class Solution {
public:
    int calprof(vector<int> &prices,int &fee,int ind,int buy,vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + calprof(prices,fee,ind+1,0,dp),calprof(prices,fee,ind+1,1,dp));
        }
        else{
            profit = max(prices[ind]-fee + calprof(prices,fee,ind+1,1,dp),calprof(prices,fee,ind+1,0,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return calprof(prices,fee,0,1,dp);
    }
};