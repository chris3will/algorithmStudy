#include<iostream>
#include<cstdio>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode{
    int v;
    Tree Left,Right;
    int flag;  //用来判别是否相同额标记
};
Tree NewNode(int V){
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}
Tree Insert(Tree T, int V)
{
    if(!T)T = NewNode(V);
    else{
        if(V >T->v){
            T->Right = Insert(T->Right, V);
        }else{
            T->Left = Insert(T->Left, V);
        }
    }
    return T;
}

int check(Tree T, int V){
    if(T->flag){
        if(V<T->v) return check(T->Left, V);
        else if(V>T->v) return check(T->Right, V);
        else return 0;
    }else{
        if(V==T->v){
            T->flag = 1;  //找到了，将其进行标记，之后的搜索可以继续往下判定
            return 1;
        }
        else return 0;
    }
}


Tree MakeTree(int N){
    Tree T;
    int i,V;

    scanf("%d",&V);
    T = NewNode(V); //先建一个头结点
    for(i=1;i<N;i++){
        scanf("%d",&V);
        T = Insert(T,V);
    }

    return T;

}

int Judge(Tree T, int N)
{//接下来读入N个数去和已经建立好的树去比较
    //直接相当于边读边判断
    int i, V, flag =0;
    //flag 0 代表目前两个树是一致的，1代表两个树已经是不一致的了


    scanf("%d",&V);
    if(V!=T->v) flag = 1;
    else T->flag = 1;

    for(int i=1;i<N;i++)
    {
        scanf("%d",&V);
        if((!flag)&&(!check(T,V)))flag = 1;
    }
    if(flag)return 0;
    else return 1;
}

void ResetT(Tree T) //清除T中各个结点的flag标记
{
    if(T->Left) ResetT(T->Left);
    if(T->Right) ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T)  //释放T的空间
{
    if(T->Left)FreeTree(T->Left);
    if(T->Right)FreeTree(T->Right);
    free(T);
}

int main()
{
    int N,L,i;
    Tree T;

    scanf("%d",&N);
    while(N)
    {
        scanf("%d",&L);
        T = MakeTree(N);  //先把这棵树建立起来
        for(i=0;i<L;i++){
            if(Judge(T,N))printf("Yes\n");
            else printf("No\n");
            ResetT(T); //清除T中的标记flag
        }
        FreeTree(T);
        scanf("%d",&N);

    }
    return 0;


}
