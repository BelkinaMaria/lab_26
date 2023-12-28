#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * first = NULL;


void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

void printList() {
	struct Node* pointer = first;
	while (pointer != NULL) {
		printf("(%d) -> ", pointer->data);
		pointer = pointer->next;
	}
	printf("NULL\n");
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int containts(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}


void main() {
	first = NULL;
	printList();

	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	int a = deleteFromHead();
	printf("(%d)\n", a);
	printList();

	a = containts(10);
	printf("10?   %d\n", a);

	a = containts(15);
	printf("15?   %d\n", a);

	clearList();
	printList();
}