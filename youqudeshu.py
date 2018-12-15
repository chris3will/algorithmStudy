import math

dp = []
for i in range(1010):
    dp.append([0 for x in range(0, 10)])

n = int(input())
Mod = 1000000007
#做这种题要分清楚状态为，把这个有趣的情况分成6种小情况
'''
又题意可推出2必在第一位
0 只含2
1 只含2，0
2 只含2，3
3 只含2，0，1
4 只含2，0，3
5 包含4种数字
'''
for i in range(0, n):
    #i 代表位数
    #dp均为满足条件个数，不是某一位的数值
    dp[i][0] = 1 % Mod#把这个数设置为1
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % Mod
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][2] * 2) % Mod
    dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % Mod
    dp[i][4] = (dp[i - 1][4] * 2 + dp[i - 1][1] + dp[i - 1][2]) % Mod
    dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2)%Mod
    print(dp[i][5],"$$$")