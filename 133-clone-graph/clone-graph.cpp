/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    

public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*>oldtonew;

        
        return dfs(node,oldtonew);


        

        
    }

    Node* dfs(Node*node,map<Node*,Node*>&oldtonew)
    {
        if(oldtonew.count(node)) return oldtonew[node];
        if(node==nullptr) return nullptr;

        Node*copy=new Node(node->val);

        oldtonew[node]=copy;

        for(Node* nei: node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei,oldtonew));
        }


        return copy;








    }
};