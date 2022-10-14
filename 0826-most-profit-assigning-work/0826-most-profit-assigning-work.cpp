class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> v;
        int m = 0;
        for(int i=0;i<difficulty.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        unordered_map<int,int> mp;
        sort(v.begin(),v.end());
        for(int i=0;i<difficulty.size();i++){
            mp[v[i][0]]=m=max(m,v[i][1]);
        }
        int ans=0;
        sort(difficulty.begin(),difficulty.end());
        for(auto a:worker){
            int j = lower_bound(difficulty.begin(),difficulty.end(),a) - difficulty.begin();
            if(difficulty[j]>a || j==difficulty.size()){
                j--;
            }
            if(j>=0){
                ans+=mp[difficulty[j]];
            }
        }
        return ans;
    }
};