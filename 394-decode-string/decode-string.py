class Solution:
    def decodeString(self, s: str) -> str:


        # i know this question basically you use a stack to store the state but
        # implementation let's think of it

        # basically you start solving it from the end you know the end once you discover a 
        # closing bracket


        # [3[a2[c]]]

        # now you hit a closing
        # you pop until you find the opening
        # [ next you get the number of top and run it that many times
        # you store the result and traverse further

        #now let's see how ca n we do this

        # for loop to traverse the string char by char

        # a stack to record previos states

        # if c==isdigit
        # push it
        # if c=='['
        # push it
        # if c==']'
        # now from here the game starts
        # while stack and stack.top!='[':
        #     you got achar a
        #     stor it in a string
        #     then pop it
        #     now when you encounter a [ you pop it
        #     then right after that you leave
        #     now you for the string
        stack=[]
        num=0
        curr_str=""
        for c in s:

            if c.isdigit():
                num=num*10+(ord(c)-ord('0'))
            elif c == '[':
                stack.append(curr_str)
                stack.append(num)
                num=0
                curr_str=""
            elif c=="]":
                #now here it should take the curr_str
                prev_num=stack.pop()
                prev_str=stack.pop()

                curr_str=prev_str+prev_num*curr_str
                
            else:
                curr_str=curr_str+c
        return curr_str
            
            






        # [3]


        # aaa
        