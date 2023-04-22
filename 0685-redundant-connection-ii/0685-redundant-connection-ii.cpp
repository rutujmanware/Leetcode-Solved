class UnionFind {
  public:
    vector<int> parent,size;
    
    UnionFind(int n){
        parent = vector<int> (n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
        size = vector<int> (n+1,1);
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int X,int Y){
        int x = find(X);
        int y = find(Y);
        if(x==y){
            return true;
        }
        if(size[x] < size[y]) swap(x,y);
        
        parent[y] = x;
        size[x] += size[y];
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind u(n);
        vector<int> indeg(n+1,-1);
        int ans1=-1,ans2=-1;
        for(int i=0;i<n;i++){
            if(indeg[edges[i][1]] == -1){
                indeg[edges[i][1]] = i;
            }
            else{
                ans1 = i;
                ans2 = indeg[edges[i][1]];
                break;
            }
        }
        // cout<<ans1<<" "<<ans2;
        
        for(int i=0;i<n;i++){
            if(i == ans1) continue;
            
            if(u.merge(edges[i][0],edges[i][1])){
                if(ans1 == -1){
                return {edges[i][0],edges[i][1]};
                    
                } 
                else{ 
//                     // cout<<"Hello";
                    return {edges[ans2][0],edges[ans2][1]};
                    
                }
            }
        }
        // cout<<"Hello2";
        return {edges[ans1][0],edges[ans1][1]};
        
    }
};








// class Solution {
// public:
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<vector<int>> adj(n+1);
//         for(auto &e:edges){
//             adj[e[0]].push_back(e[1]);
//         }
//         vector<int> ans(2);
//         vector<int> visited(n+1,0);
//         queue<int> q;
//         q.push(edges[0][0]);
//         visited[edges[0][0]]=1;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             for(auto &x:adj[node]){
//                 if(!visited[x]){
//                     visited[x] = 1;
//                     q.push(x);
//                 }
//                 else{
//                     ans[0] = node;
//                     ans[1] = x;
//                     return ans;
//                 }
//             }
//         }
//         return ans;
        
        
//     }
// };