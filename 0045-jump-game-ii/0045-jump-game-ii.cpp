class Solution {
public:
//     int help(int ind, vector<int> &nums, vector<int> &dp){
//        if(ind >= nums.size()-1){
//            return 0;
//        }
//         int ans = INT_MAX-1;
//         if(dp[ind] != -1){
//             return dp[ind];
//         }
        
//         for(int i=1;i<=nums[ind];i++){
            
//             int jump = help(ind+i,nums,dp) + 1;
//             ans = min(ans,jump);
            
//         }
//         return dp[ind] = ans;
//     }
    int jump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // int ans = help(0,nums,dp);
        // return ans;  
        int farthest = 0,current = 0,jumps=0;
        
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest,nums[i]+i);
            if(current == i){
                current = farthest;
                jumps++;
            }
            
        }
        return jumps;
        
    }
};