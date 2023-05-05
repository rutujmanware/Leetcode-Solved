class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int> m;
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        int j;
        int ans = 0;
        int temp=0;
        for(j=0;j<k;j++){
            if(m.count(s[j])){
                temp++;
            }
        }
        // cout<<temp;
        ans = max(ans,temp);
        j--;
        for(int i=0;j<s.size()-1;i++,j++){
            if(m.count(s[i])){
                temp--;
                // cout<<"y"<<" "<<temp<<" ";
            }
            if(m.count(s[j+1])){
                temp++;
                // cout<< "g"<<" "<<temp<<" ";
            }
            ans = max(ans,temp);
            // cout<<ans<<endl;
        }
        

        return ans;
        
    }
};