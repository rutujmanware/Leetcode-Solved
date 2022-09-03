class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> gettrust(n+1);
        vector<vector<int>> trustget(n+1);
        // vector<int> vis(n+1);
        for(int i=0;i<trust.size();i++){
            gettrust[trust[i][1]].push_back(trust[i][0]);
            trustget[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(gettrust[i].size()==n-1 && trustget[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};