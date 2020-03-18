'''
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        d = {}
        d[0] = 1
        #遇到那种和sums-k=0的情况即出现连续和为k的情况时，标记加1
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
        【1，1，1】这个例子就是，第一次加是因为连续的2，第二次加是因为连续的3减去连续的1存在。即又有连续的2
        从前向后一次循环，把所有小的子累加和都存到字典里，如果出现一次sums就存到d中，如果sums-k在字典里，同时sums已经在字典里，则说明k肯定又生成了一次。则res++


'''
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                print(i,j)
                if (sum(nums[i:j + 1])) == k:
                    #它自己也有可能就是k
                    res += 1
        print(res)
a = Solution()
a.subarraySum([1, 1, 1], 2)