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
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return calprof(prices,0,1,dp);
    }
};