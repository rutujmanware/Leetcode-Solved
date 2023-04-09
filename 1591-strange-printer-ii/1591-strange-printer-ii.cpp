class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector<int> min_row(61,1e9),max_row(61,-1),min_col(61,1e9),max_col(61,-1);
        for(int i=0;i<targetGrid.size();i++){
            for(int j=0;j<targetGrid[i].size();j++){
                min_row[targetGrid[i][j]] = min(min_row[targetGrid[i][j]],i);
                max_row[targetGrid[i][j]] = max(max_row[targetGrid[i][j]],i);
                min_col[targetGrid[i][j]] = min(min_col[targetGrid[i][j]],j);
                max_col[targetGrid[i][j]] = max(max_col[targetGrid[i][j]],j);
            }
        }
        
        vector<vector<int>> adj(61);
        vector<int> indeg(61);
        for(int colr = 1;colr<61;colr++){
            for(int i=min_row[colr];i<=max_row[colr];i++){
                for(int j=min_col[colr];j<=max_col[colr];j++){
                    if(targetGrid[i][j]!=colr){
                        adj[colr].push_back(targetGrid[i][j]);
                        indeg[targetGrid[i][j]]++;
                    }
                }
            }
        }
        int visited = 0;
        queue<int> q;
        for(int colr=1;colr<61;colr++){
            if(!indeg[colr]){
                q.push(colr);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited++;
            for(auto &child:adj[node]){
                if(!(--indeg[child])){
                    q.push(child);
                }
            }
        }
        return visited==60;
    }
};