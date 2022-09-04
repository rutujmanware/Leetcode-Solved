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
    static bool comp(pair<int,int> p1,pair<int,int> p2){
       if(p1.first == p2.first){
           return p1.second<p2.second;
           
       }
        else{
            return p1.first<p2.first;
        }
    }
    map<int,vector<pair<int,int>>> m;
    void vertra(TreeNode* root,int row,int col){
        if(!root) return ;
        
        vertra(root->left,row+1,col-1);
        
        m[col].push_back({row,root->val});
        
        vertra(root->right,row+1,col+1);
        
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        vertra(root,0,0);
        
        
        for(auto &f:m){
            sort(m[f.first].begin(),m[f.first].end(),comp);
            vector<int> gre;
            for(auto &val:m[f.first]){
                
                cout<<f.first<<" "<<val.first<<" "<<val.second<<endl;
                gre.push_back(val.second);
            }
            v.push_back(gre);
            
        }
        
        
        return v;
    }
};