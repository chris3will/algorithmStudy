//贝尔曼福特算法，引入松弛操作思想
//这个算法存边的方式随便存即可，只要能保证遍历到边即可
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510,M = 1e4+10;

struct Edge
{
    int a,b,c;  //一个边结构体拥有三个组成
}edges[N];

int m,n,k;

int dist[N],backup[N];

void bellman()
{
    memset(dist,0x3f3f3f3f, sizeof dist);  //先都初始化为不可抵达
    dist[1] = 0;

    for(int i=0;i<k;i++)
    {
        //最多可走k条边
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++)
        {
            //为每条边进行迭代
            int a= edges[j].a,b =edges[j].b, c=edges[j].c;

            dist[b] = min(dist[b],backup[a]+c);
        }
    }
    //结束之后，dist也同时更新完毕
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int x,y,z;
    
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edges[i]={x,y,z};
    }
    bellman();
    
    if(dist[n]>0x3f3f3f3f/2)puts("impossible");
    else printf("%d\n",dist[n]);
    
    
    return 0;

}
