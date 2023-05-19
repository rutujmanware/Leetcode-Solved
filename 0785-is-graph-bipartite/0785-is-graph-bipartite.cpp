class Solution {
public:
    bool colour(int src,vector<vector<int>>& graph,int parent,vector<int> &vis,vector<int> &color){
        if(color[src]==-1){
            if(parent!=-1){
                
                if(color[parent]==-1){
                    color[src] = 1;
                }else if(color[parent] == 0){
                    color[src] = 1;
                }else{
                    color[src] = 0;
                }
            }
            else{
                color[src] = 1;
            }
        }else{
            if(color[src] == color[parent]){
                return false;
            }
        }
        if(vis[src]) return true;
        vis[src] = 1;
        for(auto &x:graph[src]){
         
                if(!colour(x,graph,src,vis,color)){
                    return false;
                }
            
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
               if( !colour(i,graph,-1,vis,color))
                   return false;
            }
        }
        return true;
        
    }
};