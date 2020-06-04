/*
 * @Author: Chris Wang
 * @Date: 2020-03-28 14:30:50
 * @LastEditors: your name
 * @LastEditTime: 2020-05-07 08:41:48
 * @Description: file content
 */
//一道借用小根堆的题目
//用来维护所有组的最右侧端点以起到一种划分的作用

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 1e5+10;

struct Range
{
    int l,r;
    bool operator< (const Range &W)const
    {
        return l<W.l;  //按照左端点排序
    }
}ranges[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges[i]= {a,b};
    }
    sort(ranges,ranges+n);
    
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for(int i=0;i<n;i++)
    {
        //遍历每个情况
        if(heap.empty() || heap.top()>=ranges[i].l)heap.push(ranges[i].r);  //最小的一个左端点也比右端点大
        else{
            int t = heap.top();
            heap.pop();
            heap.push(ranges[i].r);
        }
        
    }
    cout<<heap.size()<<endl;
    
    return 0;
}