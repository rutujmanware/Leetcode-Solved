class Solution {
public:
//     int helper(int i,int j,string &s,string &t, vector<vector<int>> &dp){
//         if(j==t.size()){
//             return 1;
//         }
//         if(i==s.size()){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
       
//         if(s[i]==t[j]){
//              return dp[i][j] = helper(i+1,j+1,s,t,dp) + helper(i+1,j,s,t,dp);
//         }
//        return dp[i][j] = helper(i+1,j,s,t,dp);
        
      
        
        
//     }
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(s.size()+1,vector<unsigned int>(t.size()+1,0));
        // return helper(0,0,s,t,dp);
       
        for(int i=0;i<=s.size();i++){
            
                dp[i][0] = 1;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
        
    }
};