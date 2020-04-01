#include<iostream>
#include<cstdio>
#include<algorithm>

//一道并查集应用的题目，除了经典的并查集找父节点然后路径压缩操作，只要每次合并的时候，对额外设定的点数数组也进行加和即可
using namespace std;
const int N = 1e5+10;

int p[N];
int d_size[N];  //存放每个集合的点的数量，可以理解为各个连通块中点的数量
int n,m;

int find(int u)
{
    if(p[u]!=u)p[u] = find(p[u]);
    return p[u];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        //每个点的父节点是其本身，每个连通块初始化自己的数量为1
        p[i]=i;
        d_size[i]=1;
    }
    
    while(m--)
    {
        string op;
        cin>>op;
        int a,b;
        
        if(op=="C")
        {
            scanf("%d%d",&a,&b);
            a = find(a),b=find(b);
            if(a!=b)
            {
                d_size[a]+=d_size[b];
                p[b]=a;
            }
        }
        else if(op=="Q1")
        {
            scanf("%d%d",&a,&b);
            a = find(a), b = find(b);
            if(a==b)puts("Yes");
            else puts("No");
            
        }
        else if(op=="Q2")
        {
            scanf("%d",&a);
            printf("%d\n",d_size[find(a)]);
        }
    }
    
    return 0;
}