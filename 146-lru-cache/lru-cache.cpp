class Node
{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v)
    {
        key=k;
        val=v;
        prev=nullptr;
        next=nullptr;
    }

};

class LRUCache {
    private:
    int cap;
    unordered_map<int,Node*>cache;
    Node* right;   //Most recently used node
    Node* left;     //Least Recently used Node

    void insert(Node* node)
    {
        Node* prev=right->prev;
        prev->next=node;
        node->next=right;
        node->prev=prev;

        right->prev=node;

    }

    void remove(Node*node)
    {
        Node*prev=node->prev;
        Node*next=node->next;

        prev->next=next;
        next->prev=prev;


    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);

        right->prev=left;
        left->next=right;

        
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {

        Node*node=cache[key];
        remove(node);
        insert(node);
            return node->val;
        }

        return -1;

        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
        }
        Node*newNode= new Node(key,value);
        cache[key]=newNode;

        insert(newNode);

        //it is possible that the capcity of the cache has gone above

        if(cache.size()>cap)
        {
            Node*lru=left->next;
        remove(lru);
        cache.erase(lru->key);     //let's hold on to this i am not sure how the lru->key fetches the key
        delete lru;
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */