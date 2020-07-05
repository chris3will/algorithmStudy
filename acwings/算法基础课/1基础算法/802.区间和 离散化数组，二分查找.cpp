#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;
//把操作村下俩

typedef pair<int, int> PII;


//用vector做映射
const int N = 3e5+10;

int a[N],s[N];

int n,m;  //两个需要输入的值
vector<int> alls;  //所有要离散化的值
vector<PII> add, query;  //把两种操作存储下来


//求离散化的结果
int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid = l + r>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r+1;
}


int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x>>c;  //在下标x的位置加上c
        add.push_back({x,c});

        alls.push_back(x);  //待离散化的数组
    }
    for (int i=0;i<m;i++){

        int l,r;
        cin>>l>>r;
        query.push_back({l,r});

        alls.push_back(l);
        alls.push_back(r);//我们去查询的这些目的下标，也同样需要做映射，才能找到实际位置
    }

    //去重(因为我们要做的是一一映射所以要排序,而且排序的是alls这些会在过程中用到的值
    //先排序
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());  //把所有的重复元素删掉

    //依次去做每一个操作
    //先处理插入
    for(auto item:add){
        int x = find(item.first);
        a[x] += item.second;
    }

    //预处理前缀和

    for(int i=1;i<=alls.size();i++)s[i]=s[i-1]+a[i];

    //处理查询操作
    for(auto item:query){
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }


    return 0;
}
