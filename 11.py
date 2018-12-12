'''
def mode_score(students):
    scores = {}
    for i in students:
        if i[2] not in scores:
            scores[i[2]] = 1
        else:
            scores[i[2]] += 1
    #print(scores)
    ans = sorted(scores.items(), key= lambda x: x[1], reverse = True)
    #print(ans)
    maxtime = ans[0][1]
    res = []
    for i in ans:
        if i[1] == maxtime:
            res.append(i[0])
    return res


### DO NOT MODIFY THIS ###
students = [('tiffany', 'A', 15), 
            ('jane', 'B', 10),
            ('ben', 'C', 8), 
            ('simon', 'A', 21), 
            ('eugene', 'A', 21), 
            ('john', 'A', 15), 
            ('jimmy', 'F', 1), 
            ('charles', 'C', 9), 
            ('freddy', 'D', 4), 
            ('dave', 'B', 12)]

print(mode_score(students))


def top_k(students, k):
    b = sorted(students, key=lambda x: x[2]  ,reverse=True)
    for i in range(len(b)-1):
        if (b[i + 1][2] == b[i][2]):
            if b[i + 1][0] < b[i][0]:
                b[i],b[i+1]=b[i+1],b[i]
    num = 0
    ans = []
    print(b)
    flag=1
    while (flag):
        if num < k:
            ans.append(b[num])
        else:
            if num >= k:
                print(b[num])
                if b[num -1][2] == b[num][2]:
                    ans.append(b[num])
                    flag = 1
                else:
                    flag = 0
        num+=1
            
    print(ans)


### DO NOT MODIFY THIS ###
students = [('tiffany', 'A', 15), 
            ('jane', 'B', 10),
            ('ben', 'C', 8), 
            ('simon', 'A', 21), 
            ('eugene', 'A', 21), 
            ('john', 'A', 15), 
            ('jimmy', 'F', 1), 
            ('charles', 'C', 9), 
            ('freddy', 'D', 4), 
            ('dave', 'B', 12)]
top_k(students, 3)


def shift_one_left(num):
    neww=str(num)+str(num)[0]
    return int(neww[1:])  
    
def shift_left(num, n):
    ans=num
    while (n > 0):
        
        ans=shift_one_left(ans)
        n -= 1
    
    return(ans)

shift_left(12345,2)  

def nth_digit(n, num):
    #your code here
    return int(str(num)[len(str(num))-n])
    

    
def mth_digit(m, num):
    #your code here
    return int(str(num)[m-1)


def divisible_by_11(num):
    #your code here
    if num>=0:
        if num>0:
            return divisible_by_11(num-11)
        else:
            return True
    else:
        return False
            
print(divisible_by_11(11))

def concat(n, m):
    #your code here
    lsta = "".join(str(n))
    print(lsta)

concat(123,4)

def replace_digit(n, d, r):
    #your code here
    a = str(n)
    b=a.replace(d,r,-1)
    return (b)
    
    
print(replace_digit(1, 2, -1))

def count_change(amount, kinds_of_coins):
    #your code here
    c=[0,1,5,10,20,50]
    if amount<=0:
        return amount==0
    if kinds_of_coins == 0:
        return 0
    else:
        return count_change(amount, kinds_of_coins - 1) + count_change(amount - c[kinds_of_coins], kinds_of_coins)
        
print(count_change(5, 2))

def shift_one_right(num):
    strnew = str(num)[-1] + str(num)
    return(int(strnew[0:-1]))
    
def shift_right(num, n):
    ans=num
    while (n > 0):
        
        ans=shift_one_right(ans)
        n -= 1

    return (ans)
print(shift_right(12345,1))

def shift_one_right(num):
    return int((str(num)[-1] + str(num))[0:-1])
print(shift_one_right(1234))

'''
def