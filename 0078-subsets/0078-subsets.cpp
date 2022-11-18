class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> go;
        // ans.push_back(go);
        rec(0,nums,go,ans);
        return ans;
        
    }
    void rec(int ind,vector<int> &nums,vector<int> &go,vector<vector<int>> &ans){
        // if(ind==nums.size()) 
        ans.push_back(go);
        for(int i=ind;i<nums.size();i++){
            if(i==ind || nums[i]!=nums[i-1]){
                go.push_back(nums[i]);
                rec(i+1,nums,go,ans);
                go.pop_back();
            }
            
        }
    }
       
};