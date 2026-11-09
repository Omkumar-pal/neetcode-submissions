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
    bool solve(TreeNode* p, TreeNode* q, bool &flag){   
        if (!p && !q) return true;
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val){
            return false;
        }
        return solve(p->left, q->left, flag) && solve(p->right, q->right, flag);
        
    }
    void dfs(TreeNode* p, TreeNode* q, bool &flag){
        if (!p) return;
        if (p->val == q->val){
            if (solve(p, q, flag)){
                flag = true;
                return;
            }
        }
        dfs(p->left, q, flag);
        dfs(p->right, q, flag);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;
        dfs(root, subRoot, flag);
        return flag;
    }
};
