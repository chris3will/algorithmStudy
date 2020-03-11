// 尝试除法求约数
// 一定要先判断时间复杂度，条件允许我们才能这样logn地方式遍历

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100;

vector<int> get_dividers(int a)
{
    vector<int> res;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            res.push_back(i);
            if(i!=a/i)res.push_back(a/i);  //避免平方的情况
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        auto res = get_dividers(a);
        for(auto t:res)cout<<t<<" ";
        cout<<endl;
    }

    return 0;
}