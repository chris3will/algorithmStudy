//基于容斥原理和线性筛法
//顺带着在过程中把答案都求出来

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;


const int N = 1e6 + 10;
int primes[N],cnt;
bool st[N];

int phi[N];

int get_eulars(int n)
{

    phi[1] = 1;//跟着定义走
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[i*primes[j]] = true;
            if(i%primes[j]==0)
            {
                phi[i*primes[j]] = phi[i]*primes[j];
                break;
            }else
            {
                phi[i*primes[j]] = phi[i]*(primes[j]-1);
            }
        }
    }


}

int main()
{
    int n;
    scanf("%d",&n);
    LL res = 0;
    get_eulars(n);
    for(int j=1;j<=n;j++)
        res+=phi[j];

    cout<<res<<endl;

    return 0;
}