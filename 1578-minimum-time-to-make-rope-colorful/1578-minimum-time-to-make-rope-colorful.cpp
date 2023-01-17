class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0,max_num=0;
        for(int i=0;i<colors.size();i++){
            if(i>0 && colors[i]!=colors[i-1]){
                max_num = 0;
            }
            sum += min(max_num,neededTime[i]);
            max_num = max(max_num,neededTime[i]);
        }
        return sum;
    }
};