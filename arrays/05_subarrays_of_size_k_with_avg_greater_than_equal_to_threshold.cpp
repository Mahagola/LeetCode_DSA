// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int n=arr.size();
        int sum=0;
        int count=0;
        for(;i<k;i++){ //handling 1st window of size k
            sum+=arr[i];
        }
        if(sum/k>=threshold)count++;
        int j=0;
        while(i<n){ //handling rest of the windows
            sum-=arr[j];
            j++;
            sum+=arr[i];
            i++;
            if(sum/k>=threshold)count++;
        }
        return count;
    }
};