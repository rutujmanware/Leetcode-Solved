class UnionFind{
    private:
        vector<int> rank;
    public:
        vector<int> parent;
        vector<int> size;
        UnionFind(int n){
            parent = vector<int> (n);
            rank = vector<int> (n,0);
            size.resize(n+1,1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(parent[x]!=x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
    void mergeBySize(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind u(n);
        for(auto i:edges){
            u.mergeBySize(i[0],i[1]);
        }
        long long ans = 0;
        map<long long int,long long int> m;
        for(int i=0;i<n;i++){
            if(!m[u.find(i)] || m[u.find(i)]<u.size[i])
                m[u.find(i)] = u.size[i];
        }
        
        for(auto &x:m){
            cout<<x.first<<" "<<x.second<<endl;
            ans = ans + x.second*(n-x.second);
            n=n-x.second;
        }
        
        // cout<<endl;
        
        
        return ans;
    }
};