class Solution:
    def calculate(self, s: str) -> int:
        nums=0
        stack=[]

        # now whenever i add it to the stack i flush the num
        # now you should add to the stack

        # whenevr you hit a sign
        sign=1
        result=0

        for ch in s:
            if ch.isdigit():
                nums=nums*10+int(ch)


            if ch in '+-':
                nums=nums*sign

                result+=nums
                nums=0
                sign=1 if ch=='+' else -1
            elif ch==" ":
                continue
            elif ch=="(":
                stack.append(result)
                result=0
                stack.append(sign)
                nums=0
                sign=1

            elif ch==")":
                result += sign * nums
                nums=0
                
                prev_sign=stack.pop()
                
                prev_result=stack.pop()

                result=prev_result+result*prev_sign
                
        result += sign * nums
        return result



        

                



        