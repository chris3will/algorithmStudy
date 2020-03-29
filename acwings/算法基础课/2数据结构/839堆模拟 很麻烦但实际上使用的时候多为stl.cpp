/*
 * @Author: Chris Wang
 * @Date: 2020-03-29 14:25:34
 * @LastEditors: your name
 * @LastEditTime: 2020-03-29 14:52:42
 * @Description: file content
 */
//https://www.acwing.com/solution/AcWing/content/5541/
//https://www.acwing.com/solution/AcWing/content/5661/
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 1e5+10;
int h[N];  //dump
int ph[N];  //从外部指向堆的内容，存放第k个插入点在堆中对应的下标; pointer heap, 第k个插入到堆数组中的下标的映射
int hp[N];  //存放堆中点的插入顺序; heap pointer， 堆数组中下标到第k个插入的映射
int cur_size ;  //记录当前堆中的数据长度，也意为着最新添加的元素下标

void heap_swap(int u, int v)
{
    //两个参数都是在堆数组中的下标
    //交换与两个下标有关的所有信息
    swap(ph[hp[u]],ph[hp[v]]);
    swap(hp[u],hp[v]);
    swap(h[u],h[v]);
}

void down(int u)
{
    int t =u;
    if(u*2<=cur_size && h[t]>h[2*u])t=2*u;
    if(2*u+1<=cur_size && h[t]>h[2*u+1]) t= 2*u+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    if(u/2>0 && h[u]<h[u/2])
    {
        heap_swap(u,u/2);
        up(u/2);
    }
}

int main()
{
    int n,m=0;
    //m用来记录插入的数的个数，m的意义与cur_size是不同的，cur_size是记录堆中当前数据的多少
    //对应上文m是hp中应该存在的值
    scanf("%d",&n);
    while(n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            //往数组末尾插，然后往上走就可以
            cur_size++;  //记录堆的空间大小
            m++;  //记录第几次插入的
            ph[m] = cur_size;
            hp[cur_size] = m;  // 做一个逆向的映射，堆中数组到其是第几个插入的一个映射
            h[cur_size] = x;
            up(cur_size);  // 从最后一个位置上更新
        } else if (!strcmp(op, "PM"))printf("%d\n", h[1]);  //直接打印最小元素
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1,cur_size);  //把堆末尾元素提上来然后进行全局更新
            cur_size --;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d",&k);   //删除第k个插入的数，这个是通过m在ph中维护的
            k = ph[k];  //找到这个k
            heap_swap(k, cur_size);  //老方法，将其和最后一个位置的数进行交换
            cur_size--;
            down(k),up(k); //最多只会执行一个
        }
        else
        {
            //修改操作
            scanf("%d%d",&k,&x);
            k = ph[k];
            h[k] = x;
            down(k),up(k);
        }

    }
    return 0;
}