class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,curr=0;
        unordered_map<int,pair<int,int>> m;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(m.count(nums[j])){
                ans = max(ans,curr);
                while(i<=m[nums[j]].second){
                    curr-=nums[i];
                    m.erase(nums[i]);
                    i++;
                }
                
        

            }
            m[nums[j]].first++;
            m[nums[j]].second=j;
            
            curr+=nums[j];
        }
        ans = max(ans,curr);
        return ans;
    }
};