'''
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        flag=0
        for i in range(0,len(nums)):
            item = target - nums[i]
            
            if item in nums and i!=nums.index(item):
                
                l=[]
                l.append(i)
                l.append(nums.index(item))
                flag=1
                return l
            else:
                continue
        if flag==0:
            return [0,0]
'''
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for k, num in enumerate(nums):
            dic[num] = k
        for i in dic:
            #print(i,dic[i])
            if target - i in dic and i!= target-i:
                l = []
                l.append(min(dic[target - i], dic[i]))
                l.append(max(dic[target - i], dic[i]))
                return l
        return [0,0]
    

            
a = Solution()
print(a.twoSum([3,2,4], 6))
