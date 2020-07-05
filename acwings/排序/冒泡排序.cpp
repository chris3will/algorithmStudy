//冒泡排序
//每次排序一个
//排序迭代的次数为长度减一
#include<iostream>

using namespace std;

const int N = 1e5+10;
int n;
int a[N];

int main()
{

    int temp;
//    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++)
    {
        //总共要迭代的次数为数字个数减一
        int isChange = 0;  //是否更改的标记
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1] = temp;
                isChange=1;
            }
        }
        if(isChange==0)break;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


    return 0;
}
