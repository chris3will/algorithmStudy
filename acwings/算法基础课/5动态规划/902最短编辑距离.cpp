//902 https://www.acwing.com/problem/content/904/
/*
 * 一个经典的动态规划题目
 * 这是一个两维的动态dp
 * 状态转移会涉及三种情况，即删除，插入，或者替换
 * 需要为初始化操作进行必要的考虑
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;  //注意这个数据规模，n^2的复杂度是ok的
char a[N],b[N];
int f[N][N]; //f[i][j]表示从a数组从1~i匹配b数组从1~j所需要进行的操作次数的最小值
int n,m;
int main()
{
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);

    //进行必要的初始化工作
    for(int i=0;i<=m;i++)f[0][i] = i;  //对于插入操作
    for(int i=0;i<=n;i++)f[i][0] = i;  //对于删除操作

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j] = min(f[i][j-1]+1,f[i-1][j]+1);
            if(a[i]==b[j])f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1] + 1);
        }
    
    cout<<f[n][m]<<endl;
    return 0;
}