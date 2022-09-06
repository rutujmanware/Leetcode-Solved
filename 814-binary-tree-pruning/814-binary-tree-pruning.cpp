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
    void passval(TreeNode* root,TreeNode* prev,bool &flag){
        if(!root) return ;
        
        passval(root->left,root,flag);
        passval(root->right,root,flag);
        if(root->val==0 && !root->left && !root->right){
            if(prev){
                if(prev->left==root){
                    prev->left = NULL;
                }
                else{
                    prev->right = NULL;
                }
            }
            else{
                flag = 0;
            }
        }
       
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = 1;
        passval(root,NULL,flag);
        if(flag == 0){
            return NULL;
        }
        return root;
    }
};