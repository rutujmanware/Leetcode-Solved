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
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        // return calprof(prices,fee,0,1,dp);
        vector<int> forw(2,0),curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy = 0;buy <= 1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + forw[0],forw[1]);
                }
                else{
                    profit = max(prices[ind]-fee + forw[1],forw[0]);
                }
                curr[buy] = profit;
            }
            forw = curr;
        }
        return curr[1];
    }
};