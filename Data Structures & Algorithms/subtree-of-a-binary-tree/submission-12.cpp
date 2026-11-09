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
        // last node for recursn
        if (!p && !q) return true;

        //if any node diff for p & q
        if (!p || !q) {
            return false;
        }

        //if value don't match 
        if (p->val != q->val){
            return false;
        }

        // calculate if the node contain subroot as full tree using left and right subtree...
        return solve(p->left, q->left, flag) && solve(p->right, q->right, flag);
        
    }
    void dfs(TreeNode* p, TreeNode* q, bool &flag){
        // Traversing until end
        if (!p) return;
        // if val is same for p & q that can be a valid search space.. only.
        if (p->val == q->val){
            if (solve(p, q, flag)){
                flag = true;
                return;
            }
        }
        // continue exploration using dfs...
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
