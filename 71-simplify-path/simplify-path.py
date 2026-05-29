class Solution:
    def simplifyPath(self, path: str) -> str:
        

        # "home""foo"
        # first of all i would do a split on ('/')

        # then
        # this would be
        # "home" "user" "Documents" ".." "Pictures"
        # stack

        # home, user, document, 
        # if .. or .


        # "..." "a" ".." "b" "c" ".." "d" "."

        # "..." "b" "d" 

        # so double dot-> one pop and 
        # . dot-> skip
        parts=path.split('/')
        # print(parts)
        normalized=[]
        for p in parts:
            if p:
                normalized.append(p)

        stack=[]

        for part in normalized:

            if stack and part=="..":
                stack.pop()
            
            elif part==".":
                continue
            else:
                if part!="..":
                    stack.append(part)
                #print(stack)
        #["...", "b","d"]

        return "/"+ "/".join(stack)



            

