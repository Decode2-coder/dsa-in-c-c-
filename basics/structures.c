#include<stdio.h>

struct cards{
    int face;
    int shape;
    int color;
};

// face={1->ace,2->2.......J->11,Q->12,K->13}
// shape={0->club,1->spade,3->diamond, 4-> hearts}
// color={0->black, 1->red}

int main()
{
    struct cards deck[52]={{1,0,0},{2,0,0},{3,0,0}};
    printf("%d",deck[0].face);
}
