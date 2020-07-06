//一个BFS搜索的应用

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int N =1e5+10,M=2*N;

int n,m;
int h[N],e[N],ne[N],idx;

int dist[N];
bool st[N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    memset(dist,-1,sizeof dist);
    
    dist[1] = 0; //从1号到1号点的距离为0
    queue<int> q;
    
    q.push(1); //把起点装入
    st[1] = true;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        for(int x=h[t];x!=-1;x=ne[x])
        {
            int j = e[x];
            if(dist[j]==-1)
            {
                //之前没访问过
                dist[j] = dist[t] +1;
                if(j==n)return dist[j];
                q.push(j);
            }
        }
    }
    
    return -1;


}

int main()
{
    cin>>n>>m;

    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    cout<<bfs()<<endl;

    return 0;
}
