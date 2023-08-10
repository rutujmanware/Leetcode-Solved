class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char sign = '+';
        for(int i=0;i<n;i++){
            if(s[i] >= '0' && s[i]<= '9'){
                int val = 0;
                while(i<n && s[i] >= '0' && s[i]<= '9'){
                    val = val * 10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(sign == '+'){
                    st.push(val);
                }
                else if(sign == '-'){
                    st.push((-1)*val);
                }
                else if(sign == '*'){
                    int a = st.top();
                    st.pop();
                    st.push(a * val);
                }
                else if(sign == '/'){
                    int a = st.top();
                    st.pop();
                    st.push(a/val);
                }
            }
            else if(s[i] != ' '){
                sign = s[i];
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};