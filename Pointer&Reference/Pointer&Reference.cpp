/*
指针
指针引用
指针的指针
*/

#include <iostream>
using namespace std;
void FreePtr1(int* ptr1)//指针
{
    cout<<"指针形参"<<endl;
	delete ptr1;
    ptr1=NULL;//其实此时是ptr1指向了NULL,而p1相当于“野指针”了啊！！！！！！！！！
}
void Test1()
{
	cout<<endl<<endl<<"-------------Test1--------------"<<endl;
	cout<<"指针，虽然释放了内存但是p1此时变成野指针"<<endl;
    int *p1=new int;
    *p1=1;
    cout<<"*p1="<<*p1<<endl;
    FreePtr1(p1);
	//虽然p1经过执行了这个函数，但是此时p1相当于一个“野指针”
    cout<<"after call freePtr1"<<endl;
    if(p1!=NULL)//此时*p1的值应该还是1
    {
        cout<<"p1 is not null"<<endl;
        cout<<"*p1="<<(*p1)<<endl;
    }
}

void FreePtr2(int*& ptr2)//指针的引用，
{
    //这时候ptr2就是指的p2，它的一切变化都会在p2中也伴随着同样的变化。
	cout<<"指针引用的形参"<<endl;
	delete ptr2; 
    ptr2=NULL;
}
void Test2()
{
	cout<<endl<<endl<<"-------------Test2--------------"<<endl;
	cout<<"指针的引用，此时内存被释放掉，p2==NULL"<<endl;
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

void FreePtr3(int **ptr3)//指针的指针
{
	//此时ptr3里面放的就是p3的地址啊，那么*ptr3不就是指p3这个指针吗。所以也是可以的。
	cout<<"指针的指针"<<endl;
    delete *ptr3;
    *ptr3=NULL;
}
void Test3()
{
	cout<<endl<<endl<<"-------------Test3--------------"<<endl;
	cout<<"指针的指针，与指针的引用效果一样"<<endl;
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

void all1(int **p)//指针的指针
{
	int *pp=new int;
	*p=pp;
	**p=30;//这种赋值方式和下面的*a1=3的效果是一样的。
}
void all2(int*& p)//指针引用
{
	int *pp=new int;
	p=pp;
	*pp=300;//如果这边按照这种方式赋值，那么a2所指向的值就会跟着变化，其实p就是一个指针变量的引用，它和a2是同一个意思
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

