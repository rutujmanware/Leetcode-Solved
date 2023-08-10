class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="";
        for(int i=0;i<=s.size();i++){
            if(!temp.empty() && (s[i]==' '|| i==s.size())){
                st.push(temp);
                temp="";
            }
            if(s[i]!=' ')
                temp+=s[i];
        }
        string ans="";
        ans+=st.top();
        st.pop();
        while(!st.empty()){
            ans+=" "+st.top();
            st.pop();
        }
        return ans;
    }
};