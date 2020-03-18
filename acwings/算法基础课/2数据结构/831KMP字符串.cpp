//KMP算法
//这个模板序列串的下标都从1开始计数
//核心思想，为模板串维护一个next数组
//且每次是用原数组的i去和模板串的j+1的位置去比较
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e4+10, M =1e5+10;

char s[M],p[N];
int ne[N];

int n,m;

int main()
{
    scanf("%d",&n);
    scanf("%s",p+1);
    scanf("%d",&m);
    scanf("%s",s+1);

    ne[1] = 0;  //长度为1的模式串，其最长匹配前后缀长度为0，可以容易得出
    for(int i=2,j=0;i<=n;i++)
    {
        while(j && p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;  //这个匹配的长度也象征着匹配失败的时候，模式串指针需要向前移动 到 的位置
    }

    //for(int i=1;i<=n;i++)cout<<ne[i]<<endl;  这句话主要用来验证构造构造过程是否正确
    //开始正常的匹配过程
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;

        if(j==n)
        {
            printf("%d ",i-n);
        }
    }

    return 0;
}