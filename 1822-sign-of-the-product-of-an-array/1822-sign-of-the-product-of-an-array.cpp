class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countn=0,countz=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) countn++;
            if(nums[i] == 0) return 0;
            
        }
        if(countn&1) return -1;
        else return 1;
    }
};