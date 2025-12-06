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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr=0;

        return dfs(root,targetSum, curr);
        
    }

    bool dfs(TreeNode*root, int targetSum, int curr)
    {
        if(!root) return false;

        curr+=root->val;

        if(!root->left && !root->right)
        {
            return curr==targetSum;

        }

        return dfs(root->left, targetSum, curr) || dfs(root->right, targetSum, curr);
    }
};