class Solution {
public:
    void check(int src, vector<int> &candidates, int target, vector<vector<int>> &ans,vector<int> temp){
        if(src == candidates.size()){
           if(target == 0){
               ans.push_back(temp);
           }
           return ; 
        }
        if(target > 0){
            temp.push_back(candidates[src]);
            check(src,candidates,target-candidates[src],ans,temp);
            temp.pop_back();
        }
        check(src+1,candidates,target,ans,temp);
            
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        check(0,candidates,target,ans,temp);
        return ans;
    }
};