class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> go;
        int sum=0;
        rec(0,candidates,go,target,ans,sum);
        return ans;
    }
    void rec(int ind,vector<int> &cand,vector<int> &go,int &target,vector<vector<int>> &ans,int sum){
        if(sum==target){
            ans.push_back(go);
        }
        for(int i=ind;i<cand.size();i++){
            if(sum>target){
                break;
            }
            if(i  > ind && cand[i] == cand[i-1])
                continue;
            sum+=cand[i];
            go.push_back(cand[i]);
            rec(i+1,cand,go,target,ans,sum);
            go.pop_back();
            
            sum-=cand[i];
        }
    }
};