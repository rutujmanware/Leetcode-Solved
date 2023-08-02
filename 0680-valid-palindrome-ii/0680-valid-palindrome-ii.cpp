class Solution {
public:
    bool ifPallindrome(string& s,int i,int j){
        int n = s.size();
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return ifPallindrome(s,i+1,j) || ifPallindrome(s,i,j-1);
            }
        }
        return true;
    }
};