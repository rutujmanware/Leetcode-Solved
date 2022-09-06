class UnionFind {
    vector<int> parent;
    vector<int> rank;
    public:
    int count;
        UnionFind(int x){
            parent = vector<int> (x);
            rank = vector<int> (x,1);
            for(int i=0;i<x;i++){
                parent[i] = i;
            }
            count = x;
        }
    
        int findparent(int x){
            if(parent[x]!=x){
                parent[x] = findparent(parent[x]);
            }
            return parent[x];
        }
        void unify(int x,int y){
            int rx = findparent(x);
            int ry = findparent(y);
            if(rx==ry) return;
            count--;
            if(rank[rx]>rank[ry]){
                parent[ry] = rx;
            }
            else if(rank[rx]<rank[ry]){
                 parent[rx] = ry;
            }
            else{
                parent[ry] = rx;
                rank[rx]++;
            }
            
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    uf.unify(i,j);
                }
            }
        }
        return uf.count;
    }
};