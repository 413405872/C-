/*
ָ��
ָ������
ָ���ָ��
*/

#include <iostream>
using namespace std;
void FreePtr1(int* ptr1)//ָ��
{
    cout<<"ָ���β�"<<endl;
	delete ptr1;
    ptr1=NULL;//��ʵ��ʱ��ptr1ָ����NULL,��p1�൱�ڡ�Ұָ�롱�˰�������������������
}
void Test1()
{
	cout<<endl<<endl<<"-------------Test1--------------"<<endl;
	cout<<"ָ�룬��Ȼ�ͷ����ڴ浫��p1��ʱ���Ұָ��"<<endl;
    int *p1=new int;
    *p1=1;
    cout<<"*p1="<<*p1<<endl;
    FreePtr1(p1);
	//��Ȼp1����ִ����������������Ǵ�ʱp1�൱��һ����Ұָ�롱
    cout<<"after call freePtr1"<<endl;
    if(p1!=NULL)//��ʱ*p1��ֵӦ�û���1
    {
        cout<<"p1 is not null"<<endl;
        cout<<"*p1="<<(*p1)<<endl;
    }
}

void FreePtr2(int*& ptr2)//ָ������ã�
{
    //��ʱ��ptr2����ָ��p2������һ�б仯������p2��Ҳ������ͬ���ı仯��
	cout<<"ָ�����õ��β�"<<endl;
	delete ptr2; 
    ptr2=NULL;
}
void Test2()
{
	cout<<endl<<endl<<"-------------Test2--------------"<<endl;
	cout<<"ָ������ã���ʱ�ڴ汻�ͷŵ���p2==NULL"<<endl;
	int *p2=new int;
    *p2=2;
    cout<<"*p2="<<*p2<<endl;
    FreePtr2(p2);
    cout<<"after call freePtr2"<<endl;
    if(p2!=NULL)
    {       
        cout<<"*p2="<<*p2<<endl;
    }
    else
    {
        cout<<"the p2 is null"<<endl;
    }
}

void FreePtr3(int **ptr3)//ָ���ָ��
{
	//��ʱptr3����ŵľ���p3�ĵ�ַ������ô*ptr3������ָp3���ָ��������Ҳ�ǿ��Եġ�
	cout<<"ָ���ָ��"<<endl;
    delete *ptr3;
    *ptr3=NULL;
}
void Test3()
{
	cout<<endl<<endl<<"-------------Test3--------------"<<endl;
	cout<<"ָ���ָ�룬��ָ�������Ч��һ��"<<endl;
    int *p3 ;
    p3=new int(3);
    cout<<"*p3="<<*p3<<endl;
    FreePtr3(&p3);
    cout<<"after call freePtr3"<<endl;
    if(p3!=NULL)
    {       
        cout<<"*p3="<<*p3<<endl;
    }
    else
    {
        cout<<"the p3 is null"<<endl;
    }
}

void all1(int **p)//ָ���ָ��
{
	int *pp=new int;
	*p=pp;
	**p=30;//���ָ�ֵ��ʽ�������*a1=3��Ч����һ���ġ�
}
void all2(int*& p)//ָ������
{
	int *pp=new int;
	p=pp;
	*pp=300;//�����߰������ַ�ʽ��ֵ����ôa2��ָ���ֵ�ͻ���ű仯����ʵp����һ��ָ����������ã�����a2��ͬһ����˼
}
void Test4()
{
	cout<<endl<<endl<<"-------------Test4--------------"<<endl;
	int *a1;
	all1(&a1);
	cout<<*a1<<endl;
	delete a1;
	int *a2;
	all2(a2);
	cout<<*a2<<endl;
	delete a2;
}
void main()
{
	Test1();
	Test2();
	Test3();
	Test4();
}

