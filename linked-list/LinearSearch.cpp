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

struct Node * LSearch(struct Node *p, int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p= p->next;

    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return LSearch(p->next, key);
} 
int main()
{
    struct Node *temp;
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);
    RDisplay(first);
    temp = RSearch(first, 20);
    if(temp)
        cout<<"Key is found "<<temp->data<<endl;
    else
        cout<<"Key not found"<<endl;

    return 0;
}
