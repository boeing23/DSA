/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //here i do not have a direction togo. in binary search tree atleast I had a direction

        //if i found p or q i should return root

        if(!root) return NULL;

        if(root==p || root==q)
        {
            return root;
        }
        TreeNode*l=lowestCommonAncestor(root->left,p,q);
        TreeNode*r=lowestCommonAncestor(root->right,p,q);

        if(l && r)
        {
            return root;
        }
        else
        {
            if(l) return l;
            else return r;
        }







        
    }
};