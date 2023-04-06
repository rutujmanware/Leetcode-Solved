class Solution {
public:
    void dfs(int row,int col, int n, int m,vector<vector<int>>& grid){
        grid[row][col]=1;
        vector<int> rowsum = {1,-1,0,0};
        vector<int> colsum = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int r = row+rowsum[i];
            int c = col+colsum[i];
            if(r<0 || c<0 || r>=n|| c>=m){
                continue;
            }
            if(grid[r][c]==0){
                dfs(r,c,n,m,grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i*j==0 || i==n-1 || j==m-1) && grid[i][j]==0){
                    dfs(i,j,n,m,grid);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        
        return ans;
    }
};