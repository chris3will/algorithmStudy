class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #[2,3,1,1,4] true
        reach = 0
        for i, num in enumerate(nums):
            if i > reach:
                return False
            reach = max(reach, i + num)
        return True

a = Solution()
print(a.canJump([0,1,1,1,3]))
        