#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 10000

int front = -1;
int rear = 0;

void insert(int item, int n, int arr[]) //for inserting an element in the queue
{
    if (rear == max - 1) //checks if queue is full or not
        printf("Queue Overflow \n");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    arr[rear] = item;
}

void delete (int n, int arr[]) //deletes element from the queue
{
    if (front == -1 || front > rear) //checks if queue is empty
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", arr[front]);
        front = front + 1;
    }
}
void display(int arr[]) //displays the queue
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : ");
        int f = 0;
        for (i = front; i <= rear; i++) //for traversing the queue
        {
            printf("%d ", arr[i]);
            f++;
        }
        printf("\nThe number of elements in the queue are %d\n", f);
    }
}
void main()
{
    int arr[max];
    int ch, item, n = max;
    int f = 0;
    do
    {
        printf("\nSelect an option\n");
        printf("1. Insert an item\n");
        printf("2. Delete an item\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &item); //user inputs the number to be inserted
            insert(item, n, arr);
            f++;
            break;
        case 2:
            delete (n, arr);
            f--;
            break;
        case 3:
            display(arr);
            break;
        case 4:
            printf("The end of program\n");
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (ch != 4);
}
/* SAMPLE OUTPUT
Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
1
Enter the number to be inserted
10

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
3
Queue is : 
The number of elements in the queue are 0

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Queue Underflow

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
Queue Underflow 

Select an option
PS E:\programs> gcc lit2019047.c
PS E:\programs> ./a.exe

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
1
Enter the number to be inserted
10

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
2
Element deleted from queue is : 10

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
3
Queue is : 
The number of elements in the queue are 0

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
2
Queue Underflow

Select an option
1. Insert an item
2. Delete an item
3. Display the queue
4. Exit

Enter your choice
4
The end of program*/