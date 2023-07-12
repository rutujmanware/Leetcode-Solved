class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0, count = 0;
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            sum += nums[i];
            prefix[i] = sum;
        }
        
        unordered_map<int,int> m;
        m[0] = 1;
        
        for(int i=0;i<n;i++){
            if(m.count(prefix[i] - k)){
                count += m[prefix[i]-k];
                
            }
            m[prefix[i]]++;
        }
        return count;
        
        
    }
};