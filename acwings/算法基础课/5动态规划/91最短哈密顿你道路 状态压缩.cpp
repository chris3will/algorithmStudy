/*
 * @Author: Chris Wang
 * @Date: 2020-03-27 10:22:18
 * @LastEditors: your name
 * @LastEditTime: 2020-03-27 10:22:39
 * @Description: file content
 */
/*
 * 最短哈密顿问题
 * 状态压缩的经典题目
*/
//暴力情况下的状态是20的阶乘，数量级太大了，但是我们这样使用状态压缩的技术之后，就可以大大缩小数量级
//        f[state][j] state表示哪些点被用过，j的话就可以枚举
//
//        一定要抓住重点，哪些点被用过，当前停在哪个点上头
//        f[state][j] = f[state_k][k] +weight[k][j], state_k = state 除掉j之后的集合，且state_k要包含k
//
//        每个代码都是由虚拟空间的。
//整个虚拟空间大概分为两部分，上面是栈空间（cpp默认大小4mb），下面是堆空间（全局，静态）。所以我们把大数组开到全局变量中

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 20, M = 1<<20;

int n;
int f[M][N], weight[N][N];  //f[i][j]状态i下，到达点j的最短路径长度大小

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>weight[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;  //当前位于起点，0号点，不存在边长问题

    for(int i=1;i< 1<<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>>j & 1)
            {
                //如果这个状态走了这一天
                for(int k=0;k<n;k++)
                {
                    if(i - (1<<j) >> k & 1)
                    {
                        f[i][j] = min(f[i][j],f[i-(1<<j)][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    cout<<f[(1<<n)-1][n-1]<<endl;

    return 0;
}