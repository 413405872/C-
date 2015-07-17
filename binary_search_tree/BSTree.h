#include<iostream>
using namespace std;

template<class T> class BSTree;

//树的结点模型，有左右孩子还有父亲
template<class T>
class TreeNode{
	friend class BSTree<T> ;
public:
	TreeNode(){}
	TreeNode(T d, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL, TreeNode<T>* p = NULL)
		: data(d), left(l), right(r), parent(p)
	{}
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;
};

template<class T>
class BSTree
{
public:
	BSTree():m_root(NULL){}
	BSTree(const BSTree &rhs);
	const BSTree & operator=(const BSTree & rhs);
	~BSTree();

	const T &findmin() const;
	const T &findmax() const;
	bool contains(const T &x) const;
	void makeEmpty();
	void insert(const T& x);
	void remove(const T& x);s

	void PreOrder();
	void InOrder();
	void PostOrder();
	void depth_rf();//先根深度遍历
	void depth_rm();//中根深度遍历
	void width_fs(); //层次遍历
private:
	TreeNode<T> *m_root;
	void insert(const T& x, TreeNode<T>* &t);
	void remove(const T& x, TreeNode<T>* &t);
	TreeNode<T>* findmin(TreeNode<T>* t) const;
	TreeNode<T>* findmax(TreeNode<T>* t) const;
	bool contains(const T& x, const TreeNode<T>* t) const;
	TreeNode<T>* clone(TreeNode<T> *t) const;
	void makeEmpty(TreeNode<T>* &t);//这个你得注意了你要删除肯定要彻底删除，不能只是删除它的副本，所以要* &
	void printTreeInPrev(TreeNode<T>* t) const;//前序遍历
	void printTreeInMid(TreeNode<T>* t)const;//中序遍历
	void printTreeInPost(TreeNode<T>* t)const; //后续遍历
};
//二叉搜索树类的实现
template<class T>
BSTree<T>::BSTree(const BSTree &rhs)
{
	m_root = clone(rhs.m_root);
}

template<class T>
BSTree<T>::~BSTree()
{
	makeEmpty();
}

template<class T>
const BSTree<T> & BSTree<T>::operator=(const BSTree &rhs)
{
	if(this != &rhs)
	{
		makeEmpty();
		m_root = clone(rhs.m_root);
	}
	return *this;
}

template<class T>
TreeNode<T>* BSTree<T>::clone(TreeNode<T> *t) const
{
	if(t == NULL)
		return NULL;
	TreeNode<T>* newRoot =new TreeNode<T>(t->data, clone(t->left), clone(t->right), NULL);
	if(newRoot->left != NULL)
		newRoot->left->parent = newRoot;
	if(newRoot->right != NULL)
		newRoot->right->parent = newRoot;
	return newRoot;
}


//查找是否含有此元素
 template <class T> 
 bool  BSTree<T>::contains(const T& x) const 
{
    return contains(x, m_root); 
}
template <class T> 
 bool BSTree<T>::contains(const T& x, const TreeNode<T>* t) const 
{ 
	if (t == NULL) 
        return false; 
    else if (x < t->data) 
        return contains(x, t->left);
    else if (x > t->data) 
        return contains(x, t->right); 
    else 
        return true;
}

//清空
template <class T> 
void  BSTree<T>::makeEmpty() 
{ 
    makeEmpty(m_root); 
}
template <class T> 
void  BSTree<T>::makeEmpty(TreeNode<T>* &t)
{ 
    if(t != NULL) 
    {
		//注意其实你删除肯定是从树叶开始删的。所以是左右根
        makeEmpty(t->left);
        makeEmpty(t->right); 
        delete t;
    }
    t=NULL;
}

//查找最大元素
template<class T>
const T &BSTree<T>::findmax() const
{
	return findmax(m_root)->data;
}
template <class T> 
TreeNode<T>* BSTree<T>::findmax(TreeNode<T>* t) const 
{ 
    //二叉树的一个特点就是左子叶的值比根节点小， 右子叶的比根节点的大
	while (t->right != NULL)
		t = t->right;
	return t; 
}

//查找最小元素
template<class T>
const T &BSTree<T>::findmin() const
{
	return findmin(m_root)->data;
}
template <class T> 
TreeNode<T>* BSTree<T>::findmin(TreeNode<T>* t) const 
{ 
    if(t->left == NULL) 
        return t; 
    else
        return findmin(t->left); 
}

