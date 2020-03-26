/*
 * @Author: Chris Wang
 * @Date: 2020-03-26 23:08:00
 * @LastEditors: your name
 * @LastEditTime: 2020-03-26 23:08:27
 * @Description: file content
 */
//状态压缩，看成二进制数

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 12, M = 1<<N;

int n,m;
long long f[N][M];
bool st[M];  //用来检测每一种可能的状态是否存在非法情况，我们在后面会用它进行过滤操作；因为我我们默认了是去塞横向方块，所以纵向的方块的方案是会被唯一确定的

int main()
{
    int n,m;
    while(cin>>n>>m, n || m)
    {


        //预处理状态，
        for(int i=0;i< 1<<n;i++)
        {//遍历图中每一列的各种可能存在的状态
            st[i] = true ; //假设是成立的，即没有连续奇数个0
            int cnt = 0;  //当前这一段连续0的个数

            for(int j=0;j<n;j++)
                if(i>>j &1)
                {//上一段为0序列已经截止了
                    if(cnt & 1)st[i] = false;  //第i个状态有奇数个0，则不成立
                    cnt = 0;
                }
                else cnt++;
            if(cnt&1) st[i] = false;  //如果最后一段的0的个数为奇数
        }

        memset(f,0,sizeof f);
         //第0列的前边是不可能通过来的
         f[0][0] = 1; //第一列是0的时候，才有一种方案

         for(int i=1;i<=m;i++)
             for(int j=0;j< 1<<n;j++)

                 //再枚举前一列的状态
                 for(int k=0;k< 1<<n; k++)
                 {
                     if ((j & k) == 0 && st[j | k])
                         f[i][j] += f[i - 1][k];
                 }



         cout<<f[m][0]<<endl;

    }
    return 0;
}