//����������С����ıȽϡ�������������������������������
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
	delete str;//��߲�ɾ���ͻ��ڴ�й¶
} 
 
char *GetMemory2(void)
{
	char *p="hello world";//p[]��ջ�ڴ棻����ʱ�Ǿ�̬�洢��������ǲ����޸ĵģ���*pʱhello world���洢�ھ�̬�洢�������Ǵ�ʱ�ǲ����޸�ֵ��
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
    if (str!=NULL)//���ͷŵ��ڴ��ˣ��������ָ�뻹ָ������ڴ棬���Բ�����NULL��ֻ�Ǹ�Ұָ����ѣ�����Ӧ��str=NULL;
    {
		strcpy(str,"hello world");//�㿴����ָ���ͷ����Ժ��һ��ڸ�������ֵ
        cout<<str<<endl;
    } 
} 
 // ----------------------------------------------- 
void main()
 {
     // ����Test1��������ʲô���Ľ����
     // ��û�����⡣
     // 
     // ��ΪGetMemory���ݶ�̬�ڴ棬
     // ����ע��һ��Ҫ�ͷţ�������ڴ�й¶ 
	 Test1();
     //����Test2��������ʲô���Ľ����
     //�𣺲��������⡣
     // 
     // ��ΪGetMemory���ص���ָ��ջ�ڴ桱��ָ�룬
     // ��ָ��ĵ�ַ����NULL������ԭ�ֵ������Ѿ�������������ݲ���֪�� 
     Test2();
     //����Test3��������ʲô���Ľ����
     //��1���ܹ����hello
     //��2����ֹ�ڴ�й© 
     Test3();
     //����Test��������ʲô���Ľ����
	 //�𣺴۸Ķ�̬�ڴ��������ݣ��������Ԥ�ϣ��ǳ�Σ�ա�
     //��Ϊdelete str֮��str��ΪҰָ�룬
     //if(str != NULL)��䲻�����á� 
     Test4();
}
