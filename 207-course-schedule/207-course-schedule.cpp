class Solution {
public:
    bool dfs(int source,vector<vector<int>> &v,vector<int> vis){
//         vis[source] = 1;
//         dfsvis[source] = 1;
//         for(auto &adjnode:v[source]){
//             if(!vis[adjnode]){
//                 if(dfs(adjnode,v,vis,dfsvis)){
//                     return true;
//                 }
//             }
//             else if(dfsvis[adjnode]){
//                 return true;
//             }
        
       
//     }
//          dfsvis[source] = 0;
//         return false;
        if(vis[source] == 1) return false;
        if(v[source].size()==0) return true;
        vis[source] = 1;
        for(auto &val: v[source]){
            if(!dfs(val,v,vis)){
                return false;
            }
        }
        vis[source] = 0;
        v[source].clear();
        return true;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> v(numCourses);
        for(int i=0;i<n;i++){
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
    
        vector<int> vis(numCourses);
        vector<int> dfsvis(numCourses);
        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0){
                if(!dfs(i,v,vis)){
                    return false;
                }
                
               
            }
        }
        return true;
    }
};