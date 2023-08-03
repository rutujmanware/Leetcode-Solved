// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = needle.size();
//         if(haystack.size()<needle.size()) return -1;
//         for(int i=0;i<=haystack.size()-n;i++){
//             string f = haystack.substr(i,n);
//             if(f==needle){
//                 return i;
//             }
            
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int strStr(string haystack, string needle) {
       int p=haystack.find(needle);
       if(p>=0)
       {
           return p;
       }
       return -1;
    }
};