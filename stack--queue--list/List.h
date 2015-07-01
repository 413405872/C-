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
	void Insert_end(T item);//��β������Ԫ��
	bool Insert(T item,int pos);//������ĳ������Ԫ��
	void Delete(int pos);//ɾ��ĳ�����
	int Find(T item);//����ĳ�����
	void MakeEmpty();
	void Print();//��ӡ����
	int GetLength();//������
private:
	int length;//��¼������
	ListNode<T>* head;
	ListNode<T>* last;//���������¼β�����
};

template<class T>
void List<T>::Insert_end(T item)
{
	if(last!=NULL)//����տ�ʼ���н����OK
	{
		last->next=new ListNode<T>(item,NULL);
		last=last->next;
	}
	else//����տ�ʼ��û�н����
	{
		last=new ListNode<T>(item,NULL);
		head=last;
	}
	length++;
}

template<class T>
bool List<T>::Insert(T item, int pos)
{
	if(pos>length||pos<0)//������������ķ�Χ
		return false;
	ListNode<T>* p=new ListNode<T>(item,NULL);
	if(pos==0)//��Ϊͷ
	{
		p->next=head;
		head=p;
	}
	else if(pos==length)//��Ϊβ
	{
		last->next=p;
		last=last->next;
	}
	else//���м�ĳ��λ��
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
	if(pos>length||pos<0||head==NULL)//������������ķ�Χ
		return;
	ListNode<T>* p=head;
	if(pos==1)//��Ϊͷ
	{
		head=head->next;
		delete p;
	}
	else if(pos==length)//��Ϊβ
	{
		while(p->next!=last)
			p=p->next;
		p->next=last->next;
		delete last;
		last=p;
	}
	else//���м�ĳ��λ��
	{
		ListNode<T>* pDel=head;
		int i=1;
		while(i<pos)
		{
			p=pDel;//p��ΪpNodeǰһ��
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