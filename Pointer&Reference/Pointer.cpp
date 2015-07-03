//下面是四种小程序的比较。！！！！！！！！！！！！！！！
#include<iostream>
#include<string>
using namespace std;
void  GetMemory1(char** p)
{
	*p=new char[100];
} 
void  Test1( void )
{
	cout<<"-----------Test1-------------"<<endl;
	char *str=NULL;
    GetMemory1(&str);
    strcpy(str,"hello world");
    cout<<str<<endl;
	delete str;//这边不删除就会内存泄露
} 
 
char *GetMemory2(void)
{
	char *p="hello world";//p[]是栈内存；而此时是静态存储区，这个是不能修改的，而*p时hello world被存储在静态存储区，但是此时是不能修改值的
    return p;
} 
void  Test2( void )
{
	cout<<endl<<endl<<"-----------Test2-------------"<<endl;
	char *str=NULL;
    str=GetMemory2();  
    cout<<str<<endl;
} 

void  GetMemory3( char** p, int num)
{
	*p=new char[num];//(char*)malloc(num);
} 
void  Test3( void )
{
	cout<<endl<<endl<<"-----------Test3-------------"<<endl;
	char *str=NULL;
    GetMemory3(&str,100 );
    strcpy(str,"hello world");  
    cout<<str<<endl;
	delete str;
} 

void  Test4( void )
{
	cout<<endl<<endl<<"-----------Test4-------------"<<endl;
	char *str=new char[100];
    strcpy(str,"hello");
    delete [] str;
    if (str!=NULL)//是释放掉内存了，但是这个指针还指向这个内存，所以并不是NULL，只是个野指针而已，正常应该str=NULL;
    {
		strcpy(str,"hello world");//你看我在指针释放了以后我还在更改它的值
        cout<<str<<endl;
    } 
} 
 // ----------------------------------------------- 
void main()
 {
     // 运行Test1函数会有什么样的结果？
     // 答：没有问题。
     // 
     // 因为GetMemory传递动态内存，
     // 但是注意一定要释放，否则会内存泄露 
	 Test1();
     //运行Test2函数会有什么样的结果？
     //答：不会有问题。
     // 
     // 因为GetMemory返回的是指向“栈内存”的指针，
     // 该指针的地址不是NULL，但其原现的内容已经被清除，新内容不可知。 
     Test2();
     //运行Test3函数会有什么样的结果？
     //（1）能够输出hello
     //（2）防止内存泄漏 
     Test3();
     //运行Test函数会有什么样的结果？
	 //答：篡改动态内存区的内容，后果难以预料，非常危险。
     //因为delete str之后，str成为野指针，
     //if(str != NULL)语句不起作用。 
     Test4();
}
