/*
 * @Author: Chris Wang
 * @Date: 2020-04-01 09:33:59
 * @LastEditors: your name
 * @LastEditTime: 2020-04-01 09:34:47
 * @Description: file content
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 200;
int T,R,C;
int n;
int f[N][N];
int w[N][N];

int main()
{
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&R,&C);
        
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
                scanf("%d",&w[i][j]);
        }
        
        f[1][1] = w[1][1];
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
            {
                
                f[i][j] = max(f[i-1][j],f[i][j-1])+w[i][j];  //公共项提出来可以起到一定的优化作用

            }
            
        printf("%d\n",f[R][C]);
    }
    
    
    return 0;
}