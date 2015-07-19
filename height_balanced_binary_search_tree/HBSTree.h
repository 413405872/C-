/***********
*AvlTree.h*
***********/

#include <iostream>
using namespace std;

template<class T> class AvlTree;
template<class T>
class TreeNode{
	friend class AvlTree<T>;
public:
	TreeNode(){}
	TreeNode(T d, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL, int h = 0)
		: data(d), left(l), right(r), height(h)
	{}
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	int height;
};


template<class T>
class AvlTree {
public:
	AvlTree()// 构造函数
	{
		root = NULL;
	}
	AvlTree(const AvlTree & rhs) {
		root = NULL;
		*this = rhs;
	} // Copy Constructor复制构造函数
	const AvlTree & operator=(const AvlTree & rhs) {
		if (this != &rhs) {
			makeEmpty();
			root = clone(rhs.root);
		}
		return *this;
	} // Overload "operator="赋值操作符
	~AvlTree() {
		makeEmpty();
	} // Destructor析构函数

	const T & findMin() const {
		return findMin(root)->data;
	} // Find Minimum Element查找树的最小值

	const T & findMax() const {
		return findMax(root)->data;
	} // Find Maximum Element查找树的最大值

	bool contains(const T & x) const {
		return contains(x, root);
	} // Test if an item is in the tree.检测树中是否有某树

	bool isEmpty() const {
		return root == NULL;
	} // Test if the tree is empty.判断树是否是空树

	void makeEmpty() {
		makeEmpty(root);
	} // Make the tree empty.把树给解散掉

	void insert(const T & x) {
		insert(x, root);
	} // Insert an item into the tree.插入元素

	void remove(const T & x) {
		remove(x, root);
	} // Remove an item from the tree.删除元素

	void printTree(std::ostream & out = std::cout) const {
		if (isEmpty())
			out << "Empty Tree" << std::endl;
		else
			printTree(root, out);
	} // Print the tree in sorted order.把树中的元素打印出来

	int treeHeight() const {
		return treeHeight(root);
	} // Compute the height of the tree.返回树的高度

private:
	TreeNode<T>* root;
	void insert(const T & x, TreeNode<T>* & t);
	void remove(const T & x, TreeNode<T>* & t);

	TreeNode<T>* findMin(TreeNode<T>* t) const;
	TreeNode<T>* findMax(TreeNode<T>* t) const;
	
	bool contains(const T & x, TreeNode<T>* t) const;
	void makeEmpty(TreeNode<T>* & t);
	
	void printTree(TreeNode<T>* t, std::ostream & out) const;
	
	int treeHeight(TreeNode<T>* t) const;
	
	TreeNode<T>* clone(TreeNode<T>* t) const;
	int height(TreeNode<T>* t) const;

	void rotateWithLeftChild(TreeNode<T>* & k2);
	void rotateWithRightChild(TreeNode<T>* & k2);
	void doubleWithLeftChild(TreeNode<T>* & k3);
	void doubleWithRightChild(TreeNode<T>* & k3);
};



/*************
*AvlTree.cpp*其实就是实现
*************/

template<class T>//找到最左边就OK
TreeNode<T>* AvlTree<T>::findMin(
	TreeNode<T>* t) const {
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
}

template<class T>//找到最右边就OK
TreeNode<T>* AvlTree<T>::findMax(
	TreeNode<T>* t) const {
		if (t == NULL)
			return NULL;
		if (t->right == NULL)
			return t;
		return findMax(t->left);
}

/**
* Internal method to test if an item is in a subtree.
* x is item to search for.
* t is the node that roots the subtree.
*/
template<class T>
bool AvlTree<T>::contains(const T & x, TreeNode<T>* t) const {
	if (t==NULL)
		return false;
	else if (t->data>x)
		return contains(x,t->left);
	else if (x>t->data)
		return contains(x,t->right);
	else
		return true; // Match
}

