class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:

        l=[]

        for i in range(0,len(nums)):
            if nums[i]%2==0:
                l.append(nums[i])

        for i in range(0,len(nums)):
            if nums[i]%2!=0:
                l.append(nums[i])
        return l
