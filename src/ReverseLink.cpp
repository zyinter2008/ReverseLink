#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node * createLink(int *array, int len);
void showLink(const Node * node);
Node * recurse(Node *node);
Node * nonRecurse(Node *node);

int main() {
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Node *node = createLink(array, 10);
	showLink(node);

//	Node *reverse = recurse(node);
//	showLink(reverse);

	Node *non = nonRecurse(node);
	showLink(non);

	return 0;
}

Node * createLink(int *array, int len) {
	if (NULL == array || 0 == len) {
		return NULL;
	}
	Node * head = new Node();
	head->data = array[0];
	head->next = NULL;
	Node *temp = head;

	for (int i = 1; i < len; i++) {
		Node *curr = new Node();
		curr->data = array[i];
		curr->next = NULL;
		temp->next = curr;
		temp = curr;
	}

	return head;
}

void showLink(const Node * node) {
	if (NULL == node)
		return;
	const Node *temp = node;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

Node * recurse(Node *node) {
	if (NULL == node || NULL == node->next) {
		return node;
	}
	Node *p = recurse(node->next);
	node->next->next = node;
	node->next = NULL;
	return p;

}

Node * nonRecurse(Node *node) {
	if (NULL == node || NULL == node->next) {
		return node;
	}
	Node *pre = NULL, *next = NULL, *link = node;

	while (link->next != NULL) {
		next = link->next;
		link->next = pre;
		pre = link;

		link = next;
	}

	link->next = pre;
	return link;
}
