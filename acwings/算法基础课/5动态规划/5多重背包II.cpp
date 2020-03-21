//多重背包问题II
//数据规模更大了，必须要对背包的选择方式进行log处理，以避免线性处理的高复杂度

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;
const int N = 2010;

 int n,W;
 int v[N],w[N],s[N];
 int f[N];

 struct good
 {
     int v,w;
 };

 int main()
 {
     vector<good> Goods;
     scanf("%d%d",&n,&W);
     for(int i=0;i<n;i++)
     {
         //先将原有的选择做一个拆解工作
         scanf("%d%d%d",&v[i],&w[i],&s[i]);
         for(int k=1;k<=s[i];k*=2)
         {
             s[i]-=k;
             Goods.push_back({k*v[i],k*w[i]});
         }

         if(s[i]>0)Goods.push_back({s[i]*v[i],s[i]*w[i]});
     }

     for(auto good:Goods)
     {
         for(int j=W;j>=good.v;j--)
         {
             f[j] = max(f[j],f[j-good.v]+good.w);
         }
     }

     cout<<f[W]<<endl;
     return 0;
 }
