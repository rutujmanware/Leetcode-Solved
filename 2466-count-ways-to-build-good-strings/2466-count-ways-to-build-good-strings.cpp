class Solution {
public:
    int mod = 1e9+7;
    int helper(int low,int high,int zero,int one,int len,vector<int> &dp){
        if(len>high){
            return 0;
        }
        if(dp[len] != -1){
            return dp[len];
        }
        int z = 0,o =0;
        if(len+zero >= low && len+zero <= high){
            z = (helper(low,high,zero,one,len+zero,dp)+1)%mod;
        }else{
            z = (helper(low,high,zero,one,len+zero,dp)+0)%mod;
        }
        if(one+len >= low && len+one <= high){
            o = (helper(low,high,zero,one,len+one,dp) + 1)%mod;
            
        }
        else{
            o = (helper(low,high,zero,one,len+one,dp) + 0)%mod;
        }
        return dp[len] = (z+o)%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return helper(low,high,zero,one,0,dp);
    }
};