class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        # basically in this question we start from the begnning of the s
        # then let's take the first word
        # now if s[i:end+1]==word then we got the word, we mark it true and end of the word also true
        # next e start from the end character, now starting of that character to the end of any word in i

        dp=[False]*(len(s)+1)
        dp[0]=True

        for i in range(len(s)):
            for w in wordDict:
                
                if dp[i]:
                    end=i+len(w)
                    # we start from the true because it one tells that until here the word
                    # exists in dict also it tells us from where to start instead of re forming that word which came before

                    if end<=len(s) and s[i:end]==w:
                        print(s[i:end])
                        dp[end]=True    #now next word would certainly start from here

                else:
                    continue
        return dp[len(s)]


            
            

        
        
        