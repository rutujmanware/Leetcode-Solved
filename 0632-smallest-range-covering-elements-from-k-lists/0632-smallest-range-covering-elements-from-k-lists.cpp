class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       vector<pair<int,int>> pq;
        int n =nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                pq.push_back({nums[i][j],i});
                
            }
        }
        sort(pq.begin(),pq.end());
        
        vector<int> ans;
        unordered_map<int,int> m;
        int k=0,j=0;
        for(int i=0;i<pq.size();i++){
            if(!m[pq[i].second]++) ++k;
            if(k==nums.size()){
                while(m[pq[j].second]>1) --m[pq[j++].second];
                if(ans.empty() || ans[1] - ans[0] > pq[i].first-pq[j].first){
                    ans = vector<int>{pq[j].first,pq[i].first};
                }
            }
        }
        return ans;
    }
};