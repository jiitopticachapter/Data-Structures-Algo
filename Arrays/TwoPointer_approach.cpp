/* 
        Approach
Using 2 pointers approach.
1. i will iterate over all elements & j will be the index off duplicates numbers.
2. We will replace j only if we find a number not similar to the j-indexed number.
3.Increase the value of the unique element every time j increased.
4.Edge case: if you return 0 while n=0, it will give a run time error.
          Time complexity: O(n).


*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<2)
            return n;
        int ans=1, j=0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
                ans++;
            }
        }
        return ans;
    }
};

