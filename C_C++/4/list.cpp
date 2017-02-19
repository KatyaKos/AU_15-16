#include <cstdio>
#include <iostream>

using namespace std;

#define offset(X, Y) int(&((X*)0)->Y))
#define get(X, Y, Z) ((Y*)(int(X) - offset(Y, Z))

struct Node{
	Node* next;
	Node* prev;
};

struct IntNode{
	int x;
	Node n;
};

void Add(Node* n1, Node* n2){
	n2->next = n1->next;
	n1->next = n2;
	n2->next->prev = n2;
	n2->prev = n1;
}

void Remove(Node* n){
	n->prev->next = n->next;
	n->next->prev = n->prev;
}

Node* head;
Node* tail;

int main(){
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;

	IntNode node1;
	IntNode node2;
	Add(head, &node1.n);
	Add(&node1.n, &node2.n);
	cout << head->next << '\n';
	cout << head->next->next << '\n';

	get(&node1.n, IntNode, n)->x = 1;
	get(&node2.n, IntNode, n)->x = 5;
	cout << node1.x << ' ' << node2.x << '\n';

	Remove(&node1.n);
	cout << head->next << '\n';

	return 0;
}