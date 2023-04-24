class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // sort(stones.begin(),stones.end());
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int ans = abs(f-s);
            if(ans){
                pq.push(ans);
            }
        }
        
        return pq.size()==0?0:pq.top();
        
    }
};