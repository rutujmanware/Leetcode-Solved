class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, j = 1;
        int count = 0;
        while(j<n){
            if(nums[j]-nums[i] < k){
                j++;
                
            }
            else if(nums[j] - nums[i] > k){
                i++;
                
            }
            else if(i==j){
                j++;
            }
            else{
                count++;
                j++;
                while(j<n && nums[j-1] == nums[j]){
                    j++;
                }
                 i++;
                while(i<n && nums[i-1] == nums[i]){
                    i++;
                }
            }
        }
        return count;
    }
};