#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 20;

int n,m;
int p[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>p[i];  //输入所有的质数

    int res = 0; //表示答案，满足条件的整数的个数
    for(int i=1;i< 1<<m; i++)  //排除都不选的情况
    {
        int t = 1, cnt = 0;  // t 当前所有质数的乘积，cnt代表当前这个选法中包含几个集合
        for(int j=0;j<m;j++)
            if(i >> j & 1)
            {//我们选了这个集合
                cnt ++ ;
                if((LL)t*p[j]>n)
                {//如果范围过大，我们就不管了，大于了n
                    t=-1;
                    break;
                }
                t *= p[j];
            }

        if( t!=-1)
        { //这些质数的乘积是 <= n 的
            if(cnt%2)res += n/t;  //奇数就加上
            else res -=n/t; //偶数减去
        }
    }

    cout<<res<<endl;

    return 0;
}

