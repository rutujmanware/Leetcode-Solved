class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
       sort(properties.begin(),properties.end(),comp);
        int maxi = INT_MIN;
        int res = 0;
        for(auto &val:properties){
            if(maxi>val[1]){
                res++;
            }
            else{
                maxi = val[1];
            }
        }
        return res;
    }
};