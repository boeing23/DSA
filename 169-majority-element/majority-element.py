class Solution:
    def majorityElement(self, nums: List[int]) -> int:


        # it is something like this
        # basically you keep incrementing if equal

        # 3 but suddenly a new elemt appears you do
        # -1
        # if ==0 majority_cou
        candidate=None
        count=0
        for n in nums:
            if count==0:
                candidate=n
            count+=1 if n==candidate else -1
        return candidate

            
        