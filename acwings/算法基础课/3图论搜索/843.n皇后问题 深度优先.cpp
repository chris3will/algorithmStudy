#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 20;
bool col[N],row[N],d[N],ud[N];
char g[N][N],backup[N][N];

int n;


void dfs(int u)
{
    //当前行为u的记录，可以理解为深度，也可以理解为当前已放置棋子的个数
    if(u>n)return;
    if(u==n)
    {
        for(int i=0;i<n;i++)printf("%s\n",g[i]);
        puts("");
        return ;
    }

    //对棋盘开始遍历
    //此时可以理解为按列进行遍历，或者说，按照列进行扫描。
    for(int i=0;i<n;i++)
    {
        if(!col[i]&&!d[u+i]&&!ud[i-u+n])
        {
            g[u][i] = 'Q';
            col[i]=d[u+i]=ud[i-u+n] = true;
            dfs(u+1);
            col[i]=d[u+i] = ud[i-u+n] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)g[i][j] = '.';

     dfs(0);  //从第0开始放
     return 0;
}
