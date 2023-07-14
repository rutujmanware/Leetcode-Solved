class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        vector<int> v(60,0);
        for(int i=0;i<n;i++){
            int r = time[i]%60;
            if(r == 0){
                ans+=v[r];
            }
            else{
                ans+=v[60-r];
            }
            v[r]++;
        }
        return ans;
    }
};