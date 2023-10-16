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

// int sum(struct Node *p)
// {
//     int s = 0;
//     while(p!=NULL)
//     {
//         s+=p->data;
//         p=p->next;
//     }
//     return s;
// }

int Rsum(struct Node *p)
{
    if(p==NULL)
        return 0;

    else
        return Rsum(p->next)+p->data;
}


int main()
{
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);
    RDisplay(first);
    cout<<"Sum is "<<Rsum(first)<<endl;

    return 0;
}
