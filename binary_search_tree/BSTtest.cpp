#include<iostream>
#include<stack>
#include<queue>
#include"BSTree.h"
using namespace std;

void BSTtest()
{
	BSTree<int> bst;
	bst.insert(3);
	bst.insert(4);

	BSTree<int> bst_copy;
	bst_copy = bst;//�������ø�ֵ���캯��

	bst.insert(10);

	BSTree<int> bst_C = bst;//������ø��ƹ��캯��

	bst.insert(1);

	bst_copy.InOrder();//�������3��4����û�У�����bst����ͬһ���ڴ�
	bst_C.InOrder();

	//�ݹ�ʵ��
	bst.PreOrder();
	bst.InOrder();
	bst.PostOrder();

	//�ǵݹ�ʵ��
	bst.depth_rf();
	bst.depth_rm();
	bst.width_fs();

	bool contain = bst.contains(3);
	cout<<"�Ƿ����3��"<<contain<<endl;

	contain = bst.contains(5);
	cout<<"�Ƿ����5��"<<contain<<endl;

	int  MAX = bst.findmax();
	cout<<"�������ֵ��"<<MAX<<endl;
	int  MIN = bst.findmin();
	cout<<"������Сֵ��"<<MIN<<endl;

	bst.remove(3);
	bst.PostOrder();
	bst.remove(9);
	bst.PostOrder();
	bst.remove(1);
	bst.PostOrder();
	bst.remove(4);
	bst.PostOrder();
	bst.remove(10);
	bst.PostOrder();
	
	bst.makeEmpty();//���
	contain = bst.contains(3);
	cout<<"�Ƿ����3��"<<contain<<endl;
	//��ʱbst��ɾ����

	bst_C.InOrder();
	bst_copy.InOrder();
}

int main()
{
	BSTtest();
	return 1;
}