/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
   
    int widthOfBinaryTree(TreeNode* root) {
            
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
           
            int size=q.size();
            int mini=q.front().second;
            int first,last;
            
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                long long int counter=q.front().second-mini;
                q.pop();
               if(i==0){
                first=counter;
               }
                if(i==size-1){
                    last=counter;
                }
                if(curr->left){

                        q.push({curr->left,counter*2+1});
                }
                if(curr->right){
                    
                    q.push({curr->right,counter*2+2});
                }
                
    
            }
            ans=max(ans,last-first+1);
            
            
        }
        return ans;
      
    }
};