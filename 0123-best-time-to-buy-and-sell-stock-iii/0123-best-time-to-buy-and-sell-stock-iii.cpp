class Solution {
public:
    int helper(int ind, vector<int>& prices, int day,int buy,vector<vector<vector<int>>>& dp){
        if(ind == prices.size() || day == 0){
            return 0;
        }
        if(dp[ind][buy][day]!=-1){
            return dp[ind][buy][day];
        }
      
        if(buy){
           return dp[ind][buy][day] = max(helper(ind+1,prices,day,!buy,dp) - prices[ind],helper(ind+1,prices,day,buy,dp));
     
        }
        else{
           return dp[ind][buy][day] = max(helper(ind+1,prices,day-1,!buy,dp) + prices[ind],helper(ind+1,prices,day,buy,dp));
           
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,prices,2,1,dp);
    }
};