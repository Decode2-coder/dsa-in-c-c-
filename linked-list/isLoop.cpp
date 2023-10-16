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

// int count(struct Node *p)
// {
//     int sum = 0;
//     while(p)
//     {
//         sum++;
//         p = p->next;
//     }
//     return sum;
// }

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rcount(p->next)+1;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;

    }while (p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
    
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10,20,30,40,50};
    create(A,5);
    t1 = first->next->next;
    t2=first->next->next->next->next;
    t2->next = t1;

    cout<<isLoop(first)<<endl;

    return 0;
}
