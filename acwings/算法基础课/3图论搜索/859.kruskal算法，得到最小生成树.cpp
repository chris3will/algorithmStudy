
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010; //沿用并查集的思想，先对边排序，然后看两个点如果不在同一个集合中则可以加入这个集合

int p[N];  //并查集要利用的根数组
int n,m;
struct Edge
{
    int a,b,w;
    bool operator<(const Edge &x)const
    {
        return w<x.w;
    }
}edges[N];

int find(int u)
{
    if(p[u]!=u) p[u] = find(p[u]);  //实现一个路径压缩的过程
    return p[u];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i] = {a,b,c};
    }
    sort(edges, edges+m);

    for(int i=1;i<=n;i++)p[i] = i;
    int weights = 0,cnt=0;
    for(int i=0;i<m;i++)
    {
        //开始挑边
        int a = edges[i].a, b=edges[i].b, w=edges[i].w;
        a= find(a),b=find(b);
        if(a!=b)
        {
            //不在一个集合中，可以加边
            p[a] = b;
            weights +=w;
            cnt++;
        }
    }

    if(cnt<n-1)puts("impossible");
    else printf("%d\n",weights);
    
    return 0;
}
