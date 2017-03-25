#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

Node * createLink(int *array, int len);
void showLink(const Node * node);

int main() {

	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Node *node = createLink(array, 10);
	showLink(node);
	cout << "test" << endl;
	return 0;
}

Node * createLink(int *array, int len){

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

void showLink(const Node * node){

	if(NULL == node)return;
	const Node *temp = node;
	while(temp!=NULL){
		cout << temp->data<< endl;
		temp = temp->next;
	}

}
