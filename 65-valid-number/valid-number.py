class Solution:
    def isNumber(self, s: str) -> bool:

        #basically keep traversing and keep the variables

        seen_digit=False
        seen_exp=False
        seen_dot=False
        digit_after_exp=True


        # traverse

        # then if digit then checn seen_exp before, then valid:
        # do sen_digit true
        # and digit_after_exp=True

        # now check if it is a sign
        # okay so it's a sign + or - now check is the sign
        # if i>0 and the pev is not e/E then return False

        # now now it is valid

        # next check if curr c is in e/E
        # then check if is e seen earlier: if yes then return False
        # also if not seen digit then also return False

        # now seen exp=True
        # and now do digit_after_exp=false

        for i,c in enumerate(s):
            if c.isdigit():
                seen_digit=True
                if seen_exp:
                    digit_after_exp=True
            elif c in '+-':
                if i>0 and s[i-1] not in 'eE':
                    return False

            elif c =='.':
                #false kadhi karnar return
                if seen_exp or seen_dot:
                    return False
                seen_dot=True
            elif c in 'eE':
                if seen_exp or not seen_digit:
                    return False
                seen_exp=True
                digit_after_exp=False
            else:
                return False
        return seen_digit and digit_after_exp

                
            
        

        





        