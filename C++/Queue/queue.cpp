/*copyright to Pratik Shrestha*/
#include <iostream>
#define SIZE 5
void enqueue(struct queue *q,int num);
void dequeue(struct queue *q);
void display(struct queue *q);
struct queue{
    int item[SIZE];
    int front,rear;
}q;
using namespace std;
int main(){
    int num,choice;
    q.front = 0;
    q.rear = -1;
    cout<<endl<<"****************************************************";
    cout<<endl<<"1.enqueue"<<endl<<"2.dequeue"<<endl<<"3.display"<<endl<<"4.exit";
    cout<<endl<<"****************************************************";
    while(1)
        {
            cout<<endl<<"Enter your choice = ";
            cin>>choice;
            switch(choice)
                {
                    case 1:
                    cout<<endl<<"enter the number = ";
                    cin>>num;
                    enqueue(&q,num);
                    break;

                    case 2:
                    dequeue(&q);
                    break;

                    case 3:
                    display(&q);
                    break;

                    case 4:
                    exit(0);
                }
        }
        return 0;
}

void enqueue(struct queue *q,int num)
    {
        if(q->rear ==SIZE-1)
            {
                cout<<endl<<"queue is full";
            }
        else    
            {
                q->rear++;
                q->item[q->rear]=num;
            }
    }

    void dequeue(struct queue *q)
        {
            int dt;
            if(q->rear<q->front)
                {
                    cout<<endl<<"queue is empty";
                }
            else    
                {
                    dt = q->item[q->front];
                    q->front++;
                    cout<<endl<<"deleted item is "<<dt;
                }
        }
        void display(struct queue *q)
            {
                int i;
                if(q->rear<q->front)
                    {
                        cout<<endl<<"queue is empty";
                    }
                else    
                    {
                        cout<<endl<<"content of a queue is :-"<<endl;
                        for(i=q->front;i<=q->rear;i++)
                            {
                                cout<<endl<<q->item[i];
                            }
                    }
            }

