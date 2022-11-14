class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> go;
        rec(0,s,go,ans);
        return ans;
    }
    void rec(int ind,string &s,vector<string> &go,vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(go);
        }
        for(int i=ind;i<s.size();i++){
            if(isPallindrome(ind,i,s)){
                go.push_back(s.substr(ind,i-ind+1));
                rec(i+1,s,go,ans);
                go.pop_back();
            }
        }
    }
    bool isPallindrome(int start,int end,string &s){
        while(start<=end)
        {
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};