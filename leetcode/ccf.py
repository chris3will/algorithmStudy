#coding:utf8
import math
N, K = list(map(int, input().split(" ")))
#N为教室数量，K为老师的数目
#每次老师都会找到自己的钥匙，每个钥匙都有自己的标记
#归还钥匙的时候总是先还到最左边的空位
#如果有多把钥匙同时归还，则先归还编号小的钥匙
#如果同一时刻既有还也有借的便先借再取
#开始的时候所有带编号的钥匙从小到大摆放在盒子里

keys = [i for i in range(1, N + 1)]
#初始化钥匙序列
teachers = []
bound=0
while K > 0:
    msg = list(map(int, input().split(" ")))
    msg[2]=msg[1]+msg[2]
    bound=max(bound,msg[2])
    teachers.append(msg)
    K -= 1
#初始化老师序列
#需要有一个time标签来记录此时刻的活动
#我是利用字典还是暴力算呢? 使用字典这个哈希表的时候
#标记一把钥匙的话，把他的开始时间和归还时间都记录下来，然后有两个时刻
#但如果不同的老师用同一把钥匙的问题怎么处理？ 可以继续追加即可将每个字典建立然后再把字典排序
#不过我先采用一次暴力算法吧
time = 0
while time <= bound:
    time += 1
    returns = []
    brows=[]
    #先还钥匙吧，把这些放回keys序列
    for i in range(len(teachers)):
        #在这个循环中遍历时刻以便进行操作
        if teachers[i][2] == time:
            #把这个时刻要归还的钥匙进行记录
            returns.append(teachers[i][0])
        if teachers[i][1] == time:
            #把这个时刻要借入的钥匙进行记录
            brows.append(teachers[i][0])
    #先把钥匙还了
    returns = sorted(returns,reverse=False)
    #returns中存的都是待归还的钥匙的编号,按照从小到大
    
            


