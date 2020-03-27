/*
 * @Author: Chris Wang
 * @Date: 2020-03-27 08:58:16
 * @LastEditors: your name
 * @LastEditTime: 2020-03-27 09:12:03
 * @Description: 奇怪的汉诺塔
 */
#include<iostream>
#include<cstring>
using namespace std;

int n;
int d[12+1],f[12+1];

int main()
{
    d[1] = 1;// 一个饼的时候普通汉诺塔只用1步
    //先枚举所有普通汉诺塔的步数
    for(int i=2;i<=12;i++)
    {
        d[i] = 1 + 2*d[i-1];
    }

    memset(f,0x3f,sizeof f);  //0x3f的性质是，它很大，但是两倍的它也不会发生溢出

    f[0] = 0;//要求的是搬运第i个盘子到达第四个杆子所用的最小步数
    for(int i=1;i<=12;i++)
    {
        //先把三根柱子的状态下所有可能的最短步数提供出来 
        for(int j=0;j<i;j++)
        {  //我们在这里枚举前j个盘子的情况
            f[i] = min(f[i],f[j]*2 + d[i-j]);  //剩下的i-j个盘子不能放到前j个那一堆上面，所以只能用三根棍子的最大情况
        }
    }

    for(int i=1;i<=12;i++)cout<<f[i]<<endl;
    return 0 ; 
}