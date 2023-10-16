#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node;
    if(t == NULL)
        cout<<"Queue is full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front == NULL)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = front ->data;
        t = front;
        front=front->next;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<"\n";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    return 0;
}