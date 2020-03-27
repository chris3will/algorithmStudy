/*
 * @Author: Chris Wang
 * @Date: 2020-03-27 16:02:15
 * @LastEditors: your name
 * @LastEditTime: 2020-03-27 16:02:45
 * @Description: file content
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 310;
int r,c;
int f[N][N],cc[N][N];  //原始数组与记忆化数组f[i][j]表示从i,j出发所能走过的最长路径，本题采用递归的思路进行处理
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int dp(int x, int y)
{
    int &v = f[x][y]; //引用一下
    if(v!=-1)return v;  //越高的点会越先
    v = 1;
    
    for(int i=0;i<4;i++)
    {
        int a = x+dx[i], b= y+dy[i];
        if(a>=1&&a<=r&&b>=1&&b<=c&&cc[a][b]<cc[x][y])
        {
            v = max(v,dp(a,b)+1);
        }
    }
    
    return v;
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&cc[i][j]);
    
    memset(f, -1, sizeof f); //
    int res = 0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            res = max(res,dp(i,j));
        
    cout<<res<<endl;
    
    
    return 0;
}