class Solution:
    def calculate(self, s: str) -> int:

        # whenever ( is encountered add the result to the 
        # stack
        stack=[]
        num=0
        sign=1
        sums=0


        for c in s:
            if c.isdigit():
                num= num*10+(ord(c)-ord('0'))
            elif c in '+-':
                sums+=(num*sign)
                sign=1 if c=='+' else -1
                num=0
            
            else:

                if c=='(':
                    stack.append(sums)
                    stack.append(sign)

                    num=0
                    sums=0
                    sign=1
            
                elif c==')':
                    sums+=num*sign
                    num=0
                    prev_sign= stack.pop()
                    prev_num=stack.pop()

                    sums= prev_num + (sums*prev_sign)
                    

        return sums + (sign*num)
            
            



            

        