#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Node{
	
	public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};

Node* insert(){
	int data;
	cin >> data;

	Node* head = NULL;
	Node* tail = NULL;
	while(data != -1){

		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}

	return head;
}

void printList(Node* head){
	
	Node* temp = head;
	while(temp != NULL){
		cout << temp-> data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	// Your code goes here;
	Node* head = insert();
	printList(head);
	return 0;
}
