class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int i=0,j=0,k=0,l=0;
        while(true){
            if(j<m){
               for( j;j<m;j++){
                        ans.push_back(matrix[i][j]);
                }
            }
            else{
                break;
            }
            j--;
            i++;
            if(i<n){
                for(i;i<n;i++){
                    ans.push_back(matrix[i][j]);
                }
            }
            else {
                break;
            }
            i--;
            j--;
            if(j>=k){
                
            
                for(j;j>=k;j--){
                    ans.push_back(matrix[i][j]);
                }
            }
            else {
                break;
            }
            i--;
            j++;
            if(i>l){
                
            
                for(i;i>l;i--){
                    ans.push_back(matrix[i][j]);
                }
            }
                else{
                    break;
                }
            i++;
            j++;
            
            n--;
            m--;
            l++;
            k++;
            // if(n==l && m==k){
            //     break;
            // }  
        }
        return ans;
    }
};