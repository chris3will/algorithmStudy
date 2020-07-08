#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int result = v[0];  //先取一段
    for(int i=1;i<v.size();i++)
    {
        result = (result+v[i])/2;
    }
    
    printf("%d\n",result);
    
    return 0;    
}
