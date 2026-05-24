class Solution:
    def validIPAddress(self, queryIP: str) -> str:


        parts=queryIP.split('.')

        #the task is to determine which is ipv4 and which is ipv6
        if len(parts)==4:
            for part in parts:
                if not part.isdigit():
                    return "Neither"
                if not 0<=int(part)<256:
                    return "Neither"
                if len(part)>1 and part[0]=='0':
                    return "Neither"
            return "IPv4"
        parts2=queryIP.split(':')

        if len(parts2)==8:
            for part in parts2:
                if not 1<=len(part)<=4:
                    return "Neither"
                
                for c in part:
                    if c not in '0123456789ABCDEFabcdef':
                        return "Neither"
            return "IPv6"
        return "Neither"
        


        