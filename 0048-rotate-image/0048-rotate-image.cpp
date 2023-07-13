class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
//         vector<vector<int>> ans(n,vector<int>(n,0));
//         for(int i=0,k=0;i<n;i++,k++){
//             for(int j=n-1,l=0;j>=0;j--,l++){
//                 ans[k][l] = matrix[j][i];
//             }
//         }
//         matrix = ans;
        
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
};