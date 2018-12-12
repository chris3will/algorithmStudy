#coding:utf8
N, K = list(map(int, input().split()))
teacher = []
endtime=0
while (K > 0):
    K -= 1
    teacher.append(list(map(int, input().split())))
    endtime=max(endtime,teacher[-1][1]+teacher[-1][2])
keys = [i for i in range(1, N + 1)]
time = 0
while (time <= endtime):
    
        
    time += 1
print(keys)
            

    