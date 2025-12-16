class Node{
    public:
    int val;
    int key;

    Node*prev;
    Node*next;
public:
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        prev=nullptr;
        next=nullptr;
    }

};
class LRUCache {
    // a doubly linkedlist and 
    // and a unordered map
    int cap;
    unordered_map<int, Node*>cache;
    Node* left;
    Node*right;  

    void insert(Node* node)
    {
        Node*prv=right->prev;
        prv->next=node;
        right->prev=node;
        node->prev=prv;
        node->next=right;

    }

    void remove(Node*node)
    {
        Node*prv=node->prev;
        Node* nxt=node->next;
        prv->next=nxt;
        nxt->prev=prv;
    }

public:

    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);

        left->next=right;
        right->prev=left;
        
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
           Node* node=cache[key];
           remove(node);
           insert(node);


            return node->val;

        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())
        {
            remove(cache[key]);

        }

        Node* node=new Node(key,value);
        cache[key]=node;
        insert(node);

        if(cache.size()>cap)
        {
            Node*lru=left->next;
            remove(lru);
            cache.erase(lru->key);

        }


        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */