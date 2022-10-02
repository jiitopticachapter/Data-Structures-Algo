/*
Kadane's Algorithm is an iterative dynamic programming algorithm.
It calculates the maximum sum subarray ending at a particular position by 
using the maximum sum subarray ending at the previous position.......


This program calculates maximum subarray sum using kadane's algorithm.
*/

#include<bits/stdc++.h> //Includes all standard libraries
using namespace std;

int Maximum_SubArray_Sum(int arr[],int n) //Function that does the work
{
    int Curr_Max=0; //will store maximum till each current index
    int Max=INT_MIN; //will store final maximum value
    for(int i=0;i<n;i++)
    {
        Curr_Max=Curr_Max+arr[i];
        if(Max<Curr_Max)
        {
            Max=Curr_Max;
        }
        if(Curr_Max<0)
        {
            Curr_Max=0;
        }
    }
    return Max;
}

int main() //Execution of the program starts from here
{
    int arr[]={5,1,-2,4,-3,-3,-4,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Maximum_SubArray_Sum(arr,n);
    return 0;
}