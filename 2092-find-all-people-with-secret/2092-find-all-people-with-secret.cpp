class UnionFind {
    public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n){
        parent = vector<int> (n);
        rank = vector<int> (n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
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
        if(rank[x]<rank[y]){
            parent[y] = x;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
        
    }
    void reset(int x){
        parent[x] = x;
    }
    bool connected(int x,int y){
        return find(x) == find(y);
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[2]<b[2]){
            return true;
        }
        else return false;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        UnionFind u(n);
        sort(meetings.begin(),meetings.end(),comp);
        u.merge(0,firstPerson);
        vector<int> people;
        for(int i=0,m=meetings.size();i<m;){
            people.clear();
            int time = meetings[i][2];
            for(;i<m && meetings[i][2]==time;i++){
                u.merge(meetings[i][0],meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
            }
            for(auto &p:people){
                
                // cout<<p<<endl;
                if(!u.connected(0,p)) u.reset(p);
                // if(u.merge(0,p)) cout<<p<<endl;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(u.connected(0,i)) ans.push_back(i);
        }
        return ans;
    }
};