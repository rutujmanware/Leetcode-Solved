class Solution {
public:
    int dekho(int ind,vector<int> &prices,int k,int buy,vector<vector<vector<int>>> &dp){
        if(k==0){
            return 0;
        }
        if(ind==prices.size()) return 0;
        
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + dekho(ind+1,prices,k,0,dp),dekho(ind+1,prices,k,1,dp));
        }
        else{
            profit = max(prices[ind] + dekho(ind+1,prices,k-1,1,dp), dekho(ind+1,prices,k,0,dp));
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return dekho(0,prices,k,1,dp);
    }
};