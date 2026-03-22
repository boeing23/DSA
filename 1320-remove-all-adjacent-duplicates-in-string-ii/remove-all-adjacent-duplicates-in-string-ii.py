class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:

        count=0
        stack=[]

        #ye bas traverse karne k liye then agar duplicate mila and count<k then remove karung

        for i in range(len(s)):
# iss vale me stack to chahiye now what, bc 

# basically mujhe k times remove or ignore kar sakta hu

# if previous==current and count==k
# then while


            # while loop basically tab trigger kar jevha count reach honar and previous jo aahe to
            # same as current aahe

            #basically hya question madhe stack use kela aahe jo count thevnar maghcha cha


            i=0
            stack=[]
            for c in range(len(s)):
                if stack and stack[-1][0]==s[c]:
                    stack[-1][1]+=1
                    if stack[-1][1]==k:
                        stack.pop()
                else:
                    stack.append([s[c],1])


               
                
            res=""
            for c, count in stack:
                res+=c*count
            return res
                    
                    



        