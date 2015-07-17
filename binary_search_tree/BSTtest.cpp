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
	bst_copy = bst;//这里启用赋值构造函数

	bst.insert(10);

	BSTree<int> bst_C = bst;//这里采用复制构造函数

	bst.insert(1);

	bst_copy.InOrder();//这里输出3，4，并没有，它和bst不是同一个内存
	bst_C.InOrder();

	//递归实现
	bst.PreOrder();
	bst.InOrder();
	bst.PostOrder();

	//非递归实现
	bst.depth_rf();
	bst.depth_rm();
	bst.width_fs();

	bool contain = bst.contains(3);
	cout<<"是否包含3："<<contain<<endl;

	contain = bst.contains(5);
	cout<<"是否包含5："<<contain<<endl;

	int  MAX = bst.findmax();
	cout<<"树中最大值："<<MAX<<endl;
	int  MIN = bst.findmin();
	cout<<"树中最小值："<<MIN<<endl;

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
	
	bst.makeEmpty();//清空
	contain = bst.contains(3);
	cout<<"是否包含3："<<contain<<endl;
	//此时bst被删除了

	bst_C.InOrder();
	bst_copy.InOrder();
}

int main()
{
	BSTtest();
	return 1;
}