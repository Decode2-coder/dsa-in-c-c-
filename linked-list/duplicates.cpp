#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new Node;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum++;
        p = p->next;
    }
    return sum;
}

void RemoveDuplicate(struct  Node *p)
{
    struct Node *q = p->next;

    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}



int main()
{
    int A[] = {3,5,7,10,15,8,12,20,20,20};
    create(A,8);
    RemoveDuplicate(first);
    RDisplay(first);

    return 0;
}
