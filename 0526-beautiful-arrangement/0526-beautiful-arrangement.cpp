class Solution {
public:
    int countArrangement(int n) {
        int ans=0;
        vector<int> v(n);
        for(int i=1;i<=n;i++){
            v[i-1] = i;
        }
        rec(0,v,ans);
        return ans;
    }
    void rec(int ind, vector<int> &v, int &ans){
        if(ind == v.size()){
            ans++;
            return;
        }
        for(int i=ind;i<v.size();i++){
            if(v[i]%(ind+1)==0 || (ind+1)%v[i]==0){
                swap(v[i],v[ind]);
                rec(ind+1,v,ans);
                swap(v[i],v[ind]);
            }
        }
    }
    
};