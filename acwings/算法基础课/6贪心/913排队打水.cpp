/*
 * @Author: Chris Wang
 * @Date: 2020-03-29 11:37:53
 * @LastEditors: your name
 * @LastEditTime: 2020-03-29 11:38:38
 * @Description: file content
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
int t[N];
int n;
//target: to find the minmun we need for all the people who need to wait in line for getting the water
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    
    sort(t,t+n);
    LL res;
    for(int i=0;i<n;i++)res+=t[i]*(n-i-1);
    cout<<res<<endl;
    
    return 0;
}
