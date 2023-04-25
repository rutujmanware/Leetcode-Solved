class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> vis;
    int min;
    SmallestInfiniteSet() {
        vis = vector<int> (1001,0);
        min = 0;
    }
    
    int popSmallest() {
       if(pq.size()!=0){
           int x = pq.top();
           pq.pop();
           vis[x] = 0;
           return x;
       }
        min++;
        return min;
    }
    
    void addBack(int num) {
       if(num<=min && !vis[num]){
           pq.push(num);
           vis[num] = 1;
       }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */