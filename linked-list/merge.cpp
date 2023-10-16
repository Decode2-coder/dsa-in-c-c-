#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second=NULL, *third=NULL;

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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second-> data = A[0];
    second -> next = NULL;
    last = second;

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
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
}

void concat(struct Node *p, struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;

        }
        else
        {
            last ->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }


    }

    if(p) last->next = p;
    if(q) last->next = q;
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
    int B[] = {4,15,34,46};
    create(A,8);
    create2(B,4);
    RDisplay(first);
    cout<<endl;
    RDisplay(second);
    cout<<endl;
    // concat(first,second);
    
    Merge(first,second);
    RDisplay(third);
    

    return 0;
}
