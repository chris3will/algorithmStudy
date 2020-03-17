//组合数II
//用到了快速幂的知识
//用到了求解逆元的知识
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 100010,mod = 1e9+7;

int fact[N],infact[N];  //分别存放阶乘，和逆元的阶乘

int qmi(int a,int b,int mod)
{
    //快速幂函数，必须死记硬背的
    int res = 1;
    while(b)
    {
        if(b&1)res = (LL)res*a%mod;
        a = (LL)a*a%mod;
        b>>=1;
    }
    return res;
}

int main()
{
    fact[0] = infact[0] = 1;  //阶乘的定义
    for(int i=1;i<N;i++)
    {
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i] = (LL)infact[i-1]*qmi(i,mod-2,mod)%mod;  //这一步涉及到求逆元的过程，可以额外考虑一下怎么去处理
    }

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(LL)fact[a]*infact[b]%mod*infact[a-b]%mod);
    }


    return 0;
}