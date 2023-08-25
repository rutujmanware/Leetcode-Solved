class Solution {
public:
    int QuickSelect(vector<int> &nums,int left,int right){
        int pivot = nums[left],l = left + 1, r = right;
        while(l<=r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l++],nums[r--]);
                
            }
            if(nums[l] >= pivot){
                l++;
            }
            if(pivot >= nums[r]){
                r--;
            }
        }
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0,right = nums.size()-1, kth;
        
        while(1){
            int idx = QuickSelect(nums,left,right);
            if(idx == k-1){
                kth = nums[idx];
                break;
            }
            else if(idx > k-1){
                right = idx - 1;
            }
            else {
                left = idx + 1;
            }
        }
        return kth;
        
    }
};