//用第二个方法求解一下
//即用最经典的dfs进行尝试

#include<iostream>
#include<algorithm>


using namespace std;


const int N = 20; //考虑到对角线规模是行列的2n-1倍，所以数组规模要扩大
char g[N][N];
bool row[N],col[N],ud[N],d[N];

int n;

void dfs(int x,int y,int s)
{
    //可以理解为当前正在抉择的x，y和当前已经放置的皇后的个数

    if(y==n) {
        y = 0, x++;
    }
    if(x==n){
        if(s==n)
        {
        for(int i=0;i<n;i++)puts(g[i]);
        puts("");
        
        }
        return ;
    }
    //开始正常的处理棋子的操作
    //不放棋子
    dfs(x,y+1,s);

    //放棋子
    //先判断这个位置能不能放
    if(!row[x]&&!col[y]&&!ud[x+y]&&!d[n-x+y])
    {
        //只有不曾放过棋子，这里才可以放
        g[x][y]='Q';
        row[x]=col[y]=ud[x+y]=d[n-x+y]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=ud[x+y]=d[n-x+y]=false;
        g[x][y]='.';
    }


}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            g[i][j]='.';
    }
    dfs(0,0,0);

    return 0;
}
