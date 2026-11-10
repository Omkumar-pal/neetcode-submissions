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
    void dfs(TreeNode* node, bool &flag, pair<int, int> rg) {
        if (!flag) return;
        if (!node) return;
        if (node->val <= rg.first ||  node->val >= rg.second){
            flag = false;
            return;
        }
        dfs(node->left, flag, {rg.first,node->val});
        dfs(node->right, flag, {node->val,rg.second});
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        pair<int, int> rg(INT_MIN,INT_MAX);
        dfs(root, flag, rg);

        return flag;
    }
};
