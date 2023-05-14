class Solution {
public:
    int helper(int op,int mask,vector<int> &nums, vector<vector<int>> &gcd, vector<int> &dp){
        int n = nums.size();
        if(op>n/2) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) continue;
            for(int j=i+1;j<n;j++){
                if(mask&(1<<j)) continue;
                
                int newmask = (1<<j) | (1<<i) | mask;
                int sol = op*gcd[i][j] + helper(op+1,newmask,nums,gcd,dp);
                dp[mask] = max(dp[mask],sol);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gcd(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gcd[i][j] = __gcd(nums[i],nums[j]);
            }
        }
        vector<int> dp(1<<14,-1);
        return helper(1,0,nums,gcd,dp);
    }
};