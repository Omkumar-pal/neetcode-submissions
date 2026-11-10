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
    void dfs(TreeNode* root, vector<int> &node){
        if (!root) return;
        dfs(root->left, node);
        node.push_back(root->val);
        dfs(root->right, node);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        dfs(root,nodes);
        return nodes[k-1];
    }
};
