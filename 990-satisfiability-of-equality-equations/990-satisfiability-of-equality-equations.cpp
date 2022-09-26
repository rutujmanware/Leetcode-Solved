class UnionFind{
    vector<int> parent;
    vector<int> rank;
    public:
        UnionFind(){
            parent = vector<int> (26);
            rank = vector<int> (26,0);
            for(int i=0;i<25;i++){
                parent[i]=i;
            }
        }
        
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
    void merge(int x,int y){
        int row = find(x);
        int col = find(y);
        if(row==col){
            return ;
        }
        if(rank[row]<rank[col]){
            parent[row]=col;
        }
        else if(rank[row]>rank[col]){
            parent[col]=row;
        }
        else{
            parent[row]=col;
            rank[row]++;
        }
    }
    
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for(int i=0;i<equations.size();i++){
           
                if(equations[i][1] == '='){
                    int x = int(equations[i][0])-97;
                    int y = int(equations[i][3])-97;
                    uf.merge(x,y);
                
            }
        }
        
         for(int i=0;i<equations.size();i++){
           
                if(equations[i][1] == '!'){
                    int p1 = uf.find(int(equations[i][0])-97);
                    int p2 = uf.find(int(equations[i][3])-97);
                    if(p1==p2){
                        return false;
                    }
                }
            
         }
        
        return true;
        
        
    }
};