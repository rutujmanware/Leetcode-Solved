class Solution {
public:
    int bfs(vector<vector<int>> &adj,int src){
        // vector<int> vis(n);
        queue<int> q;
        q.push(src);
        vector<int> vis(adj.size(),0);
        int count = 1;
        vis[src]=1;
        while(!q.empty()){
            // int size = q.size();
            
            int node = q.front();
            q.pop();
            // vis[node] = 1;
            for(auto &x:adj[node]){
                if(vis[x]==1){
                    continue;
                }
                q.push(x);
                count++;
                vis[x]=1;
                
            }
            
        }
        return count;
    }
    bool explode(int x1,int y1,int r1,int x2,int y2,int r2){
        float x = pow(x1-x2,2);
        float y = pow(y1-y2,2);
        float dist = sqrt(x+y);
        if(dist<=r1){
            return true;
        }
        return false;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(explode(bombs[i][0],bombs[i][1],bombs[i][2],bombs[j][0],bombs[j][1],bombs[j][2])){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 1;
       for(int i=0;i<bombs.size();i++){
           ans = max(ans,bfs(adj,i));
       }
        return ans;
    }
};