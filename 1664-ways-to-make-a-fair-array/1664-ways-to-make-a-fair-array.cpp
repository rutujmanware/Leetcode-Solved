class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int oddsum=0,evensum=0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if((i&1)){
                oddsum += nums[i];
            }
            else evensum += nums[i];
        }
        int suffodd=0,suffeven=0;
        int count=0;
        for(int i=n-1;i>=0;--i){
            if((i&1)){
                oddsum -= nums[i];
            }
            else {
                evensum -= nums[i];
            }
            
            if((evensum+suffeven) == (suffodd+oddsum)){
                ++count;
            }
            
            if((i&1)){
                suffeven += nums[i];
            }
            else {
                suffodd += nums[i];
            }
        }
        return count;
    }
};