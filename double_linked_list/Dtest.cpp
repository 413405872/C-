#include<iostream>
#include"DList.h"
using namespace std;

void test()
{
	cout<<"双向链表测试"<<endl;
	DList<int> DL;
	cout<<"空链表长度 "<<DL.size()<<endl;
	DL.insert_First(3);
	DL.insert_First(4);
	cout<<"插入两个数以后的长度 "<<DL.size()<<endl;
	cout<<"此时链表中的值为 "<<endl;
	DL.print();

	DL.insert_First(10);
	DL.print();
	cout<<"此时链表是否为空 "<<DL.is_Empty()<<endl;

	DL.insert(2, 12);
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;

	DL.del(3);
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;

	DL.delete_First();
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;

	DL.delete_Last();
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;

	DL.delete_Last();
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;

	DL.del(3);
	DL.print();
	cout<<"链表长度 "<<DL.size()<<endl;
}

int main()
{
	test();
	return 1;
}