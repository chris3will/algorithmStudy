#include"map"
#include"queue"
#include"iostream"
#include"algorithm"
#include"utility"
using namespace std;

template<class T>
class TreeNode
{
	private:
		T element;
		TreeNode<T> *lchild;
		TreeNode<T> *rchild;
		template<class C>
		friend void PreOrder(TreeNode<C> node);
	public:
		TreeNode(T elem):element(elem),lchild(NULL),rchild(NULL){}
		bool AddL(TreeNode<T> &lnew);
		bool AddR(TreeNode<T> &rnew);
};
template<class T>
class wei_in_pair;


template<class T>
class TreeNode_Weight:public TreeNode<T>
{
	friend class wei_in_pair<T>;
	private:
		int weight;
	public:
		TreeNode_Weight(T elem,int wei):TreeNode<T>(elem),weight(wei){}
		TreeNode_Weight* operator+(TreeNode_Weight<T> &elem){
			return new TreeNode_Weight('/0',this->weight+elem->weight);
		}
		int GetWeight() const
		{
			return this->weight;
		}
};

template<class T>
class wei_in_pair
{
	friend bool operator>(wei_in_pair<T> a,wei_in_pair<T> b);
	private:
		pair<int,TreeNode_Weight<T>*> elem;
	public:
		wei_in_pair(TreeNode_Weight<T> &obj){
			elem.first=obj.GetWeight();
			elem.second=&obj;
		}
		TreeNode_Weight<T> * second(){
			return elem.second;
		}
};

template<class T>
bool operator>(wei_in_pari<T> a,wei_in_pair<T> b)
{
	return a.elem.first>b.elem.first;
	
}
template<class T>
priority_queue<wei_in_pairr<T>, vector<wei_in_pair<T>>, greater<wei_in_pair<T>> > pq;


template<class T>
Tree_Weight<T>* buildHuff(priority_queue<wei_in_pairr<T>, vector<wei_in_pair<T>>, greater<wei_in_pair<T>> > pq);

template<class T>
bool TreeNode<T>::AddL(TreeNode<T> &lnew){
	if(this.lchild==NULL)
	{
		this.lchild=lnew;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool TreeNode<T>::AddR(TreeNode<T> &rnew){
	if(this.rchild==NULL)
	{
		this.rchild=rnew;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
Tree_Weight<T>* buildHuff(priority_queue<wei_in_pairr<T>, vector<wei_in_pair<T>>, greater<wei_in_pair<T>> > pq)
{
	Tree_Weight<T> *root,*lchild,rchild;
	if(pq.empty)
	
}

int main()
{
	return 0;
}