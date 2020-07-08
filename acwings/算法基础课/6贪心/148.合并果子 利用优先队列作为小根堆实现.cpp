#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n;
int main()
{
    cin>>n;
    priority_queue<int, vector<int>, greater<int> > heap;
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        heap.push(c);
    }
    
    int result = 0;
    while(heap.size()>1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        result += (a+b);
        heap.push(a+b);

    }
    cout<<result<<endl;
    
    
    return 0;
}
