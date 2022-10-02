/*
This program uses kadane's alogrithm as its base to solve the problem in O(n)
time complexity.
Approach is to traverse the array and keep calculating the sum till ith 
index using Curr_Max variable and if Max_Sum is smaller than Curr_Max
than make Max_Sum=Curr_Max.
*/

#include<bits/stdc++.h> //Includes all standard libraries
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int Curr_Max=0; //will store maximum till each current index
        int Max_Sum=INT_MIN; //will store final maximum value
        for(int i=0;i<nums.size();i++)
        {
            Curr_Max=Curr_Max+nums[i];
            if(Max_Sum<Curr_Max)
            {
                Max_Sum=Curr_Max;
            }
            if(nums[i]==0) //if 0 is encountered we want to start the count again
            {
                Curr_Max=0;
            }
        }
    return Max_Sum;
}
int main() //Execution of the program starts from here
{
    vector<int> arr={1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(arr);
    return 0;
}