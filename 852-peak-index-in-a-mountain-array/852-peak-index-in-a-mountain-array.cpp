class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int right = arr.size()-1;
        int left = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(mid!=0 && mid!=arr.size()-1&&arr[mid]> arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(mid!=0 && mid!=arr.size()-1 && arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])             {
        
                left = mid + 1;
               
            }
            else if(mid==0 && arr[mid]<arr[mid+1]){
                left = mid+1;
            }
            
            else if(mid==arr.size()-1 && arr[mid]<arr[mid-1]){
                right = mid-1;
               
            }
            else{
                right = mid-1;
            }
            
        }
        return 0;
    }
};