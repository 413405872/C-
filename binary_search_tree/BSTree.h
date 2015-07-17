#include<iostream>
using namespace std;

template<class T> class BSTree;

//���Ľ��ģ�ͣ������Һ��ӻ��и���
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
	void depth_rf();//�ȸ���ȱ���
	void depth_rm();//�и���ȱ���
	void width_fs(); //��α���
private:
	TreeNode<T> *m_root;
	void insert(const T& x, TreeNode<T>* &t);
	void remove(const T& x, TreeNode<T>* &t);
	TreeNode<T>* findmin(TreeNode<T>* t) const;
	TreeNode<T>* findmax(TreeNode<T>* t) const;
	bool contains(const T& x, const TreeNode<T>* t) const;
	TreeNode<T>* clone(TreeNode<T> *t) const;
	void makeEmpty(TreeNode<T>* &t);//������ע������Ҫɾ���϶�Ҫ����ɾ��������ֻ��ɾ�����ĸ���������Ҫ* &
	void printTreeInPrev(TreeNode<T>* t) const;//ǰ�����
	void printTreeInMid(TreeNode<T>* t)const;//�������
	void printTreeInPost(TreeNode<T>* t)const; //��������
};
//�������������ʵ��
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


//�����Ƿ��д�Ԫ��
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

//���
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
		//ע����ʵ��ɾ���϶��Ǵ���Ҷ��ʼɾ�ġ����������Ҹ�
        makeEmpty(t->left);
        makeEmpty(t->right); 
        delete t;
    }
    t=NULL;
}

//�������Ԫ��
template<class T>
const T &BSTree<T>::findmax() const
{
	return findmax(m_root)->data;
}
template <class T> 
TreeNode<T>* BSTree<T>::findmax(TreeNode<T>* t) const 
{ 
    //��������һ���ص��������Ҷ��ֵ�ȸ��ڵ�С�� ����Ҷ�ıȸ��ڵ�Ĵ�
	while (t->right != NULL)
		t = t->right;
	return t; 
}

//������СԪ��
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

//����
template<class T>
void BSTree<T>::insert(const T &x)
{
	insert(x, m_root);
}
template <class T> 
void BSTree<T>::insert(const T& x, TreeNode<T>* &t) 
{ 
    if(t == NULL) 
        t = new TreeNode<T>(x, NULL, NULL, NULL);//ע�����ָ�����������
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

//ɾ�����Ƚϸ���
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
	//ִ�����else�ͱ����ҵ���ȵ��ˣ����һֱû���ҵ�����ôҲ�Ͳ���ִ���������esle�ˣ�����ҵ��ͻ�ִ�����else
    else
    { 
		//�������ӣ��ؼ���ɾ���Ĳ����Ǹ���㣬ɾ������������������ֵ��С���Ǹ���㣬�����Լ�ֻ�����ǻ�����Ǹ���С�Ľ���ֵ
        if (t->left!=NULL&&t->right!=NULL)//two child 
        {
			//������������������ӣ���ô�Ͱ���������������ϵ���С�Ľ���ֵ�������㡣
            t->data=findmin(t->right)->data; 
			//�����㣬�Ͱ��������ϵ����������Сֵ�Ľ���ȥ����
            remove(t->data,t->right);
        }
		//ִ�����else�ͱ���ֻ��һ������
        else 
        { 
            TreeNode<T> *oldNode=t;
            t=(t->left!=NULL) ? t->left : t->right;
            delete oldNode; 
        } 
    } 
}

//����ǰ���У���
template <class T>
void BSTree<T>::PreOrder()
{
	cout<<"ǰ�������";
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
	cout<<"���������";
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
	cout<<"����������";
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
void BSTree<T>::depth_rf() //�ȸ���ȱ���;��ʵ�������ǰ������ķǵݹ�ʵ��
{
	cout << "��������ȣ��ȸ���������:";
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
void BSTree<T>::depth_rm() //�и���ȱ�������������ķǵݹ�ʵ��
{
	cout << "��������ȣ��и���������:";
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
void BSTree<T>::width_fs() //��α���,�����������
{
	cout << "�����������������α�������:";
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