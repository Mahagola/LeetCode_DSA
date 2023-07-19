// https://leetcode.com/problems/maximum-subarray
// Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0;
        int maxSum=nums[0];
        for(int i:nums){
            curr_sum=max(curr_sum, 0); //reset to zero if it becomes negative
            curr_sum+=i;
            maxSum=max(maxSum, curr_sum);
        }
        return maxSum;
    }
};