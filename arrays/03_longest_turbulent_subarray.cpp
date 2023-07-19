// https://leetcode.com/problems/longest-turbulent-subarray/description/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l=0;
        int r=1;
        int n=arr.size();
        int maxi=1; 
        if(n==1)return n; //if only one element is there return it
        while(r<arr.size()){
            if(arr[l]==arr[r]){ // if l and r are equal
                l++;
                r++;
                continue;
            }
            while(r+1<n&&isTurbo(arr,r)){ //if the element is turbulent and (r+1) is within range
                r++;
            }
            maxi=max(maxi,r-l+1); //update the window size by taking the max of it
            l=r; // l will shift to r
            r=l+1; // r will be incremented by 1
        }
        return maxi;
    }
    bool isTurbo(vector<int>& arr, int k) { //check if the k is turbulent or not
        if(arr[k]<arr[k+1]&&arr[k]<arr[k-1]||arr[k]>arr[k+1]&&arr[k]>arr[k-1]) return true;
        return false;
    }
};
