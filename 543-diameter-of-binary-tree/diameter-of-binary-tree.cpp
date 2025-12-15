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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;

         dfs(root,maxD);
         return maxD;

        
    }

    int dfs(TreeNode* root, int& maxD)
    {
        if(!root) return 0;
        int left=dfs(root->left, maxD);
        int right=dfs(root->right, maxD);

        maxD=max(maxD, left+right);

        return 1+max(left,right);
    }
};