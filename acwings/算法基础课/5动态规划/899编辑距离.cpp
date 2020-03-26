// 编辑距离，即最短编辑距离的应用题

#include<iostream>
#include<cstring>
#include<cstdio>
#include<string.h>

using namespace std;

const int N = 1010, M = 15;
char str[N][M];
int n,m;
int f[N][N];  //状态数组
int edit_distance(char a[], char b[])
{
    int la = strlen(a+1), lb = strlen(b+1); //注意这个取下标的方式

    for(int i=0;i<=lb;i++)f[0][i] = i;  //要插入这么多次
    for(int i=0;i<=la;i++)f[i][0] = i;  //要删除这么多次

    for(int i=1;i<=la;i++)
        for(int j=1;j<=lb;j++)
        {
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
            f[i][j] = min(f[i][j],f[i-1][j-1]+!(a[i]==b[j]));
        }

    return f[la][lb];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",str[i]+1);  //下标仍然要保证从1开始

    while(m--)
    {
        //开始m次询问
        char s[M];
        int limit;
        scanf("%s%d",s+1,&limit);
        int res = 0;
        for(int i=0;i<n;i++)
            if(edit_distance(str[i],s)<=limit)res++;

        printf("%d\n",res);
    }

    return 0;
}