class Solution {
public:
    int rightsum(vector<int> &nums,int left,int right){
        int sum = 0,maxs = nums[left+1];
        for(int i=left+1;i<=right;i++){
            sum+=nums[i];
            maxs = max(sum,maxs);
        }
        return maxs;
    }
    int leftsum(vector<int> &nums,int left,int right){
        int sum = 0,maxs = nums[right];
        for(int i=right;i>=left;i--){
            sum+=nums[i];
            maxs = max(sum,maxs);
        }
        return maxs;
    }
    int divideandconquer(vector<int> &nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        int mid = left + (right-left)/2;
        int ans = max(divideandconquer(nums,left,mid),divideandconquer(nums,mid+1,right));
        
        return max(ans,leftsum(nums,left,mid) + rightsum(nums,mid,right));
    }
    int maxSubArray(vector<int> &nums) {
        int right = nums.size()-1;
        int left = 0;
        return divideandconquer(nums,left,right);
    }
};