class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        rec(0,nums,ans);
        return ans;
        
    }
    void rec(int ind,vector<int> nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
                 
        }
    
        for(int i=ind;i<nums.size();i++){
            if(i==ind || nums[i]!=nums[ind]){
                swap(nums[i],nums[ind]);
                rec(ind+1,nums,ans);
            }
        }
    }
};
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> perms;
//         permute(nums, 0, perms);
//         return perms;
//     }
// private:
//     void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
//         if (i == nums.size()) {
//             perms.push_back(nums);
//         } else {
//             for (int j = i; j < nums.size(); j++) {
//                 if (j == i || nums[j] != nums[i]) {
//                     swap(nums[i], nums[j]);
//                     permute(nums, i + 1, perms);
//                 }
//             }
//         }
//     }
// };