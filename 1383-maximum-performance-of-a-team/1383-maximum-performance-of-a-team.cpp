class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {efficiency[i],speed[i]};
        }
        sort(vec.rbegin(),vec.rend());
        long sum = 0, res=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &[e,s]:vec){
            pq.emplace(s);
            sum += s;
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            res = max(sum*e,res);
        }
        return res%MOD;
    }
};