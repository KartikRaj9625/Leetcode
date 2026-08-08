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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void fxn(TreeNode* root) {
        if (root == NULL)
            return;

        fxn(root->left);

        if (prev != NULL && root->val <= prev->val) {
            if (first == NULL)
                first = prev;
            second = root;
        }
        prev = root;

        fxn(root->right);
    }
    void recoverTree(TreeNode* root) {
        fxn(root);
        swap(first->val, second->val);
        return;
    }
};