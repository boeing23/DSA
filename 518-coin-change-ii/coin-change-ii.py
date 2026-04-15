class Solution:
    def change(self, amount: int, coins: List[int]) -> int:


        # what will the children return?
        # 1. either take or go ahead, I have to return total combinations
        # 2. base case is return 1 if amount is made, 


        # dp because let's say for the first tree we migh calculate the denomination now when it goes to the second recusion then we calculate it again for that idx, instead we can just return the earlier calculated value


        dp=defaultdict(int)
        


        def dfs(idx,curr_amount):

            if curr_amount==0:
                return 1

            if idx>=len(coins) or curr_amount<0:
                return 0
            if (idx,curr_amount) in dp:
                return dp[(idx,curr_amount)]

            take=dfs(idx,curr_amount-coins[idx])
            nottake=dfs(idx+1,curr_amount)

            dp[(idx,curr_amount)]= take+nottake


            return dp[(idx,curr_amount)]
        

        return dfs(0,amount)
        