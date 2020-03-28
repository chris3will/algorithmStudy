/*
 * @Author: Chris Wang
 * @Date: 2020-03-28 09:39:54
 * @LastEditors: your name
 * @LastEditTime: 2020-03-28 09:40:18
 * @Description: file content
 */
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int n;
struct Range
{
    int l,r;
    bool operator< (const Range &R)const
    {
        return r< R.r;
    }
}ranges[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ranges[i]={a,b};
        }
    sort(ranges,ranges+n);
    
    int cnt = 0, ed = -2e9;  //先把有边界的值取为极小，这样可以保证第一条边被加入
    for(int i=0;i<n;i++)
    {
        //遍历每条边
        if(ranges[i].l>ed)
        {
            cnt++;
            ed = ranges[i].r;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}