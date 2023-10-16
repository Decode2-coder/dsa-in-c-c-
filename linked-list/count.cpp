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


int main()
{
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);
    RDisplay(first);
    cout<<"Length is "<<Rcount(first)<<endl;

    return 0;
}
