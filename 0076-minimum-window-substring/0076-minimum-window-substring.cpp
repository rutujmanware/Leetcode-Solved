class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int count = 0,low=0;
        int minlength = INT_MAX,minstart = 0;
        for(int high=0;high<s.size();high++){
            if(m[s[high]]>0){
                count++;
                
            }
            m[s[high]]--;
            if(count == t.size()){
                while(low < high && m[s[low]]<0){
                    m[s[low]]++;
                    low++;
                }
                if(minlength > high-low){
                    minstart = low;
                    minlength = high-minstart+1;
                }
                m[s[low++]]++;
                count--;
            }
        }
        return minlength == INT_MAX?"":s.substr(minstart,minlength);
    }
};