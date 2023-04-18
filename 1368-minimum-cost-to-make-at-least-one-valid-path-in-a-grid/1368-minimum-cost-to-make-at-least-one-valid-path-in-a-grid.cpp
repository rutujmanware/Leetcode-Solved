class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int x,y;
        vector<int> cost(n*m,INT_MAX);
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            // auto [x,y] = node;
            pq.pop();
            x = node/m;
            y = node%m;
            // if(vis[node]){
            //     continue;
            // }
            if(x==n-1 && y==m-1){
                return wt;
            }
            
            // vis[node] = 1;
            if(y+1<m && wt+!(grid[x][y]==1) < cost[node+1]){
                pq.push({wt+!(grid[x][y]==1),node+1});
                cost[node+1] = wt+!(grid[x][y]==1);
            }
            if(y-1>=0 && wt+!(grid[x][y]==2)<cost[node-1]){
                pq.push({wt+!(grid[x][y]==2),node-1});
                cost[node-1] = wt+!(grid[x][y]==2);
            }
            if(x+1<n && wt+!(grid[x][y]==3)<cost[node+m]){
                pq.push({wt+!(grid[x][y]==3),node+m});
                cost[node+m] = wt+!(grid[x][y]==3);
            }
            if(x-1>=0 && wt+!(grid[x][y]==4)<cost[node-m]){
                pq.push({wt+!(grid[x][y]==4),node-m});
                cost[node-m] = wt+!(grid[x][y]==4);
            }
        }
        return 0;
    }
};