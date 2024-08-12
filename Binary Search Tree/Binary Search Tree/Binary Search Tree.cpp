#include<iostream>
using namespace std;

template<typename  T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(NULL),right(NULL){}
	TreeNode(T d) :val(d), left(NULL), right(NULL){}


};
template<typename T>
class BinarySearchTree {
private:
	TreeNode<T>* root;
	TreeNode<T>* insertNode(TreeNode<T>* node, T value);
	TreeNode<T>* removeNode(TreeNode<T>* node, T value);
	bool searchNode(TreeNode<T>* node, T value);
	void inOrder(TreeNode<T>* node);

public:
	BinarySearchTree() :root(NULL){}
	~BinarySearchTree();

	void insert(T value){
		root = insertNode(root, value);
	}

	void remove(T value) {
		root = removeNode(root, value);
	}

	bool search(T value) {
		return searchNode(root, value);
	}

	void inOrderTraversal() {
		inOrder(root);
		cout << endl;
	}
};


template<typename  T>
BinarySearchTree<T>::~BinarySearchTree() {
	while (root) {
		remove(root->val);
	}

}


template<typename  T>
TreeNode<T>* BinarySearchTree<T>::insertNode(TreeNode<T>* node, T value) {
	if (node == NULL) {
		return new TreeNode<T>(value);
	}
	if (value < node->val) {
		node->left=insertNode(node->left, value);
	}
	if (value > node->val) {
		node->right=insertNode(node->right, value);
	}
	return node;

}
template<typename  T>
TreeNode<T>* BinarySearchTree<T>::removeNode(TreeNode<T>* node, T value) {
	if (node == NULL) {
		return NULL;
	}
	if (value < node->val) {
		node->left = removeNode(node->left, value);
	}
	else if (value > node->val) {
		node->right = removeNode(node->right, value);

	}
	else {
		if (node->left == NULL && node->right == NULL) {
			delete node;
			return NULL;
		}
		else if (node->left == NULL) {
			TreeNode<T>* rightchild = node->right;
			delete node;
			return rightchild;

		}
		else if (node->right == NULL) {
			TreeNode<T>* leftchild = node->left;
			delete node;
			return leftchild;
		}
		else {
			TreeNode<T>* replacement = node->right;
			while (replacement->left) {
				replacement = replacement->left;
			}
			node->val = replacement->val;
			node->right = removeNode(node->right, replacement->val);
		}
	}
	return node;



}

template<typename  T>
bool BinarySearchTree<T>::searchNode(TreeNode<T>* node, T value) {
	if (node == NULL) {
		return false;
	}
	if (value < node->val) {
		return searchNode(node->left, value);
	}
	else if (value > node->val) {
		return searchNode(node->right, value);
	}
	return true;
}

template<typename  T>
void BinarySearchTree<T>::inOrder(TreeNode<T>* node) {
	if (node) {
		inOrder(node->left);
		cout << node->val << ',';
		inOrder(node->right);
	}

}

int main() {
	BinarySearchTree<int>bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(70);
	bst.insert(40);
	bst.insert(80);
	bst.insert(80);
	bst.insert(80);
	bst.insert(60);
	bst.insert(100);
	bst.inOrderTraversal();
	cout << bst.search(9090) << endl;
	cout << bst.search(100) << endl;
	bst.remove(50);
	bst.inOrderTraversal();
	return 0;
}