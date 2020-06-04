#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
const int N = 3010;//数组长度
int f[N][N];
int a[N],b[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    
for (int i = 1; i <= n; i ++ )
    {
        int maxv = 1;  //相当于优化了一重循环
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);

            if (b[j] < a[i])
                maxv = max(maxv, f[i - 1][j] + 1);
        }
    }

    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
    
}
