/*
 * @Author: Chris Wang
 * @Date: 2020-04-01 09:57:44
 * @LastEditors: your name
 * @LastEditTime: 2020-04-01 09:58:21
 * @Description: file content
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110, INF = 1e9;
int f[N][N];
int w[N][N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&w[i][j]);


    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1)f[i][j] = w[i][j];  //特判左上角的数据
            else
            {
                f[i][j] = INF;  //初始假设是无法到达的,相当于过路费很高
                if(i>1)f[i][j] = min(f[i][j], f[i-1][j]+w[i][j]);
                if(j>1)f[i][j] = min(f[i][j], f[i][j-1]+w[i][j]);
            }
        }
    printf("%d\n",f[n][n]);

    return 0;
}

