class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = n;
        for(int i=0;i<x;i++){
            n ^= nums[i];
            n ^= i;
            // cout<<n<<endl;
        }
        return n;
    }
};