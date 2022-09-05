/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
       
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                for(auto &x:node->children){
                    if(x)q.push(x);
                }
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};