class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int left = 0,right = n-1;
        int area = 0;
        while(left<right){
            int ta = min(height[left],height[right])*(right-left);
            int hl = height[left],hr=height[right];
            (hl<hr)?left++:right--;
            // if(hl<hr){
            //     while( left<n && hl>=height[left]){
            //         left++;
            //     }
            // }
            // else{
            //     while(right>=0 && hr>=height[right]){
            //         right--;
            //     }
            // }
            area = max(ta,area);
        }
        return area;
    }
};