class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:


        # so basically you keep a window and suddnely you find something already in the set you take the max len

        # set to keep track of unique elements inside the window

        maxLen=0
        window=set()
        l=0

        # so the window should be unique
        # remove the last element until it is not there in the w

        for r in range(len(s)):

            if s[r] in window:


                while s[r] in window:
                    window.remove(s[l])
                    l+=1
                    
                


            window.add(s[r])
            maxLen=max(maxLen, r-l+1)
        return maxLen



        