#include<iostream>
#include"DList.h"
using namespace std;

void test()
{
	cout<<"˫���������"<<endl;
	DList<int> DL;
	cout<<"�������� "<<DL.size()<<endl;
	DL.insert_First(3);
	DL.insert_First(4);
	cout<<"�����������Ժ�ĳ��� "<<DL.size()<<endl;
	cout<<"��ʱ�����е�ֵΪ "<<endl;
	DL.print();

	DL.insert_First(10);
	DL.print();
	cout<<"��ʱ�����Ƿ�Ϊ�� "<<DL.is_Empty()<<endl;

	DL.insert(2, 12);
	DL.print();
	cout<<"������ "<<DL.size()<<endl;

	DL.del(3);
	DL.print();
	cout<<"������ "<<DL.size()<<endl;

	DL.delete_First();
	DL.print();
	cout<<"������ "<<DL.size()<<endl;

	DL.delete_Last();
	DL.print();
	cout<<"������ "<<DL.size()<<endl;

	DL.delete_Last();
	DL.print();
	cout<<"������ "<<DL.size()<<endl;

	DL.del(3);
	DL.print();
	cout<<"������ "<<DL.size()<<endl;
}

int main()
{
	test();
	return 1;
}