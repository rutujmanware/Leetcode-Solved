class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> dirx = {0,0,1,-1,1,-1,1,-1};
        vector<int> diry = {1,-1,0,0,1,-1,-1,1};
        vector<vector<int>> h(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live = 0;
                for(int k=0;k<8;k++){
                    int newi = i + dirx[k];
                    int newj = j + diry[k];
                    if(newi<0 || newi>=n || newj<0 || newj>=m) continue;
                    if(board[newi][newj] == 1){
                        live++;
                    }
                }
                // cout<<live<<endl;
                if(board[i][j] == 0 && live==3){
                    h[i][j] = 1;
                }
                else if(board[i][j] == 1 && live<2){
                    h[i][j] = 0;
                }
                else if(board[i][j] == 1 && live>3){
                h[i][j] = 0;
                }
                else{
                    h[i][j] = board[i][j];
                }
            }
        }
        board = h;
    }
};