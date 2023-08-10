class Solution {
public:
    string reverseWords(string s) {
        // stack<string> st;
        // string temp="";
        // for(int i=0;i<=s.size();i++){
        //     if(!temp.empty() && (s[i]==' '|| i==s.size())){
        //         st.push(temp);
        //         temp="";
        //     }
        //     if(s[i]!=' ')
        //         temp+=s[i];
        // }
        // string ans="";
        // ans+=st.top();
        // st.pop();
        // while(!st.empty()){
        //     ans+=" "+st.top();
        //     st.pop();
        // }
        // return ans;
        stringstream str(s);
        vector<string> v;
        string word;
        while(str >> word){
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        string res="";
        for(int i=0;i<v.size();i++){
            res+=" "+v[i];
        }
        res.erase(0,1);
        return res;
    }
};