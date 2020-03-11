// 线性筛法筛选质数
#include<iostream>
#include<cstdio>

using namespace std;
const int N = 1e6+10;

int primes[N],cnt;
int st[N];

void prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]*i<=n;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    prime(n);
    int len=0;
    while(primes[len])len++;
    cout<<cnt<<endl;

    return 0;
}