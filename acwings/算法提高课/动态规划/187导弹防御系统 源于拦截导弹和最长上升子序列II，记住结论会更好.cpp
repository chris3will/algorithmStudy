/*
 * @Author: Chris Wang
 * @Date: 2020-04-04 15:05:41
 * @LastEditors: your name
 * @LastEditTime: 2020-04-04 15:11:16
 * @Description: file content
 * up数组表示所有严格上升子序列的结尾，它本身随下标是非严格单调下降的；down数组表示所有严格下降子序列的结尾，它本身随下标是非严格单调上升的，没有写反。
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int N= 60;
int down[N],up[N];
int c[N];
int n;
int ans;  //记录全局最小值

void dfs(int u,int ud, int dd)
{
    /*
     * u是当前处理导弹的数量，ud是上升子序列的个数，dn是下降子序列的个数
     * 我们要在两者之间选择
    */
    if(ud+dd>=ans)return;  //当前情况已经大于最大值，则直接终止这种情况
    if(u==n)
    {
        ans = min(ans,ud+dd);
        return ;
    }
    
    //情况1,将其放入上升子序列中进行尝试
    int k=0;
    while(k<ud && up[k]>=c[u])k++;  //所有数组的末尾最大值都比我这个大，我必须开一个新的序列；找到一个比这个末尾新数字大的最小值
    //保护现场
    int t = up[k];
    up[k] = c[u];
    if(k<ud)dfs(u+1,ud,dd);
    else dfs(u+1,ud+1,dd);
    up[k] = t;  //恢复现场
    
    k = 0;
    while(k<dd && down[k]<=c[u])k++;
    t=down[k];
    down[k] = c[u];
    if(k<dd)dfs(u+1,ud,dd);
    else dfs(u+1,ud,dd+1);
    down[k] = t;
}

int main()
{
    while(cin>>n,n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        
        ans = n ;  //最差的情况，是每一个导弹自己一个序列
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    
    return 0;
}