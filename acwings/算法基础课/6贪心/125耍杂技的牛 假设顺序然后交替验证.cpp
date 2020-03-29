/*
 * @Author: Chris Wang
 * @Date: 2020-03-29 12:41:59
 * @LastEditors: your name
 * @LastEditTime: 2020-03-29 12:42:23
 * @Description: file content
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<limits.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 51000;
PII cows[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int w,s;
        cin>>w>>s;
        cows[i] = {w + s,w};
    }
    sort(cows, cows+n);
    
    int res=-2e9,sum=0;
    for(int i=0;i<n;i++)
    {
        int w = cows[i].second, s = cows[i].first- w; 
        
        res = max(res,sum - s);
        sum+=w;
    }
    cout<<res<<endl;
    
    return 0;
}
