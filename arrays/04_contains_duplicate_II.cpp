// https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int>s;
        int l=0;
        for(int r=0;r<nums.size();r++){
            // Check if the size of the current window is greater than k
            if(r-l>k){
                // Remove the leftmost element from the set and increment the left end of the window
                s.erase(nums[l]);
                l+=1;
            }
            // Check if the current element is already present in the set
            if(s.find(nums[r])!=s.end())return true;
            // Insert the current element into the set
            s.insert(nums[r]);
        }
        // No duplicate elements found within k distance
        return false;
    }
};