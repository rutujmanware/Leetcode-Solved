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
    void getNodes(TreeNode* root,int value,int &ans){
        if(!root) return ;
        if(value<=root->val){
            ans++;
        }
        value = max(value,root->val);
        getNodes(root->left,value,ans);
        getNodes(root->right,value,ans);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        getNodes(root,INT_MIN,res);
        return res;
    }
};