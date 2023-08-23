class Solution {
public:
    bool isPallindrome(int start,int end,string &s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void partitions(int ind,string &s,vector<string> &v,vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(v);
        }
        for(int i=ind;i<s.size();i++){
            if(isPallindrome(ind,i,s)){
                v.push_back(s.substr(ind,i-ind+1));
                partitions(i+1,s,v,ans);
                v.pop_back();
                
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        partitions(0,s,v,ans);
        return ans;
    }
};