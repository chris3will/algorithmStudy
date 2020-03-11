#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int v,w;
int c[N],W[N];
int f[N];  //存储动态结果

int n;

int main()
{
    f[0] = 0;  //选第0件商品可获得的最大价值
    scanf("%d%d",&v,&w);
    for(int i=0;i<v;i++)
    {
        scanf("%d%d",&c[i],&W[i]);
    }

    for(int i=0;i<v;i++)
    {
        for(int j=w;j>=c[i];j--)
        {
            f[j] = max(f[j],f[j-c[i]]+W[i]);
        }
    }

    cout<<f[w]<<endl;



    return 0;

}