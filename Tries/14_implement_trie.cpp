// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    class newNode{
    public:
        bool isend;
        unordered_map<char,newNode*>mp;
        newNode() : isend(false) {}
    };

    Trie(){
        root=new newNode;
    }
    
    void insert(string word) {
        newNode*curr=root;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end()){
                curr->mp[c]=new newNode;
            }
            curr=curr->mp[c];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
        newNode*curr=root;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end()){
                return false;
            }
            curr=curr->mp[c];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        newNode*curr=root;
        for(char c:prefix){
            if(curr->mp.find(c)==curr->mp.end()){
                return false;
            }
            curr=curr->mp[c];
        }
        return true;
    }
private: 
    newNode*root;
};