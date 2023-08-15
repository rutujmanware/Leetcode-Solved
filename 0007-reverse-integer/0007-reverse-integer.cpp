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
        if(ans < -1*pow(2,31) || ans> pow(2,31)-1){
            return 0;
        }
        if(flag){
            return -1*ans;
        }
        return ans;
    }
};