class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
       vector<string> v(numRows,"");
        int j = 0,dir = -1;
        for(int i=0;i<s.size();i++){
            if(j == numRows-1 || j==0) dir *= (-1);
            
            v[j] += s[i];
            if(dir==1) j++;
            else{
                j--;
            }
            
        }
        string ans="";
        for(auto &c:v){
            ans+=c;
        }
        return ans;
    }
};