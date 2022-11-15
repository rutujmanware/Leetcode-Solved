class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> go;
        rec(1,n,go,ans,k);
        return ans;
    }
    void rec(int ind,int &n,vector<int> &go,vector<vector<int>> &ans,int &k){
        if(go.size()==k){
            ans.push_back(go);
            return;
        }
        for(int i=ind;i<=n;i++){
            go.push_back(i);
            rec(i+1,n,go,ans,k);
            go.pop_back();
            
        }
    }
};