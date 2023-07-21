// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int r=n-1;
        int l=0;
        int ans=0;
        while(l<r){
            ans=max(ans,min(height[r],height[l])*(r-l)); //update max amount of water
            if(height[l]<height[r])l++; //keep incrementing l until it is smaller than r
            else r--; //keep decrementing r until it is smaller than l
        }
        return ans;
    }
};
