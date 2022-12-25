class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int sum=0;
        for(auto x:tasks){
            m[x]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:m) pq.push(make_pair(x.second,x.first));
        while(!pq.empty()){
            int t = 0;
            vector<pair<int,char>> v;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    v.push_back(pq.top());
                    pq.pop();
                    t++;
                }
            }
                for(auto x:v) if(--x.first) pq.push(x);
                sum+= !pq.empty()?n+1:t;
            
        }
        return sum;
    }
};
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char, int> m;
//         for(auto x: tasks) m[x]++;
//         priority_queue<pair<int, char>>pq;
//         for(auto x: m) pq.push(make_pair(x.second, x.first));
//         int sum = 0;
//         while(!pq.empty()){
//             int time = 0;
//             vector<pair<int, char>>v;
//             for(int i = 0; i < n + 1; i++){
//                 if(!pq.empty()){
//                     v.push_back(pq.top());
//                     pq.pop();
//                     time++;
//                 }
//             }
//             for(auto x: v) if(--x.first) pq.push(x);
//             sum += !pq.empty() ? n + 1 : time;
//         }
//         return sum;
//     }
// };