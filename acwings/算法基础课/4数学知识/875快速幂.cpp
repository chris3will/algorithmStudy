//快速幂

#include<iostream>
#include<cstdio>

using namespace std;
typedef long long LL;

int qmi(int a,int b,int c)
{
    int res = 1;
    while(b)
    {
        if(b&1)res=(LL)res*a%c;
        b=b>>1;
        a=(LL)a*a%c;  //注意，这里也要记得取模
    }

    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cout<<qmi(a,b,c)<<endl;
    }


    return 0;
}