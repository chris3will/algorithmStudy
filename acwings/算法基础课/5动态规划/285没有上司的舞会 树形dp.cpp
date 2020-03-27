/*
 * @Author: Chris Wang
 * @Date: 2020-03-27 11:06:59
 * @LastEditors: your name
 * @LastEditTime: 2020-03-27 11:07:15
 * @Description: file content
 */
/*
 * 没有上司的舞会
 * 树形dp问题
 * 深度搜索
 * 关键是找到根部
 * 也要用dp分析来好好看看各种可能的情况
 * f[i][j]的含义，以i为根节点，j=0代表不选此节点，j=1代表选此节点，此时的最大高兴值为多少
 * 虽然H可能为负数，但是我们可以选也可以不选，所以我们只需要把f初始化为0即可满足题意
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 6010;
int w[N];  //每个节点的欢乐值
int f[N][2];  //状态数组
bool st[N];  //用来记录这个节点是不是头结点
int h[N],e[N],ne[N],idx;
int n;

void add(int a, int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    //从根节点进行更新遍历
    f[u][0] = 0;
    f[u][1] = w[u];
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];  //先把与他相邻的点拉出来
        dfs(j);  //即完成了堆f[j]的更新
        f[u][0] += max(f[j][0],f[j][1]);
        f[u][1] += f[j][0];  //只能不选这个子节点
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);

    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a);
        st[a] = true;  //b是a的根节点，我们要找到的是哪个点没有根节点
    }

    int root = 1;//默认一个为根节点的编号
    while(st[root])root++;
    //至此，得到了一个没有根节点的节点编号，即为root
    dfs(root);
    printf("%d\n",max(f[root][0],f[root][1]));

    return 0;
}