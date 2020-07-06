#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int path[8];  //记录访问深度此时的节点状态
bool st[8]; //一个针对输入的状态数组

//参数可以代表深度

//关键还是要考虑好dfs的参数到底要用什么
void dfs(int x)
{
    if(x==n){
        //深度数组已经匹配完成可以输出结果
        
        for(int i=0;i<n;i++)cout<<path[i]<<" ";
        puts("");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i]){
            path[x]=i;
            st[i]=1;
            dfs(x+1);
            //恢复现场
            st[i]=0;
            path[x]=0; 
        }
    }
}

//按照深搜的思路去做
int main()
{
    //输入一个整数n，将这些整数排成一排，即进行全排列工作
    cin>>n;
    //已知n小于等于7
    dfs(0);
    
    
    
    
    return 0;
}
