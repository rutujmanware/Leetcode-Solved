class Solution {
public:
    long long helper(vector<vector<int>> &q,int i,vector<long long> &dp){
        if(i>=q.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        long long take =  helper(q,i+q[i][1]+1,dp) + q[i][0];
        long long notake = helper(q,i+1,dp) + 0;
        // cout<<dp[i]<<endl;
        return dp[i] = max(take,notake);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        
        return helper(questions,0,dp);
    }
};