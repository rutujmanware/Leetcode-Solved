class Solution {
public:
    
    // bool isEqual(string s,string target){
    //     if(s==target){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    int numOfPairs(vector<string>& nums, string target) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i==j) continue;
        //         string s = nums[i] + nums[j];
        //         if(isEqual(s,target)){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        
        unordered_map<string,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i].size()>=target.size()){
                continue;
            }
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto &[pre,freq]:m){
            if(pre==target.substr(0,pre.size())){
                string s = target.substr(pre.size());
                ans += (pre==s)?(freq-1)*freq:freq*m[s];
            }
        }
        return ans;
        
    }
};