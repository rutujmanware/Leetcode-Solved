class Solution {
public:
    string decoding(int &ind, string &s){
       string ans="";
        int num=0;
        for(;ind<s.size();ind++){
            if(s[ind]>='0' && s[ind]<='9'){
                num = num*10 + s[ind]-'0';
            }
            else if(s[ind]=='['){
               string temp = decoding(++ind,s);
                while(num>0){ 
                    ans += temp;
                    num--;
                }
            }
            else if(s[ind]==']'){
                return ans;
            }
            else{
                ans+=s[ind];
            }
        }
        return ans;
    }
    string decodeString(string s) {
        // int n = s.size();
        // string ans="";
        int ind=0;
        return decoding(ind, s);
        
    }
};