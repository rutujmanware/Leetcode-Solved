class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int x,y;
        vector<int> vis(n*m,0);
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            // auto [x,y] = node;
            pq.pop();
            x = node/m;
            y = node%m;
            if(vis[node]){
                continue;
            }
            if(x==n-1 && y==m-1){
                return wt;
            }
            
            vis[node] = 1;
            if(y+1<m && !vis[node+1])
                pq.push({wt+!(grid[x][y]==1),node+1});
            if(y-1>=0 && !vis[node-1])
                pq.push({wt+!(grid[x][y]==2),node-1});
            if(x+1<n && !vis[node+m])
                pq.push({wt+!(grid[x][y]==3),node+m});
            if(x-1>=0 && !vis[node-m])
                pq.push({wt+!(grid[x][y]==4),node-m});
        }
        return 0;
    }
};