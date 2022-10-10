class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size()==1){
            return 0;
        }
        if(arr.size()==2){
            if(arr[0]>arr[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
         int right = arr.size()-1;
        int left = 0;
        while(left<=right){
            if(arr[left]>arr[left+1]){
                return left;
            }
            if(arr[right]>arr[right-1]){
                return right;
            }
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