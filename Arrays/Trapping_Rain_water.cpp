/*
one solution can be to make 2 arrays left and right
left array stores the maximum height present to the left of every index
similarly right array stores the maximum height present to the right of
every index
than for every index we check how much water is accumulated by subtracting
minimum of left/right and height of that index and sum that into our 
final result
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n],right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};

/*
Above solution can be optimised 
instead of taking array of left and right we can use 2 pointer approach
if left side height is smaller than the right side
we check if height of left/right is greater than left/right max height,
if greater we than make that index height to max height 
if less we add the left/right max - current height
and adds it to the final solution.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=0;
        int i=0,j=n-1,left_max=0,right_max=0;
        while(i<j){
            if(height[i]<height[j]){
                if(height[i]>left_max) left_max = height[i];
                else res+=left_max-height[i];
                i++;
            } else {
                if(height[j]>right_max) right_max = height[j];
                else res+=right_max-height[j];
                j--;
            }
        }
        return res;
    }
};
