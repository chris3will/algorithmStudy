// 欧拉函数

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        int res = a; //存储欧拉函数的结果 1~N中与N互质的数的个数

        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                res = res / i * (i - 1);
                while(a%i==0)a/=i;  //把每个质数搜刮干净
            }
        }
        if(a>1)res = res / a* (a-1);

        cout<<res<<endl;
    }

    return 0;
}