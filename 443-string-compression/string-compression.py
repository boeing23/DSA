class Solution:
    def compress(self, chars: List[str]) -> int:

        

        #this creates a frq map for all the chars in the array

        # now traverse this map and if the frq is 1< then add the
        # char + frq to the string
        s=""
        count=1

        #so basically if prev is same to current increase the count
        for i,c in enumerate(chars):
            if i>0:
                if chars[i-1]==c:
                    count+=1
                else:
                    s+=chars[i-1]
                    if count>1:
                        s+=str(count)
                        count=1
        s+=chars[-1]
        if count>1:
            s+=str(count)
                        


        



        i=0
        while i<len(s):
            chars[i]=s[i]
            i+=1
        return len(s)



# now if the a is in a different postion it should have it's own frq
# now this question makes sense

# c=1
# a
# if i-1==i
# c+=1
# else:
#     either it is a different char from current and c>1
#     then concatenate





            


        