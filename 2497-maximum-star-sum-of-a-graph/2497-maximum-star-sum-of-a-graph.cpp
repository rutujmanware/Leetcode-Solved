class Solution {
public:
    
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int temp = vals[i];
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto &x:adj[i]){
                pq.push(vals[x]);
                if(pq.size()>k){
                    pq.pop();
                }
                
            }
            while(!pq.empty()){
                if(pq.top()>0) temp+=pq.top();
                pq.pop();
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};