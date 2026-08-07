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
    int maxDia = INT_MIN;
    int checkHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);
        maxDia = max(maxDia, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        checkHeight(root);
        return maxDia;
    }
};