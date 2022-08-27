class Solution {
public:
    int maxprof(vector<int> &prices,int ind,int buy,vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-prices[ind] + maxprof(prices,ind+1,0,dp),maxprof(prices,ind+1,1,dp));
        }
        else{
            profit = max(prices[ind] + maxprof(prices,ind+1,1,dp),maxprof(prices,ind+1,0,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return maxprof(prices,0,1,dp);
    }
};