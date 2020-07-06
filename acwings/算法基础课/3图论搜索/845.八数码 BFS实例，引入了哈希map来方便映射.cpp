#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

char g[3][3];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

//活用工具
//注意一个广搜的模板
int bfs(string start)
{
    string end = "12345678x";  //目标串

    unordered_map<string, int> d;  //每个字符串状态对应一个int值
    d[start] = 0; //初始的距离即为0
    queue<string> q;  //每一个状态存进队列
    q.push(start);

    while(!q.empty())
    {
        auto t= q.front();
        q.pop();

        if(t==end)return d[t];  //回传此时距离

        int k =t.find('x');  // 先找到x的位置了
        int x = k/3, y = k%3;
        int distance = d[t];
        for(int i=0;i<4;i++)
        {
            int a = x + dx[i], b= y+dy[i];
            if(a>=0&&a<=2 && b>=0 &&b<=2 )
            {
                swap(t[k],t[3*a+b]);
                if(!d.count(t))
                {
                    //之前没到过这种状态，可以进行迭代，避免环形迭代
                    d[t] = distance + 1;
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
    string input="";
    
    for(int i=0;i<9;i++)
    {
        char x;
        cin>>x;
        input+=x;
    }
    
    cout<<bfs(input)<<endl;


    return 0;
}
