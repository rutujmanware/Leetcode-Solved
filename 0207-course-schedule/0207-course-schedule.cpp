class Solution {
public:
    bool dfs(int source,vector<int> vis,vector<vector<int>> &adj){
        if(vis[source]==1){
            return false;
        }
        if(adj[source].size()==0){
            return true;
        }
        vis[source] = 1;
        for(auto &x:adj[source]){
            if(!dfs(x,vis,adj)){
                return false;
            }
            
        }
        vis[source] = 0;
        adj[source].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses);
        // vector<int> dfsvis(numCourses);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0)
                if(!dfs(i,vis,adj)){
                    return false;
                }
        }
        return true;
    }
};