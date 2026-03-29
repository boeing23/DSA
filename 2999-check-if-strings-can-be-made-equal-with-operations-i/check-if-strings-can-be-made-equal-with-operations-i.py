class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:

        even_indices= (s1[0]==s2[0] and s1[2]==s2[2]) or (s1[2]==s2[0] and s1[0]==s2[2])
        odd_indices= (s1[1]==s2[1] and s1[3]==s2[3]) or (s1[1]==s2[3] and s1[3]==s2[1])

        return even_indices and odd_indices
        