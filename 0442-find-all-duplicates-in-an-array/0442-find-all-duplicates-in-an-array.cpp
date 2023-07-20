class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto &v:m){
            if(v.second==2){
                ans.push_back(v.first);
            }
        }
            return ans;
    }
};