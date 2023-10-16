#include<iostream>
using namespace std;

// int main()
// {
//     int arr[] = {6,7,8,9,11,12,15,16,17,18,19};
//     int l = 6;
//     int h = 19;
//     int n = 11;
//     int diff = l-0;
//     for(int i = 0; i<n; i++)
//     {
//         if(arr[i]-i!=diff)
//         {
//             while(diff<arr[i]-i)
//             {
//                 cout<<"\nElement is \n"<<i+diff;
//                 diff++;
//             }
//         }
//     }


// }


int main()
{
    int arr[] = {3,7,4,9,12,6,1,11,2,10};
    int l = 1;
    int h = 12;
    int n = 10;
    int H[12];
    int i;
    for(i = 0; i< h; i++)
        H[i]=0;
    for(i = 0; i<n; i++)
    {
        H[arr[i]]++;
    }
    for(i=l;i<=h;i++)
    {
        if(H[i]==0)
            cout<<i<<"\n";
    }
}