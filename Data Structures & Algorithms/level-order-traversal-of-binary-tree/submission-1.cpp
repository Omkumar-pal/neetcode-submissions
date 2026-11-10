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
    vector<vector<int>> levelOrder(TreeNode* root) {

                vector<vector<int>> ans;

                    if (!root) return ans;

                        queue<TreeNode*> q1, q2;
                            q1.push(root);

                                while (!q1.empty()) {
                                        vector<int> level;

                                                while (!q1.empty()) {
                                                            TreeNode* node = q1.front();
                                                                        q1.pop();

                                                                                    level.push_back(node->val);

                                                                                                if (node->left)
                                                                                                                q2.push(node->left);

                                                                                                                            if (node->right)
                                                                                                                                            q2.push(node->right);
                                                                                                                                                    }

                                                                                                                                                            ans.push_back(level);
                                                                                                                                                                    swap(q1, q2);
                                                                                                                                                                        }

                                                                                                                                                                            return ans;
                                                                                                                                                                            
        
    }
};
