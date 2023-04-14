class Solution {
public:
    int calc(vector<vector<int>>& adj, vector<int>& vis, int node, int idx) {
        if(vis[node]) return 0;
        vis[node] = 1;
        
        int ans = 0;
        for(auto &i: adj[node]) {
            if(i != idx)
                ans = max(ans, calc(adj, vis, i, idx));
        }
        return ans + 1;
    }
    
    int calc(int src,vector<vector<int>>& adj,int res,int &check,int &ans){
        // res++;
        for(auto &child:adj[src]){
            if(child!=check){
                ans = max(ans,calc(child,adj,res+1,check,ans));
                //variables me thoda dikkat hai
            }
        }
        return res;
    }
    void dfs(int src,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &rec,int &ans){
        vis[src] = rec[src] = true;
        for(auto &child:adj[src]){
            
            if(rec[child]){
                int temp = count(rec.begin(),rec.end(),true);
               
                ans = max(ans,temp);
            }
            if(!vis[child]){
                dfs(child,adj,vis,rec,ans);
            }
        }
        rec[src] = false;
        // return ans;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> adj(favorite.size());
        for(int i=0;i<favorite.size();i++){
            adj[favorite[i]].push_back(i);
        }
        // cout<<"[";
        // for(int i=0;i<adj.size();i++){
        //     cout<<"[";
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j];
        //         if(j!=adj[i].size()-1)
        //             cout<<",";
        //     }
        //     cout<<"]";
        //     if(i!=adj.size()-1)
        //         cout<<",";
        // }
        // cout<<"]";
        int ans = 0;
        vector<bool> rec(n),vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,adj,vis,rec,ans);
        }
        int twocyc = 0;
        int res = 1;
        int sol=1;
        int nonch = 0;
        int get = 0;
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++){
            if(!visited[i] && favorite[favorite[i]] == i){
                get += calc(adj, visited, i, favorite[i]);
                get += calc(adj, visited, favorite[i], i);
                // cout<<i<<" "<<favorite[i]<<" "<<get<<endl;
                // calc(favorite[i],adj,res,i,sol);
                // int t = sol;
                // sol = 1;
                // calc(i,adj,res,favorite[i],sol);
                // int y = sol;
                // // cout<<t<<" "<<y<<endl;
                // get += (t+y);
                // // break;
            }
        }
        twocyc = max(twocyc, get);
        // cout<<twocyc<<" "<<ans<<endl;
        return max(twocyc,ans);
    }
};