/**
情形1：左-左
*/
template<class T>
void AvlTree<T>::insert(const T & x, TreeNode<T>* & t)
{//插入
	if (t == NULL)
		t = new TreeNode(x, NULL, NULL);
	else if (t->data>x) //此时就是要插入左子树
	{
		insert(x,t->left);
		if (height(t->left)-height(t->right)==2)
		{
			if (t->left->data>x)//你要插入的比我左结点还小，那肯定插入左边，所以是左左
				rotateWithLeftChild(t);
			else//要不然肯定就是左右了。
				doubleWithLeftChild(t);
		}
	}
	else if (x>t->data)//此时就是要插入右子树
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2) {
			if (x > t->right->data)//此时你还大，那肯定是右右，那么肯定要进行右旋转
				rotateWithRightChild(t);
			else//右左
				doubleWithRightChild(t);
		}
	}
	else
		; // Duplicate; do nothing
	t->height=std::max(height(t->left), height(t->right)) + 1;
}

/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
//删除还没好好看
template<class T>
void AvlTree<T>::remove(const T & x, TreeNode<T>* & t) {
	if (t == NULL)
		return;
	// Item not found; do nothing
	if (t->data>x)//这个说明要出问题在左子树上，要变矮了。
	{
		remove(x,t->left);
		if (height(t->right) - height(t->left)==2){
			if (height(t->right->right)>=height(t->right->left))
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
		}
	}
	else if (x>t->data){//这个说明要出问题在右子树上，要变矮了。
		remove(x, t->right);
		if (height(t->left) - height(t->right) == 2) {
			if (height(t->left->left) >= height(t->left->right))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		}
	}
	//下面的两个判断和二叉查找树是一样的
	else if (t->left!= NULL && t->right!=NULL){//这个是正中间，说明没有问题，按正常的二叉查找树就OK。
		t->data = findMin(t->right)->data;
		remove(t->data, t->right);
		t->height = std::max(height(t->left), height(t->right)) + 1;
	}
	else {
		TreeNode *oldNode=t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
	if (t != NULL)
		t->height = std::max(height(t->left), height(t->right)) + 1;
}

/**
* Internal method to make subtree empty.
*/
template<class T>//删除肯定应该用后续遍历进行删除结点。
void AvlTree<T>::makeEmpty(TreeNode<T>* & t) {
	if (t != NULL){
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

/**
* Internal method to clone subtree.
*/
template<class T>
TreeNode<T>* AvlTree<T>::clone(TreeNode<T>* t) const
{
		if (t == NULL)
			return NULL;
		return new TreeNode(t->data, clone(t->left), clone(t->right));
}

/**
* Internal method to print a subtree rooted at t in sorted order.左中右，从小到大的顺序输出
*/
template<class T>
void AvlTree<T>::printTree(TreeNode<T>* t, std::ostream & out) const {
	if (t != NULL) {
		printTree(t->left, out);
		out << t->data << ' ';
		printTree(t->right, out);
	}
}

template<class T>
int AvlTree<T>::height(TreeNode<T>* t) const {
	return t == NULL ? -1 : t->height;
}

template<class T>//这个是LL
void AvlTree<T>::rotateWithLeftChild(TreeNode<T>* & k2) {
	TreeNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	//下面是更新高度
	k2->height = max(height(k2->left), height(k2->right)) + 1;//两个高度都要更新的
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;//此时k2还要是根节点才行
}

template<class T>//这个是RR
void AvlTree<T>::rotateWithRightChild(TreeNode<T>* & k2) {
	TreeNode<T>* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->right), height(k2->left)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	k2 = k1;
}

template<class T>//左右LR，所以要先右旋转RR，后左旋LL
void AvlTree<T>::doubleWithLeftChild(TreeNode<T>* & k3) {
	//先对k3->right的结点进行RR旋转
	rotateWithRightChild(k3->left);
	//再对k3进行RR旋转
	rotateWithLeftChild(k3);
}

template<class T>//由右左，所以要先左旋LL后右旋RR
void AvlTree<T>::doubleWithRightChild(TreeNode<T>* & k3) {
	//先对k3->right的结点进行LL旋转
	rotateWithLeftChild(k3->right);
	//再对k3进行RR旋转
	rotateWithRightChild(k3);
}

template<class T>
int AvlTree<T>::treeHeight(TreeNode<T>* t) const {
	if (t == NULL)
		return -1;
	else
		return 1 + std::max(treeHeight(t->left), treeHeight(t->right));
}