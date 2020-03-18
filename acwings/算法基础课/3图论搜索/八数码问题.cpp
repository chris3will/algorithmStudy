#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};


int bfs(string start)
{
    string end = "12345678x"; //目标串
    unordered_map<string, int> d;
    d[start] = 0;
    queue<string> q;
    q.push(start);

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        if(t==end)return d[t];

        int k = t.find('x');  //
        int x = k/3, y = k%3;
        int distance = d[t];  //先把此时的距离拿出来
        for(int i=0;i<4;i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a>=0 && a<3 && b>=0 && b<3)
            {
                swap(t[k],t[3*a+b]);
                if(!d.count(t))
                {
                    d[t] = distance+1;
                    q.push(t);
                }
                swap(t[k],t[3*a+b]);
            }
        }

    }


    return -1;
}


int main()
{
    string start;
    for(int i=0;i<9;i++)
    {
        char c;
        cin>>c;
        start+=c;
    }
    cout<<bfs(start)<<endl;
    return 0;
}