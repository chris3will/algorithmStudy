//实属划分，注意mid的数据类型
#include<iostream>
#include<algorithm>

using namespace std;

double n;


int main()
{
    cin>>n;
    double l=-10000,r=10000;  //在这两个中间找一个数满足题意
    
    
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid*mid>=n)r=mid;
        else l=mid;
    }
    printf("%lf",l);

    
   
    
    return 0;
}
