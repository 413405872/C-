#include<iostream>
#include"List.h"
#include"Queue.h"
#include"Stack.h"
using namespace std;

void TestStack()
{
	cout<<"��ջ���ԣ�"<<endl<<endl;
	Stack<int> sta;
	cout<<"��ջ����:  "<<sta.GetSize()<<endl;
	sta.Push(2);
	cout<<"һ��Ԫ�س���:   "<<sta.GetSize()<<endl;
	cout<<"ջ��Ԫ��:   "<<sta.GetTop()<<endl;
	cout<<"ջ�Ƿ�Ϊ��:  "<<sta.IsEmpty()<<endl;
	sta.Push(3);
	cout<<"����Ԫ��ջ����  "<<sta.GetTop()<<endl;
	cout<<"��ջԪ��Ϊ�� "<<sta.Pop()<<endl;
	cout<<"��ջ��ջ��Ԫ��Ϊ:  "<<sta.GetTop()<<endl;
	sta.MakeEmpty();
	cout<<"���ջ�󳤶�Ϊ��"<<sta.GetSize()<<endl<<endl<<endl;
}

void TestQueue()
{
	cout<<"���в��ԣ�"<<endl<<endl;
	Queue<int> que;
	cout<<"�ն����Ƿ�Ϊ�գ�"<<que.IsEmpty()<<endl;
	que.Enqueue(1);
	cout<<"���һ��Ԫ�غ�ͷ��Ϊ:  "<<que.GetFront()<<endl;
	que.Enqueue(2);
	cout<<"�������Ԫ�غ�ͷ��Ϊ:  "<<que.GetFront()<<endl;
	cout<<"�ǿն����Ƿ�Ϊ�գ�"<<que.IsEmpty()<<endl;
	cout<<"ɾ��һ��Ԫ��Ϊ��"<<que.Delqueue()<<endl;
	cout<<"ɾ��һ��Ԫ�غ�ͷ��Ϊ��"<<que.GetFront()<<endl;
	que.MakeEmpty();
	cout<<"���Ԫ�غ��Ƿ�Ϊ�գ�"<<que.IsEmpty()<<endl<<endl<<endl;
	
}

void TestList()
{
	cout<<"������ԣ�"<<endl<<endl;
	List<int> lis;
	cout<<"��������Ϊ��"<<lis.GetLength()<<endl;
	lis.Insert_end(5);
	lis.Insert_end(4);
	lis.Insert_end(3);
	lis.Insert_end(2);
	cout<<"��β������4��Ԫ�غ󳤶�Ϊ��"<<lis.GetLength()<<endl<<"��ʱ����Ԫ������:"<<endl;
	lis.Print();
	lis.Insert(10,2);
	cout<<"��λ��2����10�Ժ����������:"<<endl;
	lis.Print();
	cout<<"��ʱ������Ϊ��"<<lis.GetLength()<<endl;
	lis.Insert(20,0);
	cout<<"��λ��0����20�Ժ����������:"<<endl;
	lis.Print();
	lis.Insert(30,6);
	cout<<"��λ��6����30�Ժ����������:"<<endl;
	lis.Print();
	cout<<"���ֵΪ2�������е�λ���ǣ�"<<lis.Find(2)<<endl;
	lis.Delete(3);
	cout<<"ɾ��������Ԫ�غ��������Ϊ: "<<lis.GetLength()<<endl;
	cout<<"��ʱԪ��Ϊ��"<<endl;
	lis.Print();
}

int main()
{
	TestStack();
	TestQueue();
	TestList();
	return 0;
}