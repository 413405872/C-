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
	AvlTree()// ���캯��
	{
		root = NULL;
	}
	AvlTree(const AvlTree & rhs) {
		root = NULL;
		*this = rhs;
	} // Copy Constructor���ƹ��캯��
	const AvlTree & operator=(const AvlTree & rhs) {
		if (this != &rhs) {
			makeEmpty();
			root = clone(rhs.root);
		}
		return *this;
	} // Overload "operator="��ֵ������
	~AvlTree() {
		makeEmpty();
	} // Destructor��������

	const T & findMin() const {
		return findMin(root)->data;
	} // Find Minimum Element����������Сֵ

	const T & findMax() const {
		return findMax(root)->data;
	} // Find Maximum Element�����������ֵ

	bool contains(const T & x) const {
		return contains(x, root);
	} // Test if an item is in the tree.��������Ƿ���ĳ��

	bool isEmpty() const {
		return root == NULL;
	} // Test if the tree is empty.�ж����Ƿ��ǿ���

	void makeEmpty() {
		makeEmpty(root);
	} // Make the tree empty.��������ɢ��

	void insert(const T & x) {
		insert(x, root);
	} // Insert an item into the tree.����Ԫ��

	void remove(const T & x) {
		remove(x, root);
	} // Remove an item from the tree.ɾ��Ԫ��

	void printTree(std::ostream & out = std::cout) const {
		if (isEmpty())
			out << "Empty Tree" << std::endl;
		else
			printTree(root, out);
	} // Print the tree in sorted order.�����е�Ԫ�ش�ӡ����

	int treeHeight() const {
		return treeHeight(root);
	} // Compute the height of the tree.�������ĸ߶�

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
*AvlTree.cpp*��ʵ����ʵ��
*************/

template<class T>//�ҵ�����߾�OK
TreeNode<T>* AvlTree<T>::findMin(
	TreeNode<T>* t) const {
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
}

template<class T>//�ҵ����ұ߾�OK
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
����1����-��
*/
template<class T>
void AvlTree<T>::insert(const T & x, TreeNode<T>* & t)
{//����
	if (t == NULL)
		t = new TreeNode(x, NULL, NULL);
	else if (t->data>x) //��ʱ����Ҫ����������
	{
		insert(x,t->left);
		if (height(t->left)-height(t->right)==2)
		{
			if (t->left->data>x)//��Ҫ����ı������㻹С���ǿ϶�������ߣ�����������
				rotateWithLeftChild(t);
			else//Ҫ��Ȼ�϶����������ˡ�
				doubleWithLeftChild(t);
		}
	}
	else if (x>t->data)//��ʱ����Ҫ����������
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2) {
			if (x > t->right->data)//��ʱ�㻹���ǿ϶������ң���ô�϶�Ҫ��������ת
				rotateWithRightChild(t);
			else//����
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
//ɾ����û�úÿ�
template<class T>
void AvlTree<T>::remove(const T & x, TreeNode<T>* & t) {
	if (t == NULL)
		return;
	// Item not found; do nothing
	if (t->data>x)//���˵��Ҫ���������������ϣ�Ҫ�䰫�ˡ�
	{
		remove(x,t->left);
		if (height(t->right) - height(t->left)==2){
			if (height(t->right->right)>=height(t->right->left))
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
		}
	}
	else if (x>t->data){//���˵��Ҫ���������������ϣ�Ҫ�䰫�ˡ�
		remove(x, t->right);
		if (height(t->left) - height(t->right) == 2) {
			if (height(t->left->left) >= height(t->left->right))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		}
	}
	//����������жϺͶ����������һ����
	else if (t->left!= NULL && t->right!=NULL){//��������м䣬˵��û�����⣬�������Ķ����������OK��
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
template<class T>//ɾ���϶�Ӧ���ú�����������ɾ����㡣
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
* Internal method to print a subtree rooted at t in sorted order.�����ң���С�����˳�����
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

template<class T>//�����LL
void AvlTree<T>::rotateWithLeftChild(TreeNode<T>* & k2) {
	TreeNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	//�����Ǹ��¸߶�
	k2->height = max(height(k2->left), height(k2->right)) + 1;//�����߶ȶ�Ҫ���µ�
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;//��ʱk2��Ҫ�Ǹ��ڵ����
}

template<class T>//�����RR
void AvlTree<T>::rotateWithRightChild(TreeNode<T>* & k2) {
	TreeNode<T>* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->right), height(k2->left)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	k2 = k1;
}

template<class T>//����LR������Ҫ������תRR��������LL
void AvlTree<T>::doubleWithLeftChild(TreeNode<T>* & k3) {
	//�ȶ�k3->right�Ľ�����RR��ת
	rotateWithRightChild(k3->left);
	//�ٶ�k3����RR��ת
	rotateWithLeftChild(k3);
}

template<class T>//����������Ҫ������LL������RR
void AvlTree<T>::doubleWithRightChild(TreeNode<T>* & k3) {
	//�ȶ�k3->right�Ľ�����LL��ת
	rotateWithLeftChild(k3->right);
	//�ٶ�k3����RR��ת
	rotateWithRightChild(k3);
}

template<class T>
int AvlTree<T>::treeHeight(TreeNode<T>* t) const {
	if (t == NULL)
		return -1;
	else
		return 1 + std::max(treeHeight(t->left), treeHeight(t->right));
}