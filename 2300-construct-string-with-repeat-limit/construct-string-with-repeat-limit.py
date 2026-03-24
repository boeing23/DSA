class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:

        frqMap=Counter(s)

        ans=[]
        
        unique=sorted(set(s))

        #now the max is at the back



        while unique:

            maxE=unique[-1]
            useC=min(frqMap[maxE],repeatLimit)

            ans.append(maxE*useC)
            frqMap[maxE]-=useC

            if frqMap[maxE]==0:
                unique.pop()
            else:
                if len(unique)<2:
                    break
                second=unique[-2]
                # useC=min(frqMap[second],repeatLimit)
                ans.append(second)
                frqMap[second]-=1
                if frqMap[second]==0:
                    unique.pop(-2)
        return "".join(ans)
                
            
        
        