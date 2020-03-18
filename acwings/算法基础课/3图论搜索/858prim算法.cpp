//现场写一个prim算法
//满足最小生成树的使用需求
//稠密图，我采用邻接矩阵的方式进行处理
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int dist[N];
bool st[N];
int g[N][N];
int n,m;

int prim()
{
    int res = 0;
    memset(dist,INF,sizeof dist);
    
    for(int i=0;i<n;i++)
    {
        //一共要扩展n次，把每个节点都加入
        int t = -1;  //为了确认下标
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1||dist[j]<dist[t]))
                t=j;
        }
        
        if(i&&dist[t]==INF)return INF;  //不是第一次选点，但这次的距离却无法到达，说明存在不连通的点，无法构成生成树
        if(i)res+=dist[t];  //将生成树的权值进行扩大
        
        st[t] = true;  //以后无法访问
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
    
    int t = prim();
    if(t==INF)puts("impossible");
    else printf("%d\n",t);
    
    
    return 0;
}