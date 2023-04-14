class Solution {
public:
    int lps(string &s,string &s1,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s1[j]) return dp[i][j] = 1+lps(s,s1,i-1,j-1,dp);
        
        return dp[i][j] = max(lps(s,s1,i-1,j,dp),lps(s,s1,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s1 = s;
        reverse(s.begin(),s.end());
        // return lps(s,s1,n-1,n-1,dp);
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1] == s1[j-1]) dp[i][j] = 1+dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return dp[n][n];
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == s1[j-1]) curr[j] = 1+prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
        
    }
};