// https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //function to find the maximum subarray sum in a circular array
            int n=nums.size();
            if(n==1) return nums[0]; //if the array has only one element 
            int total_sum=accumulate(nums.begin(),nums.end(),0); //get the total sum of the array
            int maxsum=nums[0]; 
            int minsum=nums[0]; 
            int curx=0;
            int cury=0;
            for(int i:nums){
                curx = max(curx, 0);
                curx += i;
                maxsum = max(maxsum, curx);
                
                cury = min(cury, 0);
                cury += i;
                minsum = min(minsum, cury);
            }
            //check if all of the elements are negative
            if(total_sum==minsum) return maxsum;//return the max subarray
            return max(maxsum,total_sum-minsum);
    }
};
