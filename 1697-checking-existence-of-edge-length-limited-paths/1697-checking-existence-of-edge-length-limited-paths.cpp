class UnionFind {
    public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            return parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int X,int Y){
        int x = find(X);
        int y = find(Y);
        if(x==y){
            return ;
        }
        if(rank[x]<rank[y]){
            parent[x] = y;
        }
        else if(rank[y]<rank[x]){
            parent[y] = x;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
};
class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[2]<b[2]) return true;
        else return false;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind u(n);
        sort(edgeList.begin(),edgeList.end(),cmp);
            
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        vector<bool> ans(queries.size(),false);
        int idx = 0;
        sort(queries.begin(),queries.end(),cmp);
        for(int j=0;j<queries.size();j++){
            while(idx<edgeList.size() && edgeList[idx][2]<queries[j][2]){
                u.Union(edgeList[idx][0],edgeList[idx][1]);
                idx++;
            }
            if(u.find(queries[j][0])==u.find(queries[j][1])) ans[queries[j][3]] = true;
        }
        return ans;
    }
};




// class Solution {
// public:
//     bool bfs(int src, int dest, int &limit, vector<vector<pair<int,int>>> &adj,int n){
//         // vector<int> vis(n);
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         pq.push({0,src});
//         // vis[src] = 1;
//         while(!pq.empty()){
//             auto [dist,node] = pq.top();
//             pq.pop();
//             for(auto &x:adj[node]){
//                 // if(vis[x.first]==0){
//                     // vis[x.first] = 1;
//                     if(x.second<limit){
//                         pq.push({x.second,x.first});
//                         if(x.first==dest){
//                             // cout<<"Hello"<<endl;
//                             return 1;
//                         }
//                     }
//                 // }
//             }
//         }
//         return 0;
//     }
//     vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
//         vector<bool> ans(queries.size());
//         vector<vector<pair<int,int>>> adj(n);
        
//         for(auto &x:edgeList){
//             adj[x[0]].push_back({x[1],x[2]});
//             // adj[x[1]].push_back({x[0],x[2]});
//         }
        
//         int i = 0;
//         for(auto &querry:queries){
//             ans[i] = bfs(querry[0],querry[1],querry[2],adj,n);
//             i++;
//         }
//         return ans;
//     }
// };