//多重背包学习

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 110;
int n,W;
int v[N],w[N],s[N];
int f[N];
int main()
{
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
        for(int j=W;j>=v[i];j--)
        {
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++)
            {
                f[j] = max(f[j],f[j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[W]<<endl;
    return 0;


}