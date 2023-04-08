class Solution {
public:
    vector<long long> dijkstra(int src, vector<vector<pair<int,long long>>> &adj,int n){
        vector<long long> ans(n,1e18);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,src});
        ans[src] = 0;
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            if(dist!=ans[node]) continue;
            for(auto &x:adj[node]){
                if(x.second+dist<ans[x.first]){
                    ans[x.first] = x.second+dist;
                    pq.push({ans[x.first],x.first});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        return ans;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,long long>>> adj(n);
        vector<vector<pair<int,long long>>> rev(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            rev[e[1]].push_back({e[0],e[2]});
        }
        
        vector<long long> dist1 = dijkstra(src1,adj,n);
        vector<long long> dist2 = dijkstra(src2,adj,n);
        vector<long long> dist3 = dijkstra(dest,rev,n);
        long long ans = 1e18;
        for(int i=0;i<n;i++){
            ans = min(ans,dist1[i]+dist2[i]+dist3[i]);
        }
        return ans==1e18?-1:ans;
    }
};