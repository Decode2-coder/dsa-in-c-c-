#include<stdio.h>
#include<stdlib.h>


struct rectangle{
    int length;
    int breadth;
};

int main(){
    // struct rectangle r = {10, 5};
    // struct rectangle *p=&r;
    // p->length=20;
    // printf("%d", r.length);
    //(*p).length=20

    struct rectangle *p;
    p=(struct rectangle *)malloc(sizeof(struct rectangle));
    p->length = 10;
    p -> breadth = 5;
    printf("%d", p->length*p->breadth);

}