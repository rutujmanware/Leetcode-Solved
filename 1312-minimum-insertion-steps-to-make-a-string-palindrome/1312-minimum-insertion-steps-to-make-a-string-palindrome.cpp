class Solution {
public:
    int mIs(int i, int j,string &s1, string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = mIs(i-1,j-1,s1,s2,dp) + 1;
        
        return dp[i][j] = max(mIs(i-1,j,s1,s2,dp),mIs(i,j-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int n = s1.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0),curr(n+1,0);
        // return n-mIs(n-1,n-1,s,s1,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == s1[j-1]) curr[j] = prev[j-1] + 1;
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return n-prev[n];
    }
};