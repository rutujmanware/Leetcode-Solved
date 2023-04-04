class Solution {
public:
    int partitionString(string s) {
        map<char,int> m;
        int count=1;
        for(auto &S:s){
            if(m.count(S)){
                count++;
                m.clear();
            }
            m[S] = 1;
            
        }
        return count;
    }
};