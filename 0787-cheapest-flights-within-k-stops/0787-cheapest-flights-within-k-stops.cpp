class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
        }
        
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});
        
        vector<int> stops(n,INT_MAX);
        
        while(!pq.empty()){
            auto temp = pq.top();
            int price=temp[0],dest=temp[1],stop=temp[2];
            
            pq.pop();
            if(stop>k+1 || stop>stops[dest]){
                continue;
            }
            stops[dest] = stop;
            if(dest==dst){
                return price;
            }
            for(auto &a:adj[dest]){
                pq.push({price+a.second,a.first,stop+1});
            }
            
        }
        return -1;
        
    }
};