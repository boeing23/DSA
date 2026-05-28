class Solution:
    def calPoints(self, operations: List[str]) -> int:

        # basically i am just traversing the string 
        # whenever i see any digit is just go and put it in the list
        # then if the C is there i just pop the last one

        result=[]
        #removed
        i=0
        while i<len(operations):
            if operations[i].isdigit() or (operations[i].startswith("-") and operations[i][1:].isdigit()):
                result.append(int(operations[i]))
                i+=1
            elif operations[i]=="C":
                result.pop()
                i+=1
            elif operations[i]=="D":
                result.append(2*result[-1])
                i+=1
            else:
                #this should add the previos two scores
                result.append(result[-1]+result[-2])
                i+=1
        return sum(result)

        

        