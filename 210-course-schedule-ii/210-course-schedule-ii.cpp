// class Solution {
// public:
//     bool detectCycle(vector<vector<int>> &adj,vector<int> visited,int source){
//         if(visited[source] == 1) return true;
//         if(visited[source] == 2) return false;
        
//         visited[source] = 1;
//         for(auto &x:adj[source]){
//             if(detectCycle(adj,visited,x)){
//                 return true;
//             }
//         }
//         visited[source] = 2;
//         return false;
//     }
//     bool isCycle(vector<vector<int>> &adj,int n){
//         vector<int> visited(n,0);
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 if(detectCycle(adj,visited,i)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     void dfs(int s,vector<vector<int>> &adj,stack<int> &st,vector<bool> &vis){
//         // if(vis[s]) return ;
        
//         vis[s] = true;
//         for(auto &x:adj[s]){
//             if(!vis[x])
//                 dfs(x,adj,st,vis);
//         }
//         st.push(s);
        
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
//         vector<vector<int>> adj(numCourses);
//         for(int i=0;i<p.size();i++){
//             adj[p[i][1]].push_back(p[i][0]);
//         }
//         vector<int> order;
//         if(isCycle(adj,numCourses)){
//             return order;
//         }
//         stack<int> st;
//         vector<bool> vis(numCourses,false);
//         for(int i=0;i<numCourses;i++){
//             if(!vis[i]){
//                 dfs(i,adj,st,vis);
//             }
//         }

//         while(!st.empty()){
//             order.push_back(st.top());
//             st.pop();
//         }
//         return order;
        
//     }
// };
class Solution {
    //Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   //Mark current as visited
        for(int i=0;i<adj[v].size();++i)
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;
        
        visited[v]=2;   //Mark current node as processed
        return false;
    }
    
    //Cycle detection
    bool detectCycle(vector<vector<int>>& adj,int n)
    {
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        return false;
    }
    
    //Topological sort
    void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack)
    {
        visited[v] = true;
        for(int i=0;i<adj[v].size();++i)
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,mystack);
        
        mystack.push(v);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        //Make adjacecncy list
        for(int i=0;i<n;++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        //Detect CYCLE...If present then return empty array
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return ans;        
        
        //Find toposort and store it in stack
        stack<int> mystack;
        vector<bool> visited(numCourses,false);
        
        //Apply DFS and find topological sort
        for(int i=0;i<numCourses;++i)
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        
        while(!mystack.empty())
        {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        return ans;
    }
};