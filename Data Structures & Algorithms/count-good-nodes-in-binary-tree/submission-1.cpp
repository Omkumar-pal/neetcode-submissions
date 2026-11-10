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
    int ans = 0;

    void dfs(TreeNode* root, int max_ele){
        if (!root) return;
        if (root->val >= max_ele){
            ans++;
            max_ele = max(max_ele, root->val);
        }
        dfs(root->left, max_ele);
        dfs(root->right, max_ele);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};
