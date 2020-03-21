//滑动窗口的模仿学习

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 1e6+10;

int a[N],q[N];  //a是原数组，q中存储的是下标，它是一个存下标的队列
int h,t;  //实现队列的两个指针
int n,k;

//目标，确定每个窗口的最大值和最小值
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    h=0,t = -1;
    for(int i=0;i<n;i++)
    {
        //从前向后进行窗口滑动,每次输出窗口中存在的最大元素
        //因为每次都在移动，总有值会被处理，要么老值被删除，要么新值加入，对头出队
        if(h<=t &&q[h] < i - k + 1)h++;  //队列为空或者队列长度已达到上限
        while(h<=t && a[q[t]]>=a[i])t--;  //保证每次在队尾的都是最大的
        q[++t] = i;  //存储的是标号

        if(i>=k-1)printf("%d ",a[q[h]]);
    }
    puts("");

    h=0,t=-1;  //分别定义队头和队尾元素 h<=t是保证队列中有元素的基本条件
    for(int i =0;i<n;i++)
    {
        if(h<=t && q[h] < i - k + 1)h++;
        while(h<=t && a[q[t]]<=a[i])t--;
        q[++t] = i;

        if(i>=k-1)printf("%d ",a[q[i]]);
    }
    puts("");


    return 0;
}