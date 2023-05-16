// #include<bits/stdc++.h>
class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        
        if(k==0) return 1.0;
        vector<vector<double>> parentBoard(n,vector<double>(n,0.0));
        vector<vector<double>> childBoard(n,vector<double>(n,0.0));
        
        parentBoard[row][col] = 1.0;
        int cx,cy;
        
        vector<int> dirx = {2,-2,-2,2,1,-1,-1,1}, diry = {1,-1,1,-1,2,-2,2,-2};
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    double prob = parentBoard[i][j]/8.0;
                    
                    for(int l=0;l<8;l++){
                        cx = i+dirx[l];
                        cy = j+diry[l];
                        if(cx>=0 && cy>=0 && cy<n && cx<n){
                            childBoard[cx][cy] += prob;
                            // cout<<childBoard[cx][cy]<<endl;
                        }
                    }
                
                }
            }
                parentBoard = childBoard;
                fill(childBoard.begin(),childBoard.end(),vector<double>(n,0.0));
        }
        double knight = 0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                knight+=parentBoard[i][j];
            }
        }
        return knight;
        
        
    }
};