/*
 TCP Connect portscanner with winsock
*/

#include<stdio.h>    
#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib"); //To link the winsock library  

int main(int argc, char **argv)   
{
 WSADATA firstsock;   
 SOCKET s;
 struct hostent *host;
 int err,i, startport , endport;
 struct sockaddr_in sa; //this stores the destination address
 char hostname[100];

 strncpy((char *)&sa,"",sizeof sa);  
 sa.sin_family = AF_INET; //this line must be like this coz internet

 //Initialise winsock
 if (WSAStartup(MAKEWORD(2,0),&firstsock) != 0)  //CHECKS FOR WINSOCK VERSION 2.0
 {
  fprintf(stderr,"WSAStartup() failed"); //print formatted data specify stream and options
  exit(EXIT_FAILURE);        //or exit(1);
 } 
 
 printf("Enter hostname or ip to scan : ");
 gets(hostname);
 
 printf("Enter starting port : ");
 scanf("%d" , &startport);
 
 printf("Enter ending port : ");
 scanf("%d" , &endport);
 
 if(isdigit(hostname[0]))
 {  
  printf("Doing inet_addr...");
  sa.sin_addr.s_addr = inet_addr(hostname); //get ip into s_addr
  printf("Done\n");
 }        
 else if( (host=gethostbyname(hostname)) != 0)
 {
  printf("Doing gethostbyname()...");
  strncpy((char *)&sa.sin_addr , (char *)host->h_addr_list[0] , sizeof sa.sin_addr);
  printf("Done\n");
 }
 else
 {
    printf("Error resolving hostname");
       exit(EXIT_FAILURE);
 }

 
 //Start the portscan loop
 printf("Starting the scan loop...\n");
 for(i = startport ; i<= endport ; i++)
 {
  
  s = socket(AF_INET , SOCK_STREAM , 0); //make net a valid socket handle
  if(s < 0)  //if not a socket
  {
   perror("\nSocket creation failed");  // perror function prints an error message to stderr
   exit(EXIT_FAILURE);  //or exit(0);
  }
  
  sa.sin_port = htons(i);
  //connect to the server with that socket
  err = connect(s , (struct sockaddr *)&sa , sizeof sa);

  if(err == SOCKET_ERROR) //connection not accepted
  {
   printf("%s %-5d Winsock Error Code : %d\n" , hostname , i , WSAGetLastError());
   fflush(stdout);
  }
  else  //connection accepted
  {
   printf("%s %-5d accepted            \n" , hostname , i);
   if( shutdown( s ,SD_BOTH ) == SOCKET_ERROR )
   {
    perror("\nshutdown");// perror function prints an error message to stderr
    exit(EXIT_FAILURE);   
   }
  } 
  closesocket(s);   //closes the net socket 
 }
 
 fflush(stdout); //clears the contents of a buffer or flushes a stream
 return(0);
}