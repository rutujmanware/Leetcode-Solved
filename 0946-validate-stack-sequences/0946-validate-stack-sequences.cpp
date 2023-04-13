class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; 
        
        int j = 0; 
        
        for(auto val : pushed){
            st.push(val); // insert the values in stack
            while(st.size() > 0 && st.top() == popped[j]){ 
                st.pop(); // then pop out
                j++; // increment j
            }
        }
        return st.size() == 0; // check if stack is empty return true else false
    }
};