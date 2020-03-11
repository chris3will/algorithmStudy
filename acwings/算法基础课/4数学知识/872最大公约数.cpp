//欧几里得算法，最大公约数

#include<iostream>
#include<cstdio>

using namespace std;


int gcd(int a,int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cout<<gcd(a,b)<<endl;

    }
    return 0;
}