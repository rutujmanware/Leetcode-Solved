class Solution {
public:
    bool isPalindrome(int x) {
        int p = x;
        long long int ans = 0;
        if(x<0){
            return false;
        }
        while(x){
            int temp = x%10;
            ans = ans*10+temp;
            x /= 10;
        }
        return(p == ans);
           
    }
};