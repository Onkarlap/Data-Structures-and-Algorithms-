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

TreeNode<int>* takeInput(){

	int rootData;
	cout << "Enter the root data: " << endl;
	cin >> rootData;

	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pending;
	pending.push(root);

	while(pending.size() != 0){

		TreeNode<int>* front = pending.front();
		pending.pop();

		int num;
		cout << "Enter no of children of " << front->data << endl;

		for(int i=0; i<num; i++){
			int childData;
			cout << "Enter data of " << i <<"th child of " << front->data << endl;
			cin >> childData;

			TreeNode<int>* child = new TreeNode<int>(childData);
			pending.push(child);
			front->children.push_back(child);
		}
	}

	return root;
}


int main() {
	// Your code goes here;

	return 0;
}
