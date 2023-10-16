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

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rcount(p->next)+1;
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        RDisplay(p->next);
    }
}

void Insert( struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > Rcount(p))
        return;
    t = new Node;
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        for(i = 0; i<index-1; i++)
            p=p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node *t, *last;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first=last=t;
    else
    {
        last->next = t;
        last = t;
    }
        
}
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    SortedInsert(first, 55);
    RDisplay(first);
    return 0;
}
