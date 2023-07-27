class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        vector<int> left(n);
        vector<int> right(n);
        // if(h.size() ==1){
        //     return h[0];
        // }
        
        for(int i = 0; i < n; i++){
           
                while(!s.empty() && h[s.top()] >= h[i]){
                    s.pop();
                }
                if(s.empty()){
                    left[i] = -1;
                }
                else{
                    left[i] = s.top();
                }
            
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1; i >= 0; i--){
           
                while(!s.empty() && h[s.top()] >= h[i]){
                    s.pop();
                }
                if(s.empty()){
                    right[i] = n-1;
                }
                else{
                    right[i] = s.top()-1;
                }
            
            s.push(i);
        }
        int area = 0;
        // for(int i = 0;i<n;i++){
        //     cout<<left[i]<<" "<<right[i]<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            area = max((right[i] - left[i]) * h[i],area);
        }
       
        return area;
    }
};