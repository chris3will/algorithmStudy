class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        amount=len(nums)-1
        nums = sorted(nums)
        times=0
        while not nums[0] == nums[-1]:
            times += 1
            print(nums)
            for i in range(0, amount):
                nums[i] += 1
            nums=sorted(nums)
        
        return(times)

a = Solution()
a.minMoves([1,2,3])