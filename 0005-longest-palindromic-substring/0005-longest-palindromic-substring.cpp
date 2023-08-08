class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int maxi = 0;
        for(int i=0;i<s.size();i++){
            int l = i,r = i;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                if((r-l+1)>maxi){
                    maxi = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            
            l=i,r=l+1;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                if((r-l+1)>maxi){
                    maxi = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            
        }
        return ans;
        
    }
};
