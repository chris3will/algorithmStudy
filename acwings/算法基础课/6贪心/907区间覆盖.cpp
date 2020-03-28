/*
 * @Author: Chris Wang
 * @Date: 2020-03-28 19:15:53
 * @LastEditors: your name
 * @LastEditTime: 2020-03-28 19:16:07
 * @Description: file content
 */
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int st,ed;
struct Range
{
    int l,r;
    bool operator< (const Range &W)const
    {
        return l<W.l;  //按照左端点排序
    }
}ranges[N];
int n;

int main()
{
    scanf("%d%d",&st,&ed);  //先输入目标线段端点
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ranges[i] = {l,r};
    }
    sort(ranges, ranges+n);
    
    int res = 0;  //需要的区间数量
    bool success = false;  //成功状态
    for(int i=0;i<n;i++)
    {
        int j = i ;
        int r = -2e9;
        while(j<n && ranges[j].l<=st)
        {
            r = max(r,ranges[j].r);
            j++;
        }
        
        if(r<st)
        {
            res = -1;
            break;
        }
        
        res++;
        if(r>=ed)
        {
            success = true;
            break;
        }
        
        st = r;
        
        i = j-1;
    }
    if(!success)puts("-1");
    else printf("%d\n",res);
    return 0;
}