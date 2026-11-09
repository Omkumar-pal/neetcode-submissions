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
    int max_dia = INT_MIN;

    int solve(TreeNode* node){
        if (!node) return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        max_dia = max(left + right, max_dia);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       solve(root);
       return max_dia;
    }
};
