/*
 * @Author: Chris Wang
 * @Date: 2020-03-12 20:30:16
 * @LastEditors: your name
 * @LastEditTime: 2020-03-29 15:20:44
 * @Description: file content
 */


#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 20;
bool col[N],row[N],d[N],ud[N];
char g[N][N],backup[N][N];
int n;

//输出所有满足题意的阵列
void dfs(int u)
{
    //当前行为u
    if(u>n)return; 
    if(u==n)
    {
        for(int i=0;i<n;i++)printf("%s\n",g[i]);
        puts("");
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        if(!col[i]&&!d[u+i]&&!ud[i-u+n])
        {
            g[u][i]='Q';
            col[i]= d[u+i] = ud[i-u+n]= true;
            dfs(u+1);
            col[i]= d[u+i] = ud[i-u+n]= false;
            g[u][i]='.';
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)g[i][j] = '.';
    dfs(0);
    
    return 0;
}

