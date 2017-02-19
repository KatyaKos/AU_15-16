#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <new>
#include <cassert>

using namespace std;

#define offset(X, Y) int(&((X*)0)->Y))
#define get(X, Y, Z) ((Y*)(int(X) - offset(Y, Z))

struct Node{
	Node* next;
	Node* prev;
};

struct MyNode{
	int x, y;
	unsigned char c;
	Node n;
};

void Add(Node* n1, Node* n2){
	n2->next = n1->next;
	n1->next = n2;
	n2->next->prev = n2;
	n2->prev = n1;
}

void read_txt(FILE* fin, Node* head){

	Node* start = head;
	int x, y;

	while (!feof(fin)){
		fscanf(fin, "%d %d\n", &x, &y);
		MyNode* node = new MyNode;
		node->x = x;
		node->y = y;
		Add(start, &(node->n));
		start = start->next;
	}
}

void read_bin(FILE* fin, Node* head){
	long lSize;
	fseek(fin, 0, SEEK_END);
	lSize = ftell(fin);
	rewind(fin);
	Node* start = head;
	
	for (int i = 0; i < lSize; i++){
		MyNode* node = new MyNode;
		fread(&(node->c), sizeof(unsigned char), 1, fin);
		Add(start, &(node->n));
		start = start->next;
	}

}

void write_txt(FILE* fout, Node* head, Node* tail){
	Node* start = head;
	while (start->next != tail){
		start = start->next;
		fprintf(fout, "%d %d\n", get(start, MyNode, n)->x, get(start, MyNode, n)->y);
	}
}

void write_bin(FILE* fout, Node* head, Node* tail){
	Node* start = head;
	while (start->next != tail){
		start = start->next;
		fwrite(&get(start, MyNode, n)->c, sizeof(unsigned char), 1, fout);
	}
}


int main(){

	Node* head = new Node;
	Node* tail = new Node;
	head->next = tail;
	tail->prev = head;
	string command1, command2;

	while (1 == 1){
		cin >> command1;

		if (command1 == "exit"){
			break;
		}

		cin >> command2;

		if (command1 == "read"){

			head->next = tail;

			FILE* fin;
			if (command2 == "txt"){
				fin = fopen("in.txt", "r");
				read_txt(fin, head);
			} else{
				fin = fopen("au.in", "rb");
				read_bin(fin, head);
			}
		}

		if (command1 == "write"){

			FILE * fout;
			if (command2 == "txt"){
				fout = fopen("out.txt", "w");
				write_txt(fout, head, tail);
			}else{
				fout = fopen("au.out", "wb");
				write_bin(fout, head, tail);
			}
		}

	}
	return 0;
}