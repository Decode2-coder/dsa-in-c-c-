#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,8,9,10,11,12};
    int sum = 0;
    int s;
    int n;
    for(int i = 0; i<11; i++)
    {
        sum = sum + arr[i];
    }
    s=(12*13)/2;
    n=s-sum;
    cout<<"missing number is "<<n;


}