class RandomizedSet:

    def __init__(self):
        #so the logic is use a list and store the pos in a dict
        self.arr=[]
        self.pos={}

        

    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        idx=len(self.arr)
        self.pos[val]=idx
        self.arr.append(val)
        return True
        
        

    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        idx=self.pos[val] #this store the index of that val need to be removed
        last=self.arr[-1] #this stores the last element in the array
        self.arr[idx]=last
        self.pos[last]=idx
        self.arr.pop()
        del self.pos[val]
        
        
        return True
        

    def getRandom(self) -> int:
        return random.choice(self.arr)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()