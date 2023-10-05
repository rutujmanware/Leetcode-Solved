class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n = nums.size();
        int n1 = n/3;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto &x:m){
            if(x.second>n1){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};