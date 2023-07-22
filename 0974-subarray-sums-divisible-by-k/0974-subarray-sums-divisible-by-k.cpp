class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k,0);
        int sum = 0;
        for(auto &v:nums){
            sum += (v%k + k) %k;
            count[sum%k]++;
        }
        int res = count[0];
        for(auto &v:count){
            res += (v * (v-1))/2;
        }
        return res;
    }
};