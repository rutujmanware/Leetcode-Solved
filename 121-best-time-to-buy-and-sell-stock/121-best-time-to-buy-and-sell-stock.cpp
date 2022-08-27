class Solution {
public:
    int calprof(vector<int> &prices, int i,int k,vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int prof = 0;
        if(k==1){
            prof = max(-prices[i] + calprof(prices,i+1,0,dp),calprof(prices,i+1,1,dp));
        }
        else{
            prof = max(prices[i],calprof(prices,i+1,0,dp));
        }
        return dp[i][k] = prof;
        
        
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return calprof(prices,0,1,dp);
        for(int i = prices.size()-1;i>=0;i--){
            for(int k=0;k<=1;k++){
                int prof = 0;
                if(k==1){
                    dp[i][k] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][k] = max(prices[i],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};