//虽然和上一题一样都是进行两次上升子序列求解，但是这一题贵在分析出每个点的左右两侧最大值是不相干的才可以

#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

const int N = 1010;
int f1[N];
int f2[N];
int c[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        f1[i] = 1;
        for(int j=1;j<i;j++)
        {
            if(c[j]<c[i])f1[i] = max(f1[i],f1[j]+1);
        }
    }
    for(int i=n;i>=1;i--)
    {
        f2[i]=1;
        for(int j=n;j>i;j--)
        {
            if(c[j]<c[i])f2[i] = max(f2[i],f2[j]+1);
        }
    }
    for(int i=1;i<=n;i++)
        res = max(res,f1[i]+f2[i] - 1); //注意左右两次迭代都算上了最高点，即要减去一次
    
    cout<<res<<endl;
    
    
    return 0;
}