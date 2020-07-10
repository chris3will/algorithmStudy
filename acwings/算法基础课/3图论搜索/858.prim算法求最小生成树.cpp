//prim算法，。更新稠密图
//最小生成树，采用加入点的策略
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, INF= 0x3f3f3f3f;
int dist[N];
bool st[N];  //是否被加入集合
int g[N][N];
int n,m;

int prim()
{
    int res = 0;  //当前数的权重总集合
    memset(dist,INF,sizeof dist);  // 先把每个点都设定为不可到达

    for(int i=0;i<n;i++)
    {
        //一共要扩展n次，以确保把每个点都加入
        int t=-1;  //找到该次需要加入的下标
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[j]<dist[t]))
                t= j;
        }

        if(i&&dist[t]==INF)return INF;  //这已经不是第一次选点，但是这次的距离却无法到达，说明存在不连通的点，无法得到生成树
        if(i)res += dist[t];
        st[t] = true;  //该点以后不能被访问了
        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j],g[t][j]);
        }

        
    }

    return res;
}


int main()
{
    scanf("%d%d",&n,&m);
    memset(g,INF,sizeof g);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a][b] = g[b][a] = min(g[a][b],w);
    }
    
    int t= prim();
    if(t==INF)puts("impossible");
    else printf("%d\n",t);




}
