/*
 * @Author: Chris Wang
 * @Date: 2020-03-18 14:36:07
 * @LastEditors: your name
 * @LastEditTime: 2020-03-18 14:36:42
 * @Description: file content
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510;
int dp[N][N];  //表示从起点到dp[i][j] （i，j）的最大路径长度

int tri[N][N];  //存储基础路径

int n,m;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            scanf("%d",&tri[i][j]);
    }

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            tri[i][j] += max(tri[i+1][j],tri[i+1][j+1]); 
        }
    }
    cout<<tri[1][1]<<endl;

    return 0;
}
