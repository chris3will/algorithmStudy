#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;
int c[N],f[N];
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&c[i]);
        
        int res=0;  //定义一个全局的最大长度
        //正向求最长上升子序列
        for(int i=1;i<=n;i++)
        {
            f[i] = 1;  //一个数自己就是长度为1的上升子序列
            for(int j=1;j<i;j++)
                if(c[j]<c[i])f[i] = max(f[i],f[j]+1);
            
            res = max(res, f[i]);
        }
        
        //memset(f,0,sizeof f);  //注意初始化
        //反向求最长上升子序列
        for(int i=n;i>=1;i--)
        {
            f[i] = 1;
            for(int j=n;j>i;j--)
                if(c[j]<c[i])f[i] = max(f[i], f[j] + 1);
            res = max(res,f[i]);
        }
       
        
        cout<<res<<endl;
    }
    
    return 0;
    
}