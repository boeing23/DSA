class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:

        # okay now I have the numbers
        # i have to find the kth missing, the brute fore is pretty easy

        # you keep a count varuable, and you run a while loop until you find count==k
        # you increment count when the char is missing in arr

        present=set(arr)
        count=0
        index=1

        while count<k:
            if index not in present:
                count+=1
            index+=1
                
        return index-1