class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # basically I am given words and i have to group the anagrams together

        # brute force could be for each word you find a matching anagram

        # so basically your worst case TC will be O(n^2) and now space complexity would be
        # n*k n is basically the len of strs and k is word len


        # okay now the optimal approach would be, you create a frq list of the curr string
        # now let's say eat is there, you create a frq list of the chars init

        # which might look like this 10001000.. as a and e appears once

        # now you use this as a key. i will convert this list into a string as list is mutable and cannot be taken as a key as key should be something immutable so I can either take it as a string or a tuple

        anagramMap=defaultdict(list)

        for i,s in enumerate(strs):

            currWord=s

            key=[0]*26

            for c in range(len(s)):
                key[ord(s[c])-ord('a')]+=1

            key=','.join(map(str,key)) 
            anagramMap[key].append(s)
        ans=[]
        for key,val in anagramMap.items():

            anagrams=val
            ans.append(val)
        return ans


