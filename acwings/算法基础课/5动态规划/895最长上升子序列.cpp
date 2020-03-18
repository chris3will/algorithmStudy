/*
 * @Author: Chris Wang
 * @Date: 2020-03-18 20:25:21
 * @LastEditors: your name
 * @LastEditTime: 2020-03-18 20:25:35
 * @Description: file content
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N];  //dp状态序列f[i]，从开始位置到i的最长上升子序列长度
int c[N];  //原序列

int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
        
    int res = 0;
    for(int i=0;i<n;i++)
    {
        f[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(c[j]<c[i])
            {
                f[i] = max(f[i],f[j]+1);
            }
        }
        res = max(res,f[i]);
    }
    
    cout<<res<<endl;
    
    return 0;
}