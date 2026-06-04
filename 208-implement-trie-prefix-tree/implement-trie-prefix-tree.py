class Node:
    def __init__(self):
        self.children={}
        self.is_end=False

class Trie:

    def __init__(self):
        self.root=Node()
        

    def insert(self, word: str) -> None:
        node=self.root
        n=len(word)
        for i in range(n):
            w=word[i]
            if w in node.children:
                node=node.children[w]
            else:
                node.children[w]=Node()
                node=node.children[w]
            if i==n-1:
                node.is_end=True
            #node=node.children[w]
            
        

    def search(self, word: str) -> bool:
        node=self.root
        n=len(word)
        for i in range(n):
            w=word[i]
            if w not in node.children:
                return False
            node=node.children[w]
        return node.is_end==True
        

    def startsWith(self, prefix: str) -> bool:
        node=self.root
        n=len(prefix)
        for i in range(n):
            w=prefix[i]
            if w not in node.children:
                return False
            node=node.children[w]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)