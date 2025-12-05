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
    int longestUnivaluePath(TreeNode* root) {

        if(!root) return 0;

        int maxPath=INT_MIN;
        dfs(root,maxPath);

        return maxPath;
        
    }

    int dfs(TreeNode*root, int &maxPath)
    {
        if(!root) return 0;

        

        int left=dfs(root->left,maxPath);
        int right=dfs(root->right,maxPath);


        int leftpath=0;
        int rightpath=0;

        if(root->left && root->val==root->left->val)
        {
            leftpath=1+left;
        }
        if(root->right && root->val == root->right->val)
        {
            rightpath=1+right;
        }
maxPath = max(maxPath, leftpath + rightpath);

        return max(leftpath,rightpath);
    }

};