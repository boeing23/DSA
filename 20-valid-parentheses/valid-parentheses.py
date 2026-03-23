class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]

        for i in range(len(s)):
            curr=s[i]
            if curr in '({[':
                stack.append(curr)
            else:
                if stack and ((curr==')' and stack[-1]=='(') or (curr==']' and stack[-1]=='[') or (curr=='}' and stack[-1]=='{')):
                    stack.pop()
                else:
                    return False
        return len(stack)==0
        
        