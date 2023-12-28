#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;


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

int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int countEven() {
	struct Node* ptr = first;
	int cnt = 0;
	while (ptr != NULL) {
		if ((ptr->data) % 2 == 0) {
			cnt++;
		}
		ptr = ptr->next;
	}
	return cnt;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if ((ptr->data) % 2 == 1) {
			ptr->data = (ptr->data) * 10;
		}
		ptr = ptr->next;
	}
}

void elementsIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}


void main() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementsIx100(0);
	printList();

	elementsIx100(2);
	printList();

	elementsIx100(0);
	printList();

	{
		int x;
		scanf("%d", &x);
	}
}