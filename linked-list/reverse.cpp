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

void Reverse1(struct Node *p)
{
    int *A,i;
    struct Node *q=p;
    A= new int;
    while(q!=NULL)
    {
        A[i]=q->data;
        q = q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rcount(p->next)+1;
}


int main()
{
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);

    Reverse3(NULL,first);
    RDisplay(first);

    return 0;
}
