#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int a[N];
int n,q,k;

int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    //已经是排好序的了，开始操作
    while(q--){
        scanf("%d",&k);
        int l=0,r=n-1;
        while(l<r)
        {
            //先二分出那个左侧的k值
            int mid = l + r >>1;  //取中点
            if(a[mid]>=k)r = mid;
            else l = mid+1;
        }
        
        if(a[l]==k){
            //找到了左端点，继续找右端点
            cout<<l<<" ";
            r = n-1;
            while(l<r)
            {
                int mid = l + r + 1>>1;
                if(a[mid]<=k)l= mid;
                else r = mid-1;
            }
            
            cout<<l<<endl;
            
        }else{
            
            
            cout<<"-1 -1"<<endl;
        }
        
    
    }
    
    return 0;
}
