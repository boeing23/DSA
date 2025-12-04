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
    bool isBalanced(TreeNode* root) {

        if(root==nullptr) return true;
     

        int left=dfs(root->left);
        int right=dfs(root->right);

        int heightDiff=abs(left-right);

        return heightDiff<=1 && isBalanced(root->left) && isBalanced(root->right);

        
    }

    int dfs(TreeNode*root)
    {
        if(root==nullptr) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);

        return 1+max(left,right);
    }
};
