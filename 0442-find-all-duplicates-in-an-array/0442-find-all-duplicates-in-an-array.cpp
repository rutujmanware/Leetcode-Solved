class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int,int> m;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        // }
        // for(auto &v:m){
        //     if(v.second==2){
        //         ans.push_back(v.first);
        //     }
        // }
        //     return ans;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i]) -1 ] <0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        return ans;
    }
};