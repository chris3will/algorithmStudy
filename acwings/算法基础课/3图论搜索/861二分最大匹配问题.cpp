//二分匹配问题
//找到能够满足左右一对一匹配的最大匹配对数
//思路就是固定让一遍发起匹配行为，然后找右边
//每次右边只能迭代一次，要满足不会重复迭代右边的对象，我们初始化的时候也只需要有向边即可
//有一个特殊的match数组即可

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510, M = 1e5+10;
int n1,n2,m;
bool st[N];
int match[N];  //用来匹匹配n2的匹配对象

//经典的定义邻接表
int h[N],e[M],ne[M],idx;

void add(int a,int b)
{//在a后接上新的节点，值为b
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int u)
{
    //用来观察这个节点能否找到一个可进行匹配的对象
    //如果可以则总匹配数目就应该增加
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j]==0 || find(match[j]))
            {
                match[j] = u;
                return true;
            }
        }
    }


    return false;
}

int main()
{
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);  //邻接表的必要初始化
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    int res = 0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,0,sizeof st);  //保证对每个点进行查询的时候，右边的查询记录都是空白的
        if(find(i))res++;
    }

    cout<<res<<endl;


    return 0;
}