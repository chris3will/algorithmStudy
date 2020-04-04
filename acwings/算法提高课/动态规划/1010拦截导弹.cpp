/*
 * @Author: Chris Wang
 * @Date: 2020-04-04 11:23:37
 * @LastEditors: your name
 * @LastEditTime: 2020-04-04 11:23:55
 * @Description: file content
 */
//每次发射的炮弹自身就是一个高度区间了
//和最长上升子序列II的代码很类似，但是逻辑上完全不同
//贪心的证明思路用替代法进行，但是考场上想想出来真的是要看个人经验了
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
int n;
int p[N];
int f[N],g[N];

int main()
{
    while(cin>>p[n])n++;
    
    int res = 0;
    for(int i=0;i<n;i++)
    {
        f[i] = 1;
        for(int j=0;j<i;j++)
            if(p[j]>=p[i])f[i] = max(f[i],f[j]+1);
            
        res = max(res,f[i]);
    }
    cout<<res<<endl;
    
    //我们求得毕竟还是一个非递增序列
    int cnt = 0;  //我们开的序列的个数，刚开始一个炮弹也没有，也就没有相应的炮弹被加入
    //g数组存了每个序列的最后一个炮弹的高度
    for(int i=0;i<n;i++)
    {
        //遍历每一个炮弹
        int k = 0;
        while(k<cnt && g[k]<p[i])k++; //都放不下，我就开一个新的序列;因为高度是递减的
        g[k] = p[i];
        if(k>=cnt)cnt++;
    }
    cout<<cnt<<endl;
    
    
    return 0;
}