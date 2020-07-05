//归并排序

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int a[N];
int tmp[N];
int n,m;

void merge_sort(int q[],int l,int r){
    if(l>=r)return ;

    //先找一个中间节点，
    int k = l+r>>1;
    merge_sort(q,l,k);
    merge_sort(q,k+1,r);

    //然后将排序后的结果放到临时数组中
    int i=l,j=k+1,p=0;
    while(i<=k&&j<=r){
        if(q[i]<q[j])tmp[p++]=q[i++];
        else tmp[p++]=q[j++];
    }
    while(i<=k)tmp[p++]=q[i++];
    while(j<=r)tmp[p++]=q[j++];

    for(int z=l,t=0;z<=r;z++,t++)q[z]=tmp[t];

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";



    return 0;
}
