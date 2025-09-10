/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>res;

        dfsserialize(res,root);

        return join(res,",");
        
    }

    void dfsserialize(vector<string>&res,TreeNode*node)
    {
        if(!node) 
        {
            res.push_back("N");
            return;
        }

        res.push_back(to_string(node->val));
        dfsserialize(res,node->left);
        dfsserialize(res,node->right);

    }

    string join(const vector<string>& v, const string& delim) {
    ostringstream s;
    for (size_t idx = 0; idx < v.size(); ++idx) {
        if (idx) s << delim;     // add delimiter before non-first elements
        s << v[idx];
    }
    return s.str();              // safe even when v is empty
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>vals=split(data,',');
        int i=0;
       return dfsdeserialize(i,vals);


        
    }

    TreeNode*dfsdeserialize(int&i, vector<string>&vals)
    {
        if(vals[i]=="N")
        {
            i++;
            return NULL;
        }

        TreeNode*root=new TreeNode(stoi(vals[i]));
        i++;
        root->left=dfsdeserialize(i,vals);
        root->right=dfsdeserialize(i,vals);

        return root;
    }

    vector<string> split(const string &s, char delim) {
        vector<string>elems;
        stringstream ss(s);

        string item;
        while(getline(ss,item,delim))
        {
            elems.push_back(item);
        }
        return elems;
    }

    



    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));