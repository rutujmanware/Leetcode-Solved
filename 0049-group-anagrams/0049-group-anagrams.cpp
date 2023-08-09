class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        // map<vector<int>,vector<string>> m;
        // for(int i=0;i<strs.size();i++){
        //     vector<int> c (26,0);
        //     for(int j=0;j<strs[i].size();j++){
        //         c[strs[i][j]-'a']++;
        //     }
        //     m[c].push_back(strs[i]); 
        // }
        // for(auto &v:m){
        //     ans.push_back(v.second);
        // }
        // return ans;
        
        map<string,vector<string>> m;
        for(int i=0;i<n;i++){
            string dup = strs[i];
            sort(dup.begin(),dup.end());
            m[dup].push_back(strs[i]);
        }
        for(auto &v:m){
            ans.push_back(v.second);
        }
        return ans;
    }
};