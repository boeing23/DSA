class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:

        # bassically the task is to return the word in the dict. You can either
        # return an exact word in the dictionary or the lowercase letter
        # or the de voweled one



        exact=set(wordlist)
        devoweled={}
        cap_list={}

        def devowel(s:str)->str:
            ans=""
            for ch in s:
                if ch in 'aeiou':
                    ans+='*'
                else:
                    ans+=ch
            return ans

        for i in range(len(wordlist)):

            low=wordlist[i].lower()

            cap_list.setdefault(low,wordlist[i])
            devoweled.setdefault(devowel(low), wordlist[i])
        result=[]
        for q in queries:

            lowq=q.lower()

            if q in exact:
                result.append(q)
            elif lowq in cap_list:
                result.append(cap_list[lowq])
            elif devowel(lowq) in devoweled:
                result.append(devoweled[devowel(lowq)])
            else:
                result.append("")
        return result

        