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

        int res=root->val;

        dfs(res,root);
        return res;



    }

    int dfs(int &res, TreeNode*node)
    {
        if(!node) return 0;

        int left=max(dfs(res,node->left),0);
        int right=max(dfs(res,node->right),0);


        res=max(node->val+left+right,res);
        return node->val + max(left, right);
    }
};