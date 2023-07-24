// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        Arrays.fill(ans,1);
        int temp=1;
        for(int i=0;i<n;i++){
            ans[i]*=temp;
            temp*=nums[i];
        }
        temp=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=temp;
            temp*=nums[i];
        }
        return ans;
    }
}
