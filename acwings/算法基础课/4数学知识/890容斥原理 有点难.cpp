//所有质数的并集中的元素的个数
//核心思想就是容斥原理

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 20;


int p[N]; //存储输入的质数


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&p[i]);

    int res = 0;  //记录符合条件的整数的个数
    //开始循环遍历2^m-1个组合情况
    
    for(int i=1;i< 1<<m;i++)
    {
        //要确定每次选了几个集合，以及该组合中元素的个数，奇数个要加上，偶数个要减去
        int t=1,cnt=0;
        
        for(int j=0;j<m;j++)
        {

            if(i >> j&1)
            {
                //这一位被选了，该想中多并入了一个集合
                

                if((LL)t*p[j]>n)
                {
                    t=-1;
                    break;
                }

                t*=p[j];
                cnt ++ ;
            }

        }
        
        if(t!=-1)
        {
            if(cnt%2) res += n/t;
            else res -= n/t;
        }


    }

    cout<<res<<endl;

    return 0;
}
