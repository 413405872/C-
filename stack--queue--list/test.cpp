#include<iostream>
#include"List.h"
#include"Queue.h"
#include"Stack.h"
using namespace std;

void TestStack()
{
	cout<<"堆栈测试："<<endl<<endl;
	Stack<int> sta;
	cout<<"空栈长度:  "<<sta.GetSize()<<endl;
	sta.Push(2);
	cout<<"一个元素长度:   "<<sta.GetSize()<<endl;
	cout<<"栈顶元素:   "<<sta.GetTop()<<endl;
	cout<<"栈是否为空:  "<<sta.IsEmpty()<<endl;
	sta.Push(3);
	cout<<"两个元素栈顶：  "<<sta.GetTop()<<endl;
	cout<<"出栈元素为： "<<sta.Pop()<<endl;
	cout<<"出栈后栈顶元素为:  "<<sta.GetTop()<<endl;
	sta.MakeEmpty();
	cout<<"清空栈后长度为："<<sta.GetSize()<<endl<<endl<<endl;
}

void TestQueue()
{
	cout<<"队列测试："<<endl<<endl;
	Queue<int> que;
	cout<<"空队列是否为空："<<que.IsEmpty()<<endl;
	que.Enqueue(1);
	cout<<"入队一个元素后头部为:  "<<que.GetFront()<<endl;
	que.Enqueue(2);
	cout<<"入队两个元素后头部为:  "<<que.GetFront()<<endl;
	cout<<"非空队列是否为空："<<que.IsEmpty()<<endl;
	cout<<"删除一个元素为："<<que.Delqueue()<<endl;
	cout<<"删除一个元素后头部为："<<que.GetFront()<<endl;
	que.MakeEmpty();
	cout<<"清空元素后是否为空："<<que.IsEmpty()<<endl<<endl<<endl;
	
}

void TestList()
{
	cout<<"链表测试："<<endl<<endl;
	List<int> lis;
	cout<<"空链表长度为："<<lis.GetLength()<<endl;
	lis.Insert_end(5);
	lis.Insert_end(4);
	lis.Insert_end(3);
	lis.Insert_end(2);
	cout<<"从尾部插入4个元素后长度为："<<lis.GetLength()<<endl<<"此时链表元素如下:"<<endl;
	lis.Print();
	lis.Insert(10,2);
	cout<<"在位置2插入10以后的链表如下:"<<endl;
	lis.Print();
	cout<<"此时链表长度为："<<lis.GetLength()<<endl;
	lis.Insert(20,0);
	cout<<"在位置0插入20以后的链表如下:"<<endl;
	lis.Print();
	lis.Insert(30,6);
	cout<<"在位置6插入30以后的链表如下:"<<endl;
	lis.Print();
	cout<<"结点值为2在链表中的位置是："<<lis.Find(2)<<endl;
	lis.Delete(3);
	cout<<"删除第三个元素后的链表长度为: "<<lis.GetLength()<<endl;
	cout<<"此时元素为："<<endl;
	lis.Print();
}

int main()
{
	TestStack();
	TestQueue();
	TestList();
	return 0;
}