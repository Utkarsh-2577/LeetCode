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
    bool dfs(TreeNode* root, int sum, int target){
        if(!root->left && !root->right){
            if(sum == target) return true;
            return false;
        }

        if(root->left){
            if(dfs(root->left, sum+root->left->val, target)) return true;
        }
        if(root->right){
            if(dfs(root->right, sum+root->right->val, target)) return true;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, root->val, targetSum);
    }
};