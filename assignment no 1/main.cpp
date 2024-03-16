#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
void add_nodes(node*& head) {
	node* nnode{ nullptr }, * prev{ nullptr };
	char ch;
	nnode = prev = head;
	while (true) {
		nnode = new node;
		cout << "Enter data: "; cin >> nnode->data;
		nnode->next = nullptr;
		if (head == nullptr) {
			head = nnode;
			nnode = prev = head;
		}
		else {
			prev->next = nnode;
			prev = nnode;
		}
		cout << "Wants to add more. enter Y else N" << endl;
		cin >> ch;
		if (ch == 'N' or ch == 'n')
			break;
	}
}
void display(node* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}
int main() {
	node* head{ nullptr };
	add_nodes(head);
	display(head);
	return 0;
}