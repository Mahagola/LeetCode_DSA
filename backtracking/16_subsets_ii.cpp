// https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void func(int i,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
        if(i>=nums.size()){
            ans.push_back(curr);
            return;
        }
        //to include nums[i]
        curr.push_back(nums[i]);
        func(i+1,ans,curr,nums);
        curr.pop_back();

        //not to include nums[i]
        while(i+1<nums.size()&&nums[i]==nums[i+1])i++; 
        func(i+1,ans,curr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr={};
        func(0,ans,curr,nums);
        return ans;
    }
};