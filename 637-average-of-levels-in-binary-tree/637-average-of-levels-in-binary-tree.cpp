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
    vector<double> avg;
    void levels(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            double size = q.size();
            double val = 0.0;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                val+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
            avg.push_back(val/size);
            
            
            
        }
        
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        levels(root);
        return avg;
    }
};