 #include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 110;
typedef pair<int,int> PII;
int dx[4] = {0,1,0,-1},dy[4]={1,0,-1,0};
int dist[N][N];  // 距离数组
int g[N][N];  //原始数组
int n,m;

int bfs()
{
    queue<PII> que;
    memset(dist,-1,sizeof dist);
    
    que.push({0,0});
    dist[0][0] = 0;
    
    while(!que.empty())
    {
        //队列不为空，则一直迭代
        auto t= que.front();
        que.pop(); //弹出来
        
        for(int i=0;i<4;i++)
        {
            int x = t.first+dx[i],y=t.second+dy[i];
            if(x>=0 && x<n && y>=0 &&y<m &&dist[x][y]==-1 && g[x][y]==0)
            {
                dist[x][y]=dist[t.first][t.second]+1;
                que.push({x,y});
            }
        }
    }
    
    return dist[n-1][m-1];
    
    
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&g[i][j]);
        
    cout<<bfs()<<endl;    
    return 0;
}
