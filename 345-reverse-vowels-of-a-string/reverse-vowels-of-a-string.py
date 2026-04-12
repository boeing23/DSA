class Solution:
    def reverseVowels(self, s: str) -> str:


        l=0
        r=len(s)-1
        s=list(s)


        while l<r:



            if s[l].lower() in 'aeiou' and s[r].lower() in 'aeiou':
                s[l],s[r]=s[r],s[l]
                l+=1
                r-=1

            elif s[l].lower() in 'aeiou':
                r-=1
            elif s[r].lower() in 'aeiou':
                l+=1
            else:
                r-=1
                l+=1

        return ''.join(s)

        