class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:

        notbanned=[]
        banned=set(banned)

        for i in range(1,n+1):
            if i in banned:
                continue
            notbanned.append(i)
        # notbanned.sort()

        sum=0
        i=0

        while i < len(notbanned):
            
            sum+=notbanned[i]

            if sum > maxSum:
                sum-=notbanned[i]
                i-1
                break
            i+=1
            
            print(sum)
            print(i)
        return i
        