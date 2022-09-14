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
     int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
//     void getpath(TreeNode* root,map<int,int> mp,int &ans){
//         if(!root){
//             return ;
//         }
//         mp[root->val]++;
//         if(!root->left && !root->right){
//             int even=0,odd=0;
//             for(auto &val:mp){
//                 if(val.second%2==0){
//                     even++;
//                 }
//                 else{
//                     odd++;
//                 }
//             }
//             if(odd==1 || odd == 0){
//                 ans++;
//             }
            
//         }
    
//             getpath(root->left,mp,ans);
//             getpath(root->right,mp,ans);
        
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<vector<int>> list;
//         int ans = 0;
//         map<int,int> mp;
        
//         getpath(root,mp,ans);
//         return ans;
//         int ans = 0;
//         // cout<<list.size()<<endl;
//         for(int i=0;i<list.size();i++){
//             map<int,int> m;
//             bool flag = 1;
//             int cal=0;
//             for(int j=0;j<list[i].size();j++){
//                 m[list[i][j]]++;
//             }
//             for(auto &val:m){
//                 cal+=val.second;
//             }
//             if(cal%2!=0){
//                 bool odd = 0;
//                 for(auto &val:m){
//                     if(val.second%2!=0 && !odd){
//                         odd = 1;
//                     }
//                     else if(val.second%2!=0){
//                        flag = 0;
//                        cout<<"HELLO"<<endl;
//                        break;
//                    }
//                 }
//             }
//             else{
//                 for(auto &val:m){
                   
//                     if(val.second%2!=0){
//                        flag = 0;
//                        // cout<<"HELLO"<<endl;
//                        break;
//                    }
//                 }
//             }
            
//             if(flag){
//                 ans++;
//             }
//         }
//         return ans;
    // }
};