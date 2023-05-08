class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows= mat.size();
        int col= mat[0].size();
        int ans=0;
        for(int i=0,j=0;i<rows || j<col;i++,j++){
            ans+=mat[i][j];
        }
        for(int i=0,j=col-1;j>=0;i++,j--){
            ans+=mat[i][j];
        }
        
        if(rows%2!=0){
            ans-=mat[(rows-1)/2][(col-1)/2];
        }
        return ans;
    }
};