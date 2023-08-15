class Solution {
public:
    int squaredSum(int x){
        int sum = 0;
        while(x>0){
            int temp = x%10;
            sum += temp*temp;
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = squaredSum(slow);
            fast = squaredSum(fast);
            fast = squaredSum(fast);
        }while(slow!=fast);
        if(slow == 1){
            return 1;
        }
        return 0;
    }
};