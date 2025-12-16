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
void marker(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent)
{
    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty())
    {
        TreeNode*front=q.front();
        q.pop();

        if(front->left)
        {
            parent[front->left]=front;
            q.push(front->left);
        }
        if(front->right)
        {
            parent[front->right]=front;
            q.push(front->right);
        }
    }

    
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*>parent;

        marker(root, parent);

        queue<TreeNode*>q;
        q.push(target);

        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;

        int curr=0;

        while(!q.empty())
        {
            int size=q.size();
           
            if(curr==k) break;
            curr++;
            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                


                if(front->left && visited[front->left]!=true)
                {
                    q.push(front->left);
                    visited[front->left]=true;

                }
                if(front->right && visited[front->right]!=true)
                {
                    q.push(front->right);
                    visited[front->right]=true;

                }
                if(parent[front] && !visited[parent[front]])
                {
                    q.push(parent[front]);
                    visited[parent[front]]=true;

                }
            }
        }
        vector<int>ans;

        while(!q.empty())
        {

            ans.push_back(q.front()->val);
            q.pop();

        }


        return ans;


        

        
    }
};