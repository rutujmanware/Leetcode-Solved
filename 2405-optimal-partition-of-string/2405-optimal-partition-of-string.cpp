class Solution {
public:
    int partitionString(string s) {
//         map<char,int> m;
//         int count=1;
//         for(auto &S:s){
//             if(m.count(S)){
//                 count++;
//                 m.clear();
//             }
//             m[S] = 1;
            
//         }
//         return count;
//     }
        int flag = 0,count = 1;
        for(int i=0;i<s.length();i++){
            int k = s[i] - 'a';
            if(flag&(1<<k)){
                count++;
                flag=0;    
            }
            flag = flag|(1<<k);
            
        }
        return count;
    }
};