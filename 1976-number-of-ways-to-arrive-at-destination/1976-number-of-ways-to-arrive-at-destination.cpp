const long long mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long,long>>> adj(n);
        for(auto &x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
            
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
        vector<long long> path(n,0),dist(n,1e15);
        dist[0] = 0;
        path[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            for(auto &p:adj[node]){
                if(d+p.second<dist[p.first]){
                    dist[p.first] = dist[node]+p.second;
                    path[p.first] = path[node];
                    pq.push({d+p.second,p.first});
                }
                else if(d+p.second == dist[p.first]){
                    path[p.first] = (path[p.first] + path[node])%mod;
                }
              
            }
        }
        return path[n-1];
        
    }
};