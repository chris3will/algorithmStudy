/*
 * @Author: Chris Wang
 * @Date: 2020-03-27 15:15:19
 * @LastEditors: your name
 * @LastEditTime: 2020-03-27 15:16:20
 * @Description: file content
 */
//这是采用线性直接dp的思路

#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
const int N = 1e5+10;
int f[N]; //前i个店铺，所能获得的最大利润
int n;
int w[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        f[0] = 0;
        f[1] = w[1];
        for(int i=2;i<=n;i++)
        {
            f[i] = max(f[i-2]+w[i],f[i-1]);
        }
        cout<<f[n]<<endl;
    }
    
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1e5+10, INF = 1e9;
int n;
int f[N][2];
int w[N];

//采用状态机的方式来推断每一个点的的选择
int main()
{   
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        f[0][0]= 0, f[0][1] = -INF;
        
        for(int i=1;i<=n;i++)
        {
            f[i][0] = max(f[i-1][1],f[i-1][0]);
            f[i][1] = f[i-1][0] + w[i];
        }
        
        printf("%d\n",max(f[n][0],f[n][1]));
    }
    
    
    return 0;
}

*/