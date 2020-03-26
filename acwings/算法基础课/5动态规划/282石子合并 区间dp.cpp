//石子合并问题
//https://www.acwing.com/problem/content/284/
//一个典型的区间dp问题

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 310, INF = 1e9;
int w[N],s[N];
int f[N][N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)s[i] = s[i-1 ]+ w[i];

    for(int len=2;len<=n;len++)
    {
        for(int l=1;l +len -1<=n;l++)
        {
            int r = l +len -1 ;
            f[l][r] = INF;
            for(int k=l;k<r;k++)
            {
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }

    printf("%d\n",f[1][n]);

    return 0;
}