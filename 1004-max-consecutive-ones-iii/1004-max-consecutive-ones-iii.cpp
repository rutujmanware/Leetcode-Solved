class Solution {
public:
    int func(int mid,vector<int>& nums,int k){
        int maxzero = 0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                maxzero++;
            }
            if(j-i+1<mid){
                j++;
            }
            else{
                if(maxzero<=k) return 1;
                else{
                    if(nums[i]==0) maxzero--;
                    i++;
                    j++;
                }
            }
        }
        return 0;
    }
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size();
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(func(mid,nums,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        return ans;
        
    }
       
};