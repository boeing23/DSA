class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        # frqMap=Counter(nums)

        # for key,val in frqMap.items():
        #     if val > len(nums)//2:
        #         return key
        # return 0 


        # Boyer Moore algo,
        # if you are on current num, take this as a candidate and keep counting the votes for
        # if you come across any different candi then remove the count if count==0 then change the candiate


        candidate=None
        count=0

        for n in nums:
            if count==0:
                candidate=n
                count+=1
            else:
                if n!=candidate:
                    count-=1
                else:
                    count+=1

        return candidate
        