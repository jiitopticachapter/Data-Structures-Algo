/*

//Approach
To solve this question, we do a linear traversal on the array and keep track of ones' count by increasing count variable value by one when a '1' is encountered
and store the value of count in the res variable (used to store count of max consecutive ones so far).
And when a '0' is encountered, we  and reset the count variable to zero again. 
At last, we return res as the whole array gets traversed.

//Complexities
Time Complexity:- O(N)  (where N is length of array) Complexity is such that due to single traversal of array.
Space Complexity:- O(1) (As constant extra space is used.)

*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count=0;  //count of consecutive ones
        int res=0;  //count of max consecutive ones so far
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
              count++;
              res=max(count,res);
            }
            else
             count=0;   
        }
      
        return res;
      
    }
};
