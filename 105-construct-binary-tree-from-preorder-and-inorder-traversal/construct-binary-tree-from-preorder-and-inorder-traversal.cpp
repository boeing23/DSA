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

    int pre=0;
    int ind=0;
    TreeNode*dfs(vector<int>&preorder,vector<int>& inorder, int limit)
    {
        if(pre>=preorder.size()) return NULL;
        if(inorder[ind]==limit) 
        {
            ind++;
            return nullptr;
        }

        TreeNode*root=new TreeNode(preorder[pre++]);
        root->left=dfs(preorder,inorder,root->val);
        root->right=dfs(preorder,inorder,limit);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,INT_MAX);
        
    }
};