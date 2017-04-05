#include<iostream>
using namespace std;


template<class T>
class BinaryTree {
private;
	class BinaryTreeNode{
		public:
			T key;
			BinaryTreeNode<T> *left,*right,*p;
			BinaryTreeNode(T key, BinaryTreeNode<T> *left = NULL, BinaryTreeNode<T> *right = NULL, BinaryTreeNode<T> *p = NULL) {
                		this->key = key;
                		this->left = left; this->right = right; this->p = p;
        		}
	}

	BinaryTreeNode<T> *root;

	BinaryTree() = default;

	//还需优化
	BinaryTree(T value[], int n) {
		this->root = new BinaryTreeNode<T>(value[0]);

		for (int index = 1; index < n; index++) {
			BinaryTreeNode<T> *x = this->root;

			while (true) {
				if (value[index] > x->key) {
					if (x->right != NULL) {
						x = x->right;
					}
					else {
						x->right = new BinaryTreeNode<T>(value[index]);
						break;
					}
				}
				else {
					if (x->left != NULL) {
						x = x->left;
					}
					else {
						x->left = new BinaryTreeNode<T>(value[index]);
						break;
					}
				}
			}
		}
	}

	//中序遍历
	void inorder_tree_walk(BinaryTreeNode<T> *x) {
		if (x != NULL) {
			inorder_tree_walk(x->left);
			cout << x->key << endl;
			inorder_tree_walk(x->right);
		}
	}

	//先序遍历
	void preorder_tree_walk(BinaryTreeNode<T> *x) {
		cout << x->key << endl;
		preorder_tree_walk(x->left);
		preorder_tree_walk(x->right);
	}

	////后序遍历
	void postorder_tree_walk(BinaryTreeNode<T> *x) {
		postorder_tree_walk(x->left);
		postorder_tree_walk(x->right);
		cout << x->key << endl;
	}

	//递归搜寻
	BinaryTreeNode<T>* tree_search(BinaryTreeNode<T> *x, T key) {
		if (x == NULL || key == x->key) { return x; }

		if (key < x->key) {
			return tree_search(x->left, key);
		}
		else {
			return tree_search(x->right, key);
		}
	}

	//迭代搜寻
	BinaryTreeNode<T>* iterative_tree_search(BinaryTreeNode<T> *x, T key) {
		while (x != NULL&&key != x->key) {
			if (key < x->key) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}

		return x;
	}

	//最小搜寻
	BinaryTreeNode<T>* tree_minimum(BinaryTreeNode<T> *x) {
		while (x->left != NULL) { x = x->left; }

		return x;
	}

	//最大搜寻
	BinaryTreeNode<T>* tree_maximum(BinaryTreeNode<T> *x) {
		while (x->right != NULL) { x = x->right; }

		return x;
	}

	//插入
	void tree_insert(T value) {

		if (this->root != NULL) {
			BinaryTreeNode<T> *z = new BinaryTreeNode<T>(value);
			BinaryTreeNode<T> *x = this->root;
			BinaryTreeNode<T> *y;

			while (x != NULL) {
				y = x;
				if (z->key < x->key) {
					x = x->left;
				}
				else {
					x = x->right;
				}
			}
			z->p = y;
		}
		else {
			this->root = new BinaryTreeNode<T>(value);
		}
	}

	//
};

int main(int argc, char *argv[]) {
	int value = 12;
	BinaryTree<int> *binaryTree = new BinaryTree<int>();
	binaryTree->tree_insert(value);

	cout << binaryTree->root->key << endl;
}
