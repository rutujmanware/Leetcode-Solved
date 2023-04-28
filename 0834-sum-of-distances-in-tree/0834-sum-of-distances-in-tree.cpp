class Solution {
public:
    void dfs1(vector<int> &ans, vector<int> &child, vector<vector<int>> &adj, int src,int parent){
        for(auto &i:adj[src]){
            if(i == parent) continue;
            
            dfs1(ans,child,adj,i,src);
            child[src] += child[i];
            ans[src] += ans[i] + child[i];
        }
        
    }
     void dfs2(vector<int> &ans, vector<int> &child, vector<vector<int>> &adj, int src,int parent){
         for(auto &i:adj[src]){
             if(i==parent) continue;
             ans[i] = ans[src] - child[i] + (child.size()-child[i]);//kya gadbad hai?
             dfs2(ans,child,adj,i,src);
             
             
         }
     }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n);
        vector<int> child(n,1);
        
        dfs1(ans,child,adj,0,-1);
        // for(auto &x:ans){
        //     cout<<x<<" ";
        // }
        dfs2(ans,child,adj,0,-1);
        return ans;
       
    }
};