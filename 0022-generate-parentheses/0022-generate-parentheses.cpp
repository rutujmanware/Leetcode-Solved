class Solution {
public:
   
    void helper(int openP,int closeP,int &n,vector<string> &ans,string temp){
        if(openP == n && closeP == n){
            ans.push_back(temp);
            return;
        }
        
        if(openP<n){
            helper(openP + 1 ,closeP, n, ans, temp+'(');
        }
        if(openP>closeP){
            helper(openP,closeP+1,n,ans,temp+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        helper(0,0,n,ans,"");
        return ans;
        
        
    }
};