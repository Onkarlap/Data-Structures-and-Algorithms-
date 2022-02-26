#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>

using namespace std;
template <typename T>

class TreeNode{
	public:
	T data;       		                    // data to be stored in node
	vector<TreeNode<T>*> children;			 // vector of TreeNode pointers to store children of node	

	TreeNode(T data){
		this->data = data;
	}
};

// take input level wise

TreeNode<int>* takeInput(){
	// Create root node
	int rootData;
	cout << "Enter the root data: " << endl;
	cin >> rootData;

	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	// create a queue and push nodes whose childrens are yet to be asked for in input 
	queue<TreeNode<int>*> pending;
	pending.push(root);

	// loop till all the nodes are asked, i.e. queue gets empty
	while(pending.size() != 0){

		TreeNode<int>* front = pending.front();		// access front element and input all its childrens
		pending.pop();					// pop it up as its childrens are taken care of

		int num;
		cout << "Enter no of children of " << front->data << endl;

		for(int i=0; i<num; i++){
			int childData;
			cout << "Enter data of " << i <<"th child of " << front->data << endl;
			cin >> childData;

			TreeNode<int>* child = new TreeNode<int>(childData);		// create child of given front node
			pending.push(child);						// push the child in queue to further take its children
			front->children.push_back(child);				// push child in children vector
		}
	}

	return root;
}

// print level wise

void print(TreeNode<int>* root){
	
	// create a queue similar to that of input function
	queue<TreeNode<int>*> pending;
	pending.push(root);
	
	while(pending.size() != 0){
		TreeNode<int>* front = pending.front();
		cout << front->data << " : ";
		
		for(int i=0; i<front->children.size(); i++){
			cout << front->children[i]->data << ",";
			pending.push(front->children[i]);
		}
		
		cout << endl;
		pending.pop();
	}
}

int main() {
	// Your code goes here;
	TreeNode<int>* root = takeInput();
	print(root);
	return 0;
}
