#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

Node * CreateLink(int *array, int len){

	if(NULL == array|| 0 ==len ){
		return NULL;
	}
	Node * head = new Node();
	head->data = array[0];
	head->next = NULL;
	Node *temp = head;

	for(int i =1; i< len;i++){
		Node *curr = new Node();
		curr->data = array[i];
		curr->next =NULL;
		temp->next = curr;
		temp = curr;
	}

	return head;
}

int main() {

	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Node *node = CreateLink(array, 10);

	cout << "test" << endl;
	return 0;
}
