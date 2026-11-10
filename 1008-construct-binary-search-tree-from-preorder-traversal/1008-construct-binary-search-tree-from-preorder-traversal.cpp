/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> in;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return fxn(preorder, 0, inorder.size() - 1);
    }
    int idx = 0;
    TreeNode* fxn(vector<int>& preorder, int low, int high) {
        if (low > high)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int id = in[node->val];
        node->left = fxn(preorder, low, id - 1);
        node->right = fxn(preorder, id + 1, high);
        return node;
    }
};