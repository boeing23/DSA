class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window=set()
        maxL=0

        left=0

        for right in range(len(s)):
            curr_c=s[right]

            
            while curr_c in window:
                window.remove(s[left])
                left+=1

            maxL=max(maxL, right-left+1)

            window.add(curr_c)
        return maxL
# TC=O(n)
# SC=O(n)