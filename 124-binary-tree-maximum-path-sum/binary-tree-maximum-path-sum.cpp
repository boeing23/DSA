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
    int maxPathSum(TreeNode* root) {

        //the idea is to check for each node, maintain a maxVal variable to keep track of the max.  two things to care of is, figure out what the return statement would return in the dfs call

        int maxVal=INT_MIN;

        dfs(root,maxVal);

        return maxVal;
        
    }

    int dfs(TreeNode*root, int &maxVal)
    {
        if(!root) return 0;

        int left=max(0,dfs(root->left,maxVal));
        int right=max(0,dfs(root->right,maxVal));

        maxVal=max(maxVal,root->val+left+right);

        return root->val+max(left,right);

    }
};