class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // vector<vector<int>> adj(n);
        vector<int> degree(n);
        unsigned long long int ans = 0;
        unsigned long long int c=1;
        for(auto &x:roads){
            // adj[x[0]].push_back(x[1]);
            // adj[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        // for(auto &x:degree){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // return 1LL;
        sort(degree.begin(),degree.end());
        for(auto &x:degree){
            ans += x*(c++);
            // c++;
        }
        return ans;
    }
};