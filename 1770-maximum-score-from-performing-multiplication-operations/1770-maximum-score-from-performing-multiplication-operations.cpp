class Solution {
public:
    int func(vector<int>& nums, vector<int>& multipliers,int i,int ind,vector<vector<int>> &dp){
        if(ind == multipliers.size()){
            return 0;
        }
        if(i == nums.size()){
            return 0;
        }
       
        if(dp[i][ind] != INT_MIN){
            return dp[i][ind];
        }

        
        return dp[i][ind] = max((multipliers[ind]*nums[i] + func(nums,multipliers,i+1,ind+1,dp)),(multipliers[ind]*nums[(nums.size()-1) - (ind-i)] + func(nums,multipliers,i,ind+1,dp)));
        
        
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    //     int sum=0;
    //     int n = multipliers.size();
    //     for(int i=0;i<n;i++){
    //         if(multipliers[i]*nums[0]>multipliers[i]*nums[nums.size()-1]){
    //             sum += multipliers[i]*nums[0];
    //             nums.erase(nums.begin());
    //         }
    //         else{
    //             sum += multipliers[i]*nums[nums.size()-1];
    //             nums.erase(nums.begin()+nums.size()-1);
    //         }
    //     }
    //     return sum;
    vector<vector<int>> dp(multipliers.size()+1,vector<int>(multipliers.size()+1,INT_MIN));
        return func(nums,multipliers,0,0,dp);
    }
};