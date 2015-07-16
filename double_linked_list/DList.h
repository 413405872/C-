#include<iostream>
using namespace std;

template<class T> class DList;

template<class T>
class DListNode{
	friend class DList<T>;
public:
	DListNode(T d, DListNode<T>* n = NULL, DListNode<T>* p = NULL): data(d), next(n), pre(p)
	{}
private:
	T data;
	DListNode<T>* next;
	DListNode<T>* pre;
};

template<class T>
class DList{
public:
	DList():length(0),head(NULL)
	{}
	~DList();
	int size();
	int is_Empty();
	T get(int index);
	T get_First();
	T get_Last();
	bool insert(int index, T t);
	void insert_First(T t);
	void del(int index);
	void delete_First();
	void delete_Last();
	void print();
private:
	int length;
	DListNode<T>* head;
	DListNode<T>* get_Node(int index);
};

template<class T>
DList<T>::~DList()
{
	while(head != NULL)
	{
		DListNode<T>* pNode = head;
		head = head->next;
		delete pNode;
	}
}

template<class T>
int DList<T>::size()
{
	return length;
}

template<class T>
int DList<T>::is_Empty()
{
	return length == 0;
}

template<class T>
DListNode<T>* DList<T>::get_Node(int index)
{
	//超出范围了
	if(index <= 0 || index > length)
		return NULL;
	DListNode<T>* pNode = head;
	while(index > 1)//如果是1的话就是头结点
	{
		pNode = pNode->next;
		index--;
	}
	return pNode;
}
template<class T>
T DList<T>::get(int index)
{
	return get_Node(index)->data;
}

template<class T>
T DList<T>::get_First()
{
	return get_Node(1)->data;
}

template<class T>
T DList<T>::get_Last()
{
	return get_Node(length)->data;
}

template<class T>
bool DList<T>::insert(int index, T t)
{
	//看有没有超过界限，可插入的是1-length
	if(index <= 0 || (length != 0 && index > length))
		return false;
	if(index == 1)//插在头结点
		insert_First(t);
	else
	{
		DListNode<T>* pNode = get_Node(index);
		DListNode<T>* pPre = pNode->pre;
		cout<<pPre->data<<endl;
		DListNode<T>* newNode = new DListNode<T>(t, pNode, pPre);
		pPre->next = newNode;//这个一定要注意，下面这两句
		pNode->pre = newNode;
		length++;
	}
	return true;
}

template<class T>
void DList<T>::insert_First(T t)
{
	DListNode<T>* newNode = new DListNode<T>(t, head, NULL);
	if(head != NULL)
		head->pre = newNode;
	head = newNode;
	length++;
}

template<class T>
void DList<T>::del(int index)
{
	if(index <= 0 || index >length)
		return ;
	DListNode<T>* pNode = get_Node(index);
	if(pNode == head)
	{
		head = head->next;
		delete pNode;
	}
	else
	{
		pNode->pre->next = pNode->next;
		if(pNode->next != NULL)
			pNode->next->pre = pNode->pre;
		delete pNode;
	}
	length--;
}

template<class T>
void DList<T>::delete_First()
{
	del(1);
}

template<class T>
void DList<T>::delete_Last()
{
	del(length);
}

template<class T>
void DList<T>::print()
{
	DListNode<T>* pNode = head;
	while(pNode != NULL)
	{
		cout<<pNode->data<<"   ";
		pNode = pNode->next;
	}
	cout<<endl;
}