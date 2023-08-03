// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void target_comb(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&comb,int curr_sum, int ind, int target){
        if(curr_sum>target)return;
        if(curr_sum==target){
            ans.push_back(comb);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            curr_sum+=candidates[i];
            comb.push_back(candidates[i]);
            target_comb(candidates,ans,comb,curr_sum,i,target);
            comb.pop_back();
            curr_sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        target_comb(candidates,ans,comb,0,0,target);
        return ans;
    }
};
