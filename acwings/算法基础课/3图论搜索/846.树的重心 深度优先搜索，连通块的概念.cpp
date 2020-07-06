#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+10, M = 2*N;

int h[N],e[M],ne[M],idx=0;
int n;
bool st[N];

int ans = N;

void add(int a,int b)
{
    e[idx] = b;  //该idx节点快分配的数据值为k
    ne[idx] = h[a];  //该新节点块指向的位置为原来x头部节点指向的位置
    h[a] = idx++; //给他分配一个新的标号
}

//以u为根的子树中点的数量
int dfs(int u)
{
    st[u] = true;  //之后不能再被访问

    int sum = 1;  //记录当前这个子树的规模，头就算一个点
    int res = 0;  //把这个头部点删除之后，每一个连通块中点数的最大值

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j = e[i];  //把这个节点的值取出来
        
        if(!st[j])
        {
            int s = dfs(j);  //求出以j为根的子树中点的数量
            res  = max(res, s);
            sum+=s;

        }
    }

    res = max(res, n - sum);

    ans = min(res,ans);

    return sum;
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);add(b,a);
        }
    
    dfs(1);
    
    cout<<ans<<endl;
    
    
    return 0;
}
