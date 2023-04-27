class UnionFind{
  public:
    vector<int> parent,rank;
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int> (n,0);
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
    void merge(int X,int Y){
        int x = find(X);
        int y = find(Y);
        if(x==y) return ;
        if(rank[x]>rank[y]){
            parent[y] = x;
        }
        else if(rank[x]<rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
    
    bool connected(int x,int y){
        return find(x) == find(y);
    }
    void reset(int n){
        parent[n] = n;
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind u(n);
        vector<bool> ans(requests.size(),false);
        int t = 0;
        for(auto &r:requests){
            bool v = true;
            int x = u.find(r[0]);
            int y = u.find(r[1]);
            for(auto &res: restrictions){
                int i = u.find(res[0]);
                int j = u.find(res[1]);
                if((i==x && j == y) || (i==y && j == x)){
                    v=false;
                    break;
                }
                
            }
            if(v){
                    u.merge(x,y);
                    ans[t] = true;
                }
                t++;
            
        }
        return ans;
    }
};