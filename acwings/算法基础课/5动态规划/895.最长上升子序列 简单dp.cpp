#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;

const int N = 1010;

int c[N];
int f[N]; //每个位置及其之前的最长上升子序列长度
int n;

int res=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    
    for(int i=0;i<n;i++)
    {
        f[i]=1;
        for(int j=0;j<i;j++)
        {
            if(c[j]<c[i])f[i] = max(f[i],f[j]+1); 
        }
        res = max(res,f[i]);
    }
    
    cout<<res<<endl;
    
    
    return 0;
}
