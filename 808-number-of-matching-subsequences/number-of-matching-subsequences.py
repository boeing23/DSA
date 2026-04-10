class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:


        # so basicaly go to each word and check whether it is in s if it is
        # then it is the start
        # and then traverse it checking the index current is bigger than the 
        # index where you started


        # the brute force would be using s.find 
        count=0

        for word in words:
            pos=-1
            found=True


            for ch in word:
                pos=s.find(ch, pos+1)

                if pos==-1:
                    found=False
                    break
            if found==True:
                count+=1
        return count
        