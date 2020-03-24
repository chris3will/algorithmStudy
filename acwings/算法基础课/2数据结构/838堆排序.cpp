#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int h[N]; //原始输入
int c[N];  //堆
int n,m;

void down(int u)
{
    int t = u;
    if(2*u<=n && c[2*u]<c[t])t=2*u;
    if(2*u+1<=n && c[2*u+1]<c[t])t=2*u+1;  //找到那个最小的位置
    if(t!=u)
    {
        //如果存在更新，则修改值
        swap(c[u],c[t]);
        down(t);  //向下继续更新吧
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=n/2;i;i--)
    {
        down(i);
    }
    

    while(m--)
    {
        printf("%d ",c[1]);
        c[1]=c[n--];
        down(1);
        
    }
    //cout<<c[1]<<endl;
    return 0;
}