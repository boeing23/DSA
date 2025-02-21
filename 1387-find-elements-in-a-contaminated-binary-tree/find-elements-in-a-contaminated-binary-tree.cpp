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
class FindElements {

    private:
    unordered_set<int>vals;
public:



void recover(TreeNode* root,int value)
{
    if(!root) return;
     root->val=value;
     vals.insert(value);

    recover(root->right,value*2+2);
    recover(root->left, value*2+1);

}


    FindElements(TreeNode* root) {

   
       recover(root,0);
        

        
        
    }
    
    bool find(int target) {
        return vals.count(target) > 0;

        
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */