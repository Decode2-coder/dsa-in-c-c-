#include<stdio.h>
#include<stdlib.h>

int main(){
    int[] arr = {1,3,5,6};
    int target=5;
    int i;
    for(i=0;i<4;i++){
        if(target==arr[i])
            return i;
    }
}