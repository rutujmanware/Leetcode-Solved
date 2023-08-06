class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256]={0};
        int n = s.size();
        int i=0,j=0;
       
        int ans = 0;
      
        while(j<n){
            arr[s[j]]++;
        
            while(arr[s[j]]>1){
                arr[s[i]]--;
                i++;
             
            }
            ans = max(ans,j-i+1);
            j++;
            
        }
       
        return ans;
    
    }
};