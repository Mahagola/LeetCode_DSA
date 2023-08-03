https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    void permute(vector<string>&ans,unordered_map<char, string> mp,string &curr,string &digits, int ind)
    {
        if(curr.size()==digits.length()){
            ans.push_back(curr);
            return;
        }
        for(char c:mp[digits[ind]]){
            curr+=(c);
            permute(ans,mp,curr,digits, ind+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        vector<string>ans;
        string curr="";
        unordered_map<char, string>mp={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        permute(ans,mp,curr, digits, 0);
        return ans;
    }
};
