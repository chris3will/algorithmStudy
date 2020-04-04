/*
 * @Author: Chris Wang
 * @Date: 2020-04-04 09:53:16
 * @LastEditors: your name
 * @LastEditTime: 2020-04-04 09:53:31
 * @Description: file content
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
int n;
int c[N],f[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    
    int res = 0 ;
    for(int i=0;i<n;i++)
    {
        f[i] = c[i]; //考虑到数量规模不会爆int
        for(int j=0;j<i;j++)
        {
            if(c[j]<c[i])f[i] = max(f[i],f[j]+c[i]);
        }
        res = max(res, f[i]);
    }
    cout<<res<<endl;
    return 0;
}