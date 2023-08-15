class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        bool flag = 0;
        if(x<0){
            flag = 1;
        }
        while(abs(x)>0){
            int temp = abs(x)%10;
            // cout<<temp<<endl;
            ans = ans*10 + temp;
            x = abs(x)/10;
        }
        if(ans < INT_MIN || ans> INT_MAX){
            return 0;
        }
        if(flag){
            return -1*ans;
        }
        return ans;
    }
};