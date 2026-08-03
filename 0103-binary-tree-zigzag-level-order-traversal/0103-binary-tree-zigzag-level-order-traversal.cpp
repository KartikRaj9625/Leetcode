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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> res;
        if(root == NULL)
         return {};
        q.push(root);
        bool LtoR = 1;
        while(!q.empty()){
            int lvl_size = q.size();
            vector<int> temp(lvl_size);
            int first = 0;
            int last = lvl_size -1;
            while(lvl_size--){
                TreeNode* t = q.front();
                q.pop();
                if(LtoR == 0){
                    temp[last] = t->val;
                    last--;
                }else{
                temp[first]=t->val;
                first++;
                }
                if(t->left != NULL)
                  q.push(t->left);
                if(t->right != NULL)
                   q.push(t->right);
                 
            }
            res.push_back(temp);
            LtoR = 1 - LtoR;
        }
        return res;
        
    }
};