//插入
template<class T>
void BSTree<T>::insert(const T &x)
{
	insert(x, m_root);
}
template <class T> 
void BSTree<T>::insert(const T& x, TreeNode<T>* &t) 
{ 
    if(t == NULL) 
        t = new TreeNode<T>(x, NULL, NULL, NULL);//注意这个指针参数是引用
    else if(x < t->data)
	{
        insert(x, t->left);
		t->left->parent = t;
	}
    else if (x > t->data)
	{
        insert(x, t->right);
		t->right->parent = t;
	}
    else 
        ; 
}

//删除，比较复杂
template<class T>
void BSTree<T>::remove(const T &x)
{
	remove(x, m_root);
}
template <class T> 
void BSTree<T>::remove(const T& x, TreeNode<T>* &t) 
{
    if (t == NULL) 
        return; 
    if (x < t->data)
	{
        remove(x, t->left);
		if(t->left != NULL)
			t->left->parent = t;
	}
    else if (x > t->data)
	{
        remove(x, t->right);
		if(t->right != NULL)
			t->right->parent = t;
	}
	//执行这个else就表明找到相等的了，如果一直没有找到，那么也就不会执行下面这个esle了，如果找到就会执行这个else
    else
    { 
		//有两孩子，关键是删除的不是那个结点，删除的是它的右子树上值最小的那个结点，而它自己只不过是获得了那个最小的结点的值
        if (t->left!=NULL&&t->right!=NULL)//two child 
        {
			//如果这个结点有两个儿子，那么就把这个结点的右子树上的最小的结点的值给这个结点。
            t->data=findmin(t->right)->data; 
			//给完结点，就把右子树上的这个含有最小值的结点给去掉。
            remove(t->data,t->right);
        }
		//执行这个else就表明只有一个儿子
        else 
        { 
            TreeNode<T> *oldNode=t;
            t=(t->left!=NULL) ? t->left : t->right;
            delete oldNode; 
        } 
    } 
}

//遍历前，中，后
template <class T>
void BSTree<T>::PreOrder()
{
	cout<<"前序遍历：";
	printTreeInPrev(m_root);
	cout<<endl;
}
template <class T>
 void BSTree<T>::printTreeInPrev(TreeNode<T>* t) const
{
    if(t)
    {
        cout<<t->data<<" ";
        printTreeInPrev(t->left);
        printTreeInPrev(t->right);
    }
}

template <class T>
void BSTree<T>::InOrder()
{
	cout<<"中序遍历：";
	printTreeInMid(m_root);
	cout<<endl;
}
template <class T>
void BSTree<T>::printTreeInMid(TreeNode<T>* t) const
{
    if(t)
    {
        printTreeInMid(t->left);
        cout<<t->data<<" ";
        printTreeInMid(t->right);
    }
}

template <class T>
void BSTree<T>::PostOrder()
{
	cout<<"后续遍历：";
	printTreeInPost(m_root);
	cout<<endl;
}
template <class T>
 void BSTree<T>::printTreeInPost(TreeNode<T>* t) const
{
    if(t)
    {
        printTreeInPost(t->left);
        printTreeInPost(t->right);
        cout<<t->data<<" ";
    }
}


template <class T>
void BSTree<T>::depth_rf() //先根深度遍历;其实这里就是前序遍历的非递归实现
{
	cout << "（深度优先）先根遍历序列:";
	stack<TreeNode<T>*> s;
	s.push(m_root);
	while(!s.empty())
	{
		TreeNode<T>* node_s = s.top();
		cout << node_s->data <<" ";
		s.pop();
		if (node_s->right != NULL)
		{
			s.push(node_s->right);
		}
		if (node_s->left != NULL)
		{
			s.push(node_s->left);
		}
	}
	cout<<endl;
}

template <class T>
void BSTree<T>::depth_rm() //中根深度遍历，中序遍历的非递归实现
{
	cout << "（深度优先）中根遍历序列:";
	stack<TreeNode<T> > s;    
    TreeNode<T> *pNode=m_root;
	while (pNode != NULL || !s.empty())
	{
		while (pNode != NULL)
		{
			s.push(*pNode);
			pNode=pNode->left;
		}
		if (!s.empty())
		{
			TreeNode<T> node_s = s.top();
			cout << node_s.data <<" ";
			s.pop();
			pNode = node_s.right;
		}
	}
	//return true;
	cout<<endl;
}

template <class T>
void BSTree<T>::width_fs() //层次遍历,广度优先搜索
{
	cout << "（广度优先搜索）层次遍历序列:";
	queue<TreeNode<T> > q;
	q.push(*m_root);
	while (!q.empty())
	{
		TreeNode<T> *pNode = &q.front();
		q.pop();
		cout << pNode->data << " ";
		if (pNode->left != NULL)
		{
			q.push(*pNode->left);
		}
		if (pNode->right != NULL)
		{
			q.push(*pNode->right);
		}
	}
	cout<<endl;
}