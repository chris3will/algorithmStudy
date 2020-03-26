//最长公共子序列
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

const int N = 1010;
char a[N],b[N];
int f[N][N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    scanf("%s",b+1);

    f[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //考虑到f[i][j]唯一的更新路径，我们可以这样做
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }

    return 0;
}