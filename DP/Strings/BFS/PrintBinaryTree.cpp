// Print Binary Tree/**
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
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    void fill(vector<vector<string>>& ans, TreeNode* root, int row, int low,
              int high) {
        if (!root)
            return;

        int mid = low + (high - low) / 2;
        ans[row][mid] = to_string(root->val);
        fill(ans, root->left, row + 1, low, mid - 1);
        fill(ans, root->right, row + 1, mid + 1, high);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int ht = height(root);
        int m = ht;
        int n = pow(2, m) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        fill(ans, root, 0, 0, n - 1);
        return ans;
    }
};