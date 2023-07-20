class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid,int &n,int &m){
        if(i<n && i>=0 && j<m && j>=0 && grid[i][j]==1){
            grid[i][j] = 0;
            return 1 + dfs(i+1,j,grid,n,m) + dfs(i-1,j,grid,n,m) + dfs(i,j+1,grid,n,m) + dfs(i,j-1,grid,n,m);
        }
        return 0;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,grid,n,m);
                   ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};