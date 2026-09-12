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
    vector<vector<int>> ans;
    bool dfs(TreeNode* root, int sum, vector<int> &v, int target){
        if(!root->left && !root->right){
            if(sum == target){
                for(auto &i : v){
                    ans.back().push_back(i);
                }
            }
            return false;
        }

        if(root->left){
            v.push_back(root->left->val);
            if(dfs(root->left, sum+root->left->val, v, target)) return true;
            v.pop_back();
        }
        if(root->right){
            v.push_back(root->right->val);
            if(dfs(root->right, sum+root->right->val, v, target)) return true;
            v.pop_back();
        }

        return false;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> v;
        v.push_back(root->val);
        if(!dfs(root, root->val, v, targetSum)) return {};
        return ans;
    }
};