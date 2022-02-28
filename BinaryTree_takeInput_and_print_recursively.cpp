#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
template <typename T>

class BinaryTreeNode{
	public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;

	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftNode = takeInput();
	BinaryTreeNode<int>* rightNode = takeInput();

	root->left = leftNode;
	root->right = rightNode;

	return root;
}

void print(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout << root->data << ":";

	if(root->left != NULL){
		cout << "L-" <<root->left->data;
	}

	if(root->right != NULL){
		cout << " R-" <<root->right->data;
	}
	cout << endl;
	print(root->left);
	print(root->right);
}

int main() {
	// Your code goes here;
	BinaryTreeNode<int>* root = takeInput();
	print(root);
	return 0;
}
