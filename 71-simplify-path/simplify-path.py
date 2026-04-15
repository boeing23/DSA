class Solution:
    def simplifyPath(self, path: str) -> str:
        

        #okay so stack i can use
        stack=[]

        parts=path.split('/')


        #parts=['home','user','Documents','..','Pictures']


        for part in parts:

            if part=='..':
                if stack:
                    stack.pop()
            elif part=='' or part=='.':
                continue
            else:
                stack.append(part)
        return '/'+'/'.join(stack)
        
            


        