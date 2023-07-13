class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e7;
        int mindiff = 1e7;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int l = i + 1;
            int r = n - 1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                
                // cout<<abs(target-sum)<<" "<<sum<<endl;
                if(abs(target-sum)<mindiff){
                    ans = sum;
                    mindiff = abs(target-sum);
                    
                }
                
                if(sum>target){
                    r--;
                }
                else{
                    l++;
                }
            }
            
        }
        return ans;
    }
};