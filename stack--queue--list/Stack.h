#include<iostream>
template<class T> class Stack;
template<class T>
class StackNode{//ջ�Ľ��
	friend class Stack<T>;//�����Ԫ�Ϳ����ý���װ��˽�еģ���Ϊ��Ԫ���Է������˽�г�Ա
public:
	StackNode(T Data,StackNode<T>* L=NULL):data(Data),link(L)
	{}
private:
	T data;
	StackNode<T>* link;
};

template<class T>
class Stack{
public:
	Stack():top(NULL),Size(0)
	{}
	~Stack()
	{
		MakeEmpty();
	}
	void Push(T item);
	T Pop();//������һ���ѳ�ջ��Ԫ�ؼ��£����Է���T
	T GetTop();
	void MakeEmpty();
	bool IsEmpty();
	int GetSize();
private:
	int Size;//��ȡջ��Ԫ�ظ���
	StackNode<T>* top; 
};

template<class T>
void Stack<T>::Push(T item)
{
	top=new StackNode<T>(item,top);
	Size++;
}

template<class T>
T Stack<T>::Pop()
{
	StackNode<T>* p;
	T item=top->data;
	p=top;
	top=top->link;
	delete p;
	Size--;
	return item;
}

template<class T>
T Stack<T>::GetTop()
{
	T item=top->data;
	return item;
}

template<class T>
void Stack<T>::MakeEmpty()
{
	while(top!=NULL)
	{
		StackNode<T> *p=top;
		top=top->link;
		delete p;
	}
	Size=0;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return top==NULL;
}

template<class T>
int Stack<T>::GetSize()
{
	return Size;
}