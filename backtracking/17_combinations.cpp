// https://leetcode.com/problems/combinations/
class Solution {
public:
    void func(int init, int k, int n, vector<vector<int>>&ans, vector<int>&v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=init;i<=n;i++){
            v.push_back(i);
            func(i+1,k,n,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        func(1,k,n,ans,v);
        return ans;
    }
};
