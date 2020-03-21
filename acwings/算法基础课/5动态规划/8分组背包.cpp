//分组背包尝试
//可以把多重背包看做是一种特殊的分组背包，即每组里面的各种物品有s个，但是你有s+1种决策。在多重背包里得每种物品你都有s+1种数量的决策
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110;
int n,W;  //组数与总体积大小
int f[N];
int v[N],w[N];

int main()
{
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++)
    {
        //输入所有的组
        int s;  //确认该组中有多少个物品
        scanf("%d",&s);
        //由于每个组中的物品只能用一次，我们逆序以确保“i”的不重复
        for(int k=0;k<s;k++)cin>>v[k]>>w[k];
        for(int j=W;j>=0;j--)
        {
            for(int k=0;k<s;k++)
            {
                if(j>=v[k])f[j]=max(f[j],f[j-v[k]]+w[k]);
            }
        }
        
        
    }
    cout<<f[W]<<endl;
    
    return 0;
}