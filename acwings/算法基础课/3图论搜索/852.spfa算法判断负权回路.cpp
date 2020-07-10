//spfa算法 只有我更新过了，我才能让别人也更新
//不断把东西引入一个优先队列中，
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 150010;
typedef pair<int,int> PII;
int e[N],ne[N],w[N],h[N],idx;
int n,m;
int dist[N];
int cnt[N];
bool st[N];

void add(int a ,int b,int wei)
{
    e[idx] = b,ne[idx]=h[a],w[idx] = wei,h[a]=idx++;
}

int spfa()
{

    queue<int> q; //所有待更新的点
    for(int i=1;i<=n;i++)
    {
    //因为从1出发可能无法到达，所以要把所有点都放到队列中
        st[i] = true;
        q.push(i);
    }

    q.push(1);
    st[1]  = true;  //存重复的点没有意义

    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;  //这个点不在队列，
        //更新临边

        for(int i=h[t];~i;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j] = dist[t]+w[i];
                //只要这个经过的边数够了，则可说明问题
                cnt[j]  =  cnt[t]+1;
                if(cnt[j]>=n)return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}


int main()
{

    cin>>n>>m;
    memset(h,-1,sizeof h);
    int x,y,z;
    while(m--)
    {

        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    if(spfa())puts("Yes");
    else puts("No");
    return 0;
}
