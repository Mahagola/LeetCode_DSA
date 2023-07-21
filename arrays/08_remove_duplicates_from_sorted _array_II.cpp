// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        if(n<=2)return n;
        int count=1;
        for(int r=1;r<n;r++){
            if(nums[r-1]==nums[r])count++;
            else count=1;
            if(count<=2){
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
};
