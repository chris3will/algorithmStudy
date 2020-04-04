/*
 * @Author: Chris Wang
 * @Date: 2020-04-04 09:58:40
 * @LastEditors: your name
 * @LastEditTime: 2020-04-04 09:59:01
 * @Description: file content
 */
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
    
    cout<<n - res<<endl;  //总人数减去满足题意的最长序列
    
    
    return 0;
}
