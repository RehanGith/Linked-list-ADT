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
void odd_after_even(node*& head) {
	node* temp{ nullptr }, * head2{ nullptr }, * temp2{ nullptr }, * nnode{ head };
	temp = head;
	if (nnode->data % 2)
		nnode = nnode->next;
	else
		head = nullptr;
	while (nnode) {
		if (nnode->data % 2) {
			if (!head)
				head = nnode;
			else
				temp->next = nnode;
			temp = nnode;
		}
		else {
			if (!head2)
				head2 = nnode;
			else
				temp2->next = nnode;
			temp2 = nnode;
		}
		nnode = nnode->next;
	}
	if (head2) {
		temp2->next = nullptr;
		temp->next = head2;
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
	odd_after_even(head);
	cout << endl;
	display(head);
	node* temp{ nullptr };
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
	return 0;
}