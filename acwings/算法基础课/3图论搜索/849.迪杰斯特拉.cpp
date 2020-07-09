#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 510;

int n,m;

int g[N][N];
int dist[N];
bool st[N];

int dji()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i=0;i<n;i++)
    {
        //需要进行这么多次迭代
        int t = -1;//每次找一个需要更新的下界
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[j]<dist[t]))
                t = j;
        }
        //找到了需要更新的下标
        st[t] = true;  //将其进行固定
        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];

}


int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y] = min(g[x][y],z);


    }
    cout<<dji()<<endl;

    return 0;
}
