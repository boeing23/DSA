class Node:
    def __init__(self,key, value):
        self.key=key
        self.value=value
        self.next=None
        self.prev=None
class LRUCache:

    def __init__(self, capacity: int):
        self.cache={}
        self.capacity=capacity
        self.left=Node(0,0)
        self.right=Node(0,0)
        self.left.next=self.right
        self.right.prev=self.left
    def _insert(self, node):
        prev=self.right.prev
        prev.next=node
        node.next=self.right
        node.prev=prev
        self.right.prev=node
    def _remove(self,node):
        prev=node.prev
        next=node.next

        prev.next=next
        next.prev=prev
        

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node=self.cache[key]

        self._remove(node)
        self._insert(node)
        return node.value
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node=self.cache[key]
            node.value=value
            self._remove(node)
            self._insert(node)

        else:
            self.cache[key]=Node(key,value)
        
            self._insert(self.cache[key])
            if len(self.cache)>self.capacity:
                node=self.left.next
                self._remove(node)
                del self.cache[node.key]
            
            
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)