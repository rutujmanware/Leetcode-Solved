class Solution {
public:
    int cut(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        int minimumcost=1e9;
       for(int ind=i;ind<=j;ind++){
           int cutt = cuts[j+1] - cuts[i-1] + cut(i,ind-1,cuts,dp) + cut(ind+1,j,cuts,dp);
           minimumcost = min(minimumcost,cutt);
       }
        return dp[i][j] = minimumcost;
    }
    int minCost(int n, vector<int>& cuts) {
        int s = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(s+1,vector<int>(s+1,0));
        // return cut(1,s,cuts,dp);
        for(int i=s;i>=1;i--){
            for(int j=1;j<=s;j++){
                if(i>j) continue;
                 int minimumcost=1e9;
               for(int ind=i;ind<=j;ind++){
                   int cutt = cuts[j+1] - cuts[i-1] + cut(i,ind-1,cuts,dp) + cut(ind+1,j,cuts,dp);
                   minimumcost = min(minimumcost,cutt);
               }
                dp[i][j] = minimumcost;
                
            }
        }
        return dp[1][s];
        
    }
};