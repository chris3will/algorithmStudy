class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        d = {}
        d[0]=1
        sums = 0
        res = 0
        for i in range(n):
            sums += nums[i]
            if sums - k in d:
                res += d[sums - k]
            if sums in d:
                d[sums] += 1
            else:
                d[sums]=1
        return(res)
        '''
        还没怎么看动
a = Solution()
a.subarraySum([1,1,1],2)
              