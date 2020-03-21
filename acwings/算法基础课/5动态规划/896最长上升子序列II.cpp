/*
 * @Author: Chris Wang
 * @Date: 2020-03-21 09:55:16
 * @LastEditors: your name
 * @LastEditTime: 2020-03-21 09:55:34
 * @Description: file content
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int n;
int q[N];  //存储各个长度最长子序列的末尾数值
int a[N];  //存储原始数组


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    int len = 0;  //存储最终的长度
    q[0] = -2e9;  //保证能有解答，因为样例中的数据范围是1e9的正负
    for(int i=0;i<n;i++)
    {
        //开始从前往后的遍历
        //对每个a[i]先进行二分
        int l=0,r=len;  //右侧是len，毕竟如果没有一个已知的值，你的右侧边界多大都是无效的
        while(l<r)
        {
            int mid = l+r+1>>1;
            if(q[mid]<a[i])l=mid;
            else r=mid-1;
        }
        q[r+1]=a[i];
        len = max(len,r+1);
    }
    cout<<len<<endl;
    
    return 0;
}