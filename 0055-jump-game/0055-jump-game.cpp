class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
     
        int farthest = 0;
        if(n==1){
            return true;
        }
        for(int i=0;i<n;i++){
            farthest = max(farthest,nums[i] + i);
            if(farthest == i){
                return false;
            }
            else{
                if(farthest>=n-1){
                    return true;
                }
            }
        }
        return true;
    }
};