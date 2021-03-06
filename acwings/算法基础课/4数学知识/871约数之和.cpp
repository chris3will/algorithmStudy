
// 求所有约数的个数
// 注意我们分解的还是质因子
// 核心思想还是算数基本定理
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;

LL res=1;

int main()
{
    int n;
    scanf("%d",&n);
    unordered_map<int,int> primes;
    while(n--)
    {
        int a;
        scanf("%d",&a);
        for(int i=2;i*i<=a;i++)
        {
            while(a%i==0)
            {
                a /= i;
                primes[i]++;
            }
        }
        if(a>1)primes[a]++;
    }

    for(auto prime:primes)
    {
        //已经把所有约数的底数和指数得到
        int p = prime.first,ind=prime.second;
        LL t=1;
        while(ind--)t=(t*p+1)%mod;
        res = res * t %mod;
    }
    cout<<res<<endl;
    return 0;






}
