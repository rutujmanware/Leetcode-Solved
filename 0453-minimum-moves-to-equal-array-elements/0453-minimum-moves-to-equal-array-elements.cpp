class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = *min_element(nums.begin(),nums.end());
        
        int a = 0;
        for(int i=0;i<nums.size();i++){
            a += nums[i] - n;
        }
        return a;
    }
};