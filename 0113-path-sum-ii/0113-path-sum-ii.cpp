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
    bool res = false;
    void fun(TreeNode* root, int sum, int target, vector<vector<int>>& ans,
             vector<int>& temp) {
        if (root == NULL) {
            return;
        } else {
            sum += root->val;
            temp.push_back(root->val);
        }
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        fun(root->left, sum, target, ans, temp);
        fun(root->right, sum, target, ans, temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(root, 0, targetSum, ans, temp);
        return ans;
    }
};