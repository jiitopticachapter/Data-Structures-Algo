/*
Link: https://leetcode.com/problems/3sum/
Approach: Two Pointers

The basic thinking logic for this is: Fix any one number in sorted array and find the other two numbers after it. The other two numbers can be easily found using two pointers (as array is sorted) and two numbers should have sum = -1*(fixed number).

Traverse the array and fix a number at every iteration.
If number fixed is +ve, break there because we can't make it zero by searching after it.
If number is getting repeated, ignore the lower loop and continue. This is for unique triplets. We want the last instance of the fixed number, if it is repeated.
Make two pointers start and end, and initialize sum as 0.
Search between two pointers, just similiar to binary search. Sum = num[i] + num[low] + num[high].
If sum is -ve, means, we need more +ve numbers to make it 0, increament start (start++).
If sum is +ve, means, we need more -ve numbers to make it 0, decreament end (end--).
If sum is 0, that means we have found the required triplet, push it in answer vector.
Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[start] and num[end] respectively. 

*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());    // sorting the array acc. to logic
        int start,end,sum =0;
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;      // If number fixed is +ve, stop there because we can't make it zero by searching after it.
            if(i>0 && nums[i] == nums[i-1]) continue;     // If number is getting repeated, ignore the lower loop and continue.
            start = i+1;
            end = n-1;
            while(start<end) {
                sum = nums[i] + nums[start] + nums[end];
                if(sum > 0) end--;   
                else if(sum <0) start++;
                else {
                    v.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start-1])
                        start++;
                    while(start < end && nums[end] == nums[end+1])
                        end--;
                }
            }
        }
    return v;
}

int main() {
    
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    ans = threeSum(arr);

    cout<<"Output: \n";
    for(int i=0; i<ans.size(); i++){
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    
    return 0;
}

/*
Input: 
6
-1 0 1 2 -1 -4

Output: 
-1 -1 2 
-1 0 1 

*/