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
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1,i;

    if(index < 1 || index > Rcount(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x = first -> data;
        first = first -> next;
        delete q;
        return x;
    }

    else
    {
        for(i = 0; i< index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;

    }


}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    Delete(first, 0);
    RDisplay(first);
    return 0;
}
