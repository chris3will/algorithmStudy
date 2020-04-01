//1027 方格取数
// 只有两条路线横纵坐标相等的时候，坐标才有可能重合，所以我们用k来表示横纵坐标之和
//  一次迭代表示两条路线而不是从头到尾进行两次遍历
// 时间复杂度
// O(n3)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 15;
int w[N][N];
int f[N+N][N][N];  //表示从(1,1),(1,1)走到(i1,k-1), (i2,k-2)得到的数字加和的最大值。特殊情况及两个坐标横纵坐标相等的时候，权重只能加一次 
int n;

int main()
{
    scanf("%d",&n);
    int a,b,c;
    //初始化输入
    while(cin>>a>>b>>c,a||b||c)w[a][b] = c;
    
    //开始dp
    for(int k=1+1;k<=n+n;k++)
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                int t = w[i1][k-i1];
                if(k-i1!=k-i2)t+=w[i2][k-i2];  //两者不是重合的节点，即可以分别加上
                int &x = f[k][i1][i2];
                x = max(x, f[k-1][i1-1][i2-1]+t);
                x = max(x, f[k-1][i1-1][i2] + t);
                x = max(x, f[k-1][i1][i2-1] +t);
                x = max(x, f[k-1][i1][i2] + t);
            }
            
    printf("%d\n",f[n+n][n][n]);
    
    
    return 0;
}