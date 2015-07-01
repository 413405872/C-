#include<iostream>
using namespace std;

template<class T> class List;

template<class T>
class ListNode{
public:
	friend class List<T>;
	ListNode(T Data,ListNode<T>* Next=NULL):data(Data),next(Next)
	{}
private:
	T data;
	ListNode<T>* next;
};

template<class T>
class List{
public:
	List():length(0),head(NULL),last(NULL)
	{}
	~List()
	{
		MakeEmpty();
	}
	void Insert_end(T item);//在尾部插入元素
	bool Insert(T item,int pos);//在链表某处插入元素
	void Delete(int pos);//删除某个结点
	int Find(T item);//查找某个结点
	void MakeEmpty();
	void Print();//打印链表
	int GetLength();//链表长度
private:
	int length;//记录链表长度
	ListNode<T>* head;
	ListNode<T>* last;//这个用来记录尾部结点
};

template<class T>
void List<T>::Insert_end(T item)
{
	if(last!=NULL)//如果刚开始就有结点那OK
	{
		last->next=new ListNode<T>(item,NULL);
		last=last->next;
	}
	else//如果刚开始就没有结点呢
	{
		last=new ListNode<T>(item,NULL);
		head=last;
	}
	length++;
}

template<class T>
bool List<T>::Insert(T item, int pos)
{
	if(pos>length||pos<0)//超过了你链表的范围
		return false;
	ListNode<T>* p=new ListNode<T>(item,NULL);
	if(pos==0)//作为头
	{
		p->next=head;
		head=p;
	}
	else if(pos==length)//作为尾
	{
		last->next=p;
		last=last->next;
	}
	else//在中间某个位置
	{
		ListNode<T>* pNode=head;
		int i=1;
		while(i<pos)
		{
			pNode=pNode->next;
			i++;
		}
		p->next=pNode->next;
		pNode->next=p;
	}
	length++;
	return true;
}

template<class T>
void List<T>::Delete(int pos)
{
	if(pos>length||pos<0||head==NULL)//超过了你链表的范围
		return;
	ListNode<T>* p=head;
	if(pos==1)//作为头
	{
		head=head->next;
		delete p;
	}
	else if(pos==length)//作为尾
	{
		while(p->next!=last)
			p=p->next;
		p->next=last->next;
		delete last;
		last=p;
	}
	else//在中间某个位置
	{
		ListNode<T>* pDel=head;
		int i=1;
		while(i<pos)
		{
			p=pDel;//p作为pNode前一个
			pDel=pDel->next;
			i++;
		}
		p->next=pDel->next;
		delete pDel;
	}
	length--;
}

template<class T>
int List<T>::Find(T item)
{
	ListNode<T>* pNode=head;
	int i=1;
	while(pNode!=NULL&&pNode->data!=item)
	{
		i++;
		pNode=pNode->next;
	}
	if(pNode==NULL)
		return 0;
	else
		return i;
}

template<class T>
void List<T>::MakeEmpty()
{
	ListNode<T>* p=head;
	ListNode<T>* p1=p;
	while(p!=NULL)
	{
		p=p->next;
		delete p1;
		p1=p;
	}
	length=0;
}

template<class T>
void List<T>::Print()
{
	ListNode<T>* p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}

template<class T>
int List<T>::GetLength()
{
	return length;
}