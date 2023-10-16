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

int isSorted(struct Node *p)
{
    int x = -65536;
    while(p!=NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }

    return 1;
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    RDisplay(first);
    if(isSorted(first))
    {
        cout<<"Sorted";
    }
    else
        cout<<"Not Sorted";
    
    return 0;
}
