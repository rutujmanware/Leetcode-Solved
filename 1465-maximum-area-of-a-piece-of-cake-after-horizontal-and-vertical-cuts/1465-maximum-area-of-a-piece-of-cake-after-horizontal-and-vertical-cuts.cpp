class Solution {
public:
    int find_max_diff(vector<int> v,int l){
       
        sort(v.begin(),v.end());
        int maxdiff = v[0];
        for(int i=1;i<v.size();i++){
            maxdiff = max(maxdiff,v[i]-v[i-1]);
        }
        maxdiff = max(maxdiff,l-v.back());
        return maxdiff;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
         ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long maxh = find_max_diff(horizontalCuts,h);
        long maxw = find_max_diff(verticalCuts,w);
        return (maxh*maxw)%1000000007;
    }
};