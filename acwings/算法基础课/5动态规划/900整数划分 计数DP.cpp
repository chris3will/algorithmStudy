/*
 * @Author: Chris Wang
 * @Date: 2020-03-26 16:25:39
 * @LastEditors: your name
 * @LastEditTime: 2020-03-26 16:26:08
 * @Description: file content
 */
//做这个题，只用考虑可行的方案数量，不需要考虑他们的数据的排列的顺序
//可以采用dp和枚举的思路来进行处理

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int f[N];  //f[i] 表示总体积占用为i的方案的数量，注意属性是数量这就很关键
int n;

int main()
{
    scanf("%d",&n);
    f[0] = 1;//体积为零，只有一个方案，即一个都不选
    
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            f[j] = (f[j] +f[j-i])%MOD;
         }
    
    cout<<f[n]<<endl;
    
    return 0;
}
/*
//做这个题，只用考虑可行的方案数量，不需要考虑他们的数据的排列的顺序
//可以采用dp和枚举的思路来进行处理
//这个有点像脑筋急转弯，

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int f[N][N];  //f[i][j] 表示总和为i且由j个数字构成的方案的数量 答案应为f[n][1] +f[n][2] + f[n][3] +f[n][4] + f[n][n];
int n;

int main()
{
    scanf("%d",&n);
    f[0][0] = 1;  //依然是一个都不选
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j] = (f[i-1][j-1] + f[i-j][j])%MOD;  //第一种情况是说总和为i，由j个数字组成的方案的数量，这一类方案组成数字的最小数为1，那我减去一个，专业所用数字个数少了一个，且总和减小一，但是方案数量和原始情况是一一对应的。
			//第二种情况是说，所有组成该方案的数的最小值大于1，那我全部减去1这样总和就减去了j*1 (因为我这种方案一共有j个数）,通过这样遍历情况就可以做到不重不漏
        }
    }
    
    int res = 0;
    for(int i=1;i<=n;i++)res = (res+f[n][i])%MOD;
    cout<<res<<endl;
    return 0;
    
}


*/