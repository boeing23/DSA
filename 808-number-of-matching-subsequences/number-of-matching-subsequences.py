class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:

        # not the optimal approach would be finding the pos using the binary search
        # then checking if the mid is greater than pos if it is then change pos to
        # the mid index and then set found for that char



        # but first store all the indices of the char in s


        index_map=defaultdict(list)
        count=0

        for i in range(len(s)):
            index_map[s[i]].append(i)

        # this creates the index map

        # now in that list we have to do the binary search

        for word in words:
            pos=-1
            found=True

            for ch in word:
                if ch not in index_map:
                    found=False
                    break
                indexes=index_map[ch]

                lo=0
                hi=len(indexes)-1
                res=-1

                while lo<=hi:

                    mid=(lo+hi)//2

                    if indexes[mid] >=pos+1:
                        res=mid
                        hi=mid-1
                    else:
                        lo=mid+1
                if res==-1:
                    found=False
                    break
                pos=indexes[res]

            if found==True:
                count+=1
        return count
        





        