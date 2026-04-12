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

            while l<r and s[l].lower() not in 'aeiou':
                l+=1
            while l<r and  s[r].lower() not in 'aeiou':
                r-=1


        return ''.join(s)

        