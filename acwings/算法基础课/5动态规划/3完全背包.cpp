#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//可以无限次的拿
const int N = 1010;
int f[N];
int n,W;
int v[N],w[N];

int main()
{
    f[0] = 0;
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=v[i];j<=W;j++)
        {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }

    }
    cout<<f[W]<<endl;

    return 0;
}