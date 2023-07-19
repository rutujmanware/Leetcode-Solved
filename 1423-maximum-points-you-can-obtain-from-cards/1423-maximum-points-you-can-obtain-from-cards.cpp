class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n);
        prefix[0] = cardPoints[0];
        for(int i=1;i<n;i++){
    
           prefix[i] += prefix[i-1] + cardPoints[i];
        }
        int res = 0;
        for(int i=k-1,j=n;i>=-1,j>0;i--,j--){
            int ans = 0;
            
            if(i>=0)
                ans = prefix[i];
            
            if(j<=n-1 && (n-1)-(j-1) <= k){
                ans += prefix[n-1]-prefix[j-1];
            }
            res = max(ans,res);
        
        }
        return res;
    }
};