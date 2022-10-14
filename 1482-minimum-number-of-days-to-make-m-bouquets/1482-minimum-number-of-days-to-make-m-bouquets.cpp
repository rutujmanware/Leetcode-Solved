class Solution {
public:
    bool func(vector<int> &bloomDay,int day,int m,int k){
        int res=0,bouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                res++;
            }else{
                res=0;
            }
            if(res==k){
                bouquet++;
                res=0;
            }
        }
        if(bouquet>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long int)k*m>bloomDay.size()){
            return -1;
        }
        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        while(left<right){
            int mid = left + (right-left)/2;
            if(func(bloomDay,mid,m,k)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};