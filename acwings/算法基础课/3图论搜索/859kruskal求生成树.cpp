/*
 * @Author: Chris Wang
 * @Date: 2020-03-26 22:25:46
 * @LastEditors: your name
 * @LastEditTime: 2020-03-26 22:26:07
 * @Description: 这个有点迷
 */
//看大佬写题就和看连续剧一样

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010;

int p[N];
int n,m;
struct Edge
{
    int a,b,W;
    bool operator<(const Edge &x)const
    {
        return W < x.W;
    }
}edges[N];

int find(int u)
{
    if(p[u]!=u)p[u] = find(p[u]);
    return p[u];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i]={a,b,c};
    }
    sort(edges,edges+m);
    
    for(int i=1;i<=n;i++)p[i]=i;
    int weights=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a, b= edges[i].b,c=edges[i].W;
        
        a= find(a),b=find(b);  //并查集对根的要求真的很严格
        
        if(a!=b)
        {
            p[a]=b;
            weights+=c;
            cnt++;
        }
    }
    if(cnt<n-1)puts("impossible");
    else printf("%d\n",weights);
    
    
    return 0;
}