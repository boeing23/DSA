class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:

        # so three priorities
        # 1. exact word exists or not
        # if not then check if the lowercase exists or not

        # 3. devowel


        exact_w=set(wordlist)

        cap_w={}
        vowel_list={}

        def devowel(w):
            word=''
            for ch in w:
                if ch in 'aeiou':
                    word+='*'
                else:
                    word+=ch
            return word
        for word in wordlist:
            low=word.lower()
            cap_w.setdefault(low,word)
            vowel_list.setdefault(devowel(low),word)
        result=[]
        for q in queries:
            low=q.lower()
            dev=devowel(low)
            if q in exact_w:
                result.append(q)
            elif low in cap_w:
                result.append(cap_w[low])
            elif dev in vowel_list:
                result.append(vowel_list[dev])
            else:
                result.append("")
        return result

            


        