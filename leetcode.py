'''
class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
'''        



                
        


'''
def solve(strl):


        return ann

resu = []
resu.append(solve(anew))

class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums==[0]:
            return 1
        a=max(nums)
        b=min(nums)
        for i in range(b,a+1):
            if i not in nums:
                return i
a = Solution()
print(a.missingNumber([0, 1, 3]))

defaultdict(int)



def time_difference(time1, time2):
    # Fill in your code here
    lst1 = time1.split(':')
    
    lst2 = time2.split(':')
    
    print(lst2)
    c = [0] * 2
    lst = [0] * 3
    k = len(time1) - 1
    (lst[2]) = int(lst2[2]) - int(lst1[2])
    if lst[2] < 0:
            lst[2] += 60
            c[1] = 1
    lst[1] = int(lst2[1]) - int(lst1[1]) - c[1]
    if lst[1] < 0:
        lst[1] += 60
        c[0] = 1
    lst[0] = int(lst2[0]) - int(lst1[0]) - c[0]
    
    strans = ""
    yinhao=0
    for i in lst:
        if i < 10 and i >= 0:
            strans += "0" + str(i)
        else:
            strans += str(i)
        yinhao+=1
        if yinhao<=2:
            strans += ":"

    return( strans)

time_difference('1:2:3', '13:12:11')
'''
def triangle(side1, side2, side3):
    # Fill in your code here
    if side1+side2<side3 or side1+side3<side2 or side2+side3<side1:
        return 'Not a triangle'
    else:
        if side1==side2 and side2==side3 and side1==side3:
            return 'Equilateral'
        elif side1==side2 or side1==side3 or side2==side3:
            return 'Isosceles'
        else:
            return 	'Scalene'
            
print(triangle(5,4,3))