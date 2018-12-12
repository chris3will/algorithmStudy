nn, k = list(map(int, input().split()))
stu=[1]*nn
flag = 0
num = 1
zeros = 0
ft = True
if (nn == 1):
    ft=False
while (ft):
    #从第一个小孩开始报数，当他没有被淘汰的时候才让他报数
    if stu[flag] == 1:
        if (num % k == 0 or str(num)[-1] == "k"):
            stu[flag] = 0
            flag = (flag + 1) % nn
            num += 1
            zeros+=1
        else:
            num += 1
            flag = (flag + 1) % nn
    else:
        flag = (flag + 1) % nn
    if zeros == nn - 1:
        break                    
            

for i in range(len(stu)):
    if (stu[i] == 1):
        print(i+1)