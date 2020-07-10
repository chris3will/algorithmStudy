//floyd算法，三重循环
//先循环k，即迭代的次数
//然后再遍历两个维度即可

#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;
const int N = 210;
const int INF = 1e9;
int n,m,Q;
int d[N][N];

void floyd()
{
    //对多源最短路的路径进行更新操作
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}


int main()
{
    scanf("%d%d%d",&n,&m,&Q);

    //先初始化一下这个图
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;

    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y] = min(d[x][y],z);
    }

    floyd();

    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        if(d[x][y]>INF/2)puts("impossible");
        else printf("%d\n",d[x][y]);
    }

    return 0;
}
