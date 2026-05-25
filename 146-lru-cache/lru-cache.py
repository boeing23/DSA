# # basically it has to store the most recently accessed task. In order to implement it
# # we would normally use a dict to map the key value pair but how would you track the most
# # recently used one
# # a bruter force approach could be most recent -> key ->value
# # instead we can just use pointers which would tell us the recently used and least used that's it
# # no need to over architect it

# so the implementation is as follows:

# you store a key as an identifier then a node reference 

# key > reference > Node|key:Value|

# why key in the node too?
# basicaly when you do get the right pointer will tell you the most recent node
# which would just return value if we only store value key we are storing for the ease of finding it inside the dict too for eviction purpose

class Node:
    #node has a value ,key and 
    def __init__(self, key: int, value: int):
        self.key=key
        self.value=value
        self.next=None
        self.prev=None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity=capacity
        self.ref_table={}
        self.left=Node(0,0)
        self.right=Node(0,0)
        self.left.next=self.right
        self.right.prev=self.left

    def _insert(self,node):
       #most recent one < node > < right

       prev_node=self.right.prev
       node.next=self.right
       self.right.prev=node

       node.prev=prev_node
       prev_node.next= node


    def remove(self,node):

        #left > node1 >  node2
        tmp1=node.prev
        tmp2=node.next
        tmp1.next=tmp2
        tmp2.prev=tmp1


        

    def get(self, key: int) -> int:

        # basically it gets the value from the ref_table and returns it, now it should
        # also mark that node as currently accessed

        if key not in self.ref_table:
            return -1
        node=self.ref_table[key]
        self.remove(node)
        self._insert(node)  
           #basically this will update the most recently used

        

        #now it should put the recent key beside the left and right


        

        return node.value

        

    def put(self, key: int, value: int) -> None:
        # put has two things update if the value exists
        # and also keep track of the recently access key basically it should update the cache if capacity is full and evict the recently used one

        if key not in self.ref_table:
            self.ref_table[key]=Node(key,value)
            self._insert(self.ref_table[key])
            if len(self.ref_table)>self.capacity:
                least_used=self.left.next
                self.remove(least_used)
                del self.ref_table[least_used.key]
            return

        #when we update the value we basically update the val + insert it in the right
        node= self.ref_table[key]
        node.value=value
        self.remove(node)
        self._insert(node)

        


       

       



        
        



        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)