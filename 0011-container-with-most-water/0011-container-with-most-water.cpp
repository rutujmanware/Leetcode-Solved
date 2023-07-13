class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int left = 0,right = n-1;
        int area = 0;
        while(left<right){
            int ta = min(height[left],height[right])*(right-left);
            (height[left]<height[right])? left++:right--;
            area = max(ta,area);
        }
        return area;
    }
};