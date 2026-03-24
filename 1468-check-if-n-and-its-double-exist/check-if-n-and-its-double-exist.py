class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen=set()

        for i in range(len(arr)):
            num=arr[i]
            if num*2 in seen or (num%2 ==0 and num//2 in seen):
                return True
            seen.add(num)

        return False