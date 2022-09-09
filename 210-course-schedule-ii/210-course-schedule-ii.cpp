class Solution {
public:
    bool detectCycle(vector<vector<int>> &adj,vector<int> &visited,int source){
        if(visited[source] == 1) return true;
        if(visited[source] == 2) return false;
        
        visited[source] = 1;
        for(auto &x:adj[source]){
            if(detectCycle(adj,visited,x)){
                return true;
            }
        }
        visited[source] = 2;
        return false;
    }
    bool isCycle(vector<vector<int>> &adj,int n){
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectCycle(adj,visited,i)){
                    return true;
                }
            }
        }
        return false;
    }
    void dfs(int s,vector<vector<int>> &adj,stack<int> &st,vector<bool> &vis){
        // if(vis[s]) return ;
        
        vis[s] = true;
        for(auto &x:adj[s]){
            if(!vis[x])
                dfs(x,adj,st,vis);
        }
        st.push(s);
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> order;
        if(isCycle(adj,numCourses)){
            return order;
        }
        stack<int> st;
        vector<bool> vis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
        
    }
};
