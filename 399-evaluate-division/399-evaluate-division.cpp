class Solution {
public:
    void dfs(string s,string d,double temp, unordered_map<string,int> &vis,unordered_map<string,vector<pair<string,double>>> &m,double &ans){
        if(vis.count(s)) return;
        if(s==d){
            ans = temp;
            return ;
        }
        vis[s] = 1;
        for(auto &val:m[s]){
            dfs(val.first,d,temp*val.second,vis,m,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> m;
        for(int i=0;i<equations.size();i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/(double)values[i]});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            string s = queries[i][0] , d = queries[i][1];
            unordered_map<string,int> vis;
            double temp = 1.0;
            double ans = -1.0;
            if(m.count(s))
            dfs(s,d,temp,vis,m,ans);
            
            res.push_back(ans);
        }
        return res;
    }
};