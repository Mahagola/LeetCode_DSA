// https://leetcode.com/problems/longest-repeating-character-replacement/description/
class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char>st;
        int maxi=0;
        for(char c :s)st.insert(c);
        for(char c:st){
            int l=0; int count=0;
            for(int r=0;r<s.length();r++){ //initialze a sliding window for each unique letter
                if(s[r]==c)count++; // if the letter matches increment count
                
                while(!isValid_window(r,l,count,k)){ //increment l until window gets valid again
                    if(s[l]==c)count--; //if char matches,decrease the count 
                    l++;
                }
                maxi=max(r-l+1, maxi); //update the max length
            }
        }
        return maxi;
    }
    bool isValid_window(int r, int l, int count, int k){
        return r-l+1-count<=k;
    }
};
