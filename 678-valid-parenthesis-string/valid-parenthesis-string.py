class Solution:
    def checkValidString(self, s: str) -> bool:
        # so basically maintain two stacks, one for storing the indices of opening brakcets and one for storing the astericks
        stackO=[]
        stackA=[]

        for c in range(len(s)):
            if s[c]=='(':
                stackO.append(c)
            elif s[c]=='*':
                stackA.append(c)
            elif s[c]==')':
                if stackO:
                    stackO.pop()
                elif stackA:
                    stackA.pop()
                else:
                    return False
        # laast loop to process
        if stackO and len(stackA)==0:
            return False
        

        while stackO and stackA:
            if stackO[-1]<stackA[-1]:
                stackO.pop()
                stackA.pop()
            else:
                return False
        return len(stackO)==0
            
            

           
            


            # let's say the stackO was emtpy or top is 
            # you push the opening bracket
            # stackO.append(s[i])



        