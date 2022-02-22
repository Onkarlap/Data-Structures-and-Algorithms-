#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
template <typename T>

// TreeNode class
class TreeNode{
	public:
	T data;       		                    // data to be stored in node
	vector<TreeNode<T>*> children;			 // vector of TreeNode pointers to store children of node	

	TreeNode(T data){
		this->data = data;
	}
};

// take input using recursion, returns root of Tree
TreeNode<int>* takeInput(){
	int rootData;						    // value of rootData
	cout << "Enter root data:" << endl;
	cin >> rootData;

	// create a TreeNode with rootData
	TreeNode<int>* root = new TreeNode<int>(rootData);

	// ask for number of children of root
	cout<<"Enter number of children of " << rootData << endl;
	int num;
	cin >> num;
	
	// loop over each children for there children

	for(int i=0; i<num; i++){
		TreeNode<int>* child = takeInput();    // returns root of the subtree which is taken as child of current root
		root->children.push_back(child);       // push child of tree in children vector;
	}

	return root;			
}

// print tree recursively

void print(TreeNode<int>* root){
	
	// print root data
	cout << root->data << ":";

	// print children of current root
	for(int i=0; i<root->children.size(); i++){
		cout << root->children[i]->data << ",";
	} 
	cout << endl;

	// recursive call on each child
	for(int i=0; i<root->children.size(); i++){
		print(root->children[i]);
	}

}


int main() {
	// Your code goes here;
	TreeNode<int>* root = takeInput();
	print(root);
	return 0;
}		
