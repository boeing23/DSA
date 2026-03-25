# basically use a hash to store the index in the array
# now to delete the element, what you can do is replace the last element with the intereted element
# then pop

class RandomizedSet:

    def __init__(self):
        self.indexMap={}
        self.array=[]

        

    def insert(self, val: int) -> bool:

        #key will be val and it's index will be the val
        if val in self.indexMap:
            return False
        self.array.append(val)
        self.indexMap[val]=len(self.array)-1
        return True
        

    def remove(self, val: int) -> bool:
        #now to remove you get the index of the element from the indexMap

        if val not in self.indexMap:
            return False
        
        index=self.indexMap[val]
        self.array[index], self.array[len(self.array)-1]= self.array[len(self.array)-1], self.array[index]
       # the value t index is different now, so 
        self.indexMap[self.array[index]]=index

        self.array.pop()
        del self.indexMap[val]
        return True
        

    def getRandom(self) -> int:
        return random.choice(self.array)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()