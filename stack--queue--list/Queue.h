#include<iostream>

template<class T> class Queue;

template<class T>
class QueueNode{
public:
	friend class Queue<T>;//一定要声明为友元
	QueueNode(T Data,QueueNode<T>* L=NULL):data(Data),link(L)
	{}
private:
	T data;
	QueueNode<T>* link;
};

template<class T>
class Queue{
public:
	Queue():front(NULL),rear(NULL)
	{}
	~Queue()
	{
		MakeEmpty();
	}
	void Enqueue(T item);
	T Delqueue();
	T GetFront();
	void MakeEmpty();
	bool IsEmpty();
private:
	QueueNode<T>* front;
	QueueNode<T>* rear;
};

template<class T>
void Queue<T>::Enqueue(T item)//相当于进一个尾部rear往上走一个
{
	if(front==NULL)//无结点
	{
		front=new QueueNode<T>(item,NULL);
		rear=front;
	}
	else
	{
		rear->link=new QueueNode<T>(item,NULL);
		rear=rear->link;
	}
}

template<class T>
T Queue<T>::Delqueue()
{
	QueueNode<T>* p;
	p=front;
	T item=front->data;
	front=front->link;
	delete p;
	return item;
}

template<class T>
T Queue<T>::GetFront()
{
	return front->data;
}

template<class T>
void Queue<T>::MakeEmpty()
{
	while(front!=NULL)
	{
		QueueNode<T> *p=front;
		front=front->link;
		delete p;
	}
}

template<class T>
bool Queue<T>::IsEmpty()
{
	return front==NULL;
}