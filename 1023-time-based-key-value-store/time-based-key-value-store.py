class TimeMap:

    def __init__(self):
        #this should store the key -> (timestamp, value)
        self.store={}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store.setdefault(key,[]).append((timestamp,value))

        

    def get(self, key: str, timestamp: int) -> str:
        # get should find the key then it has to return the ts if 
        # it is there else don't
        versions=self.store.get(key,[])
        #print(versions)
        
        index=bisect.bisect_right(versions,(timestamp,"{}"))
        if index!=0:
            return versions[index-1][1]
        return ""
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)