#include <stdlib.h>
#include "linkedList.h"

LinkedList* Ll_createNewEmpty(void) {
	LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
	list->comparator = NULL;
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
	return list;
}

LinkedList* Ll_createNewBased(void* value) {
	LinkedList* list = Ll_createNewEmpty();
	Ll_addLast(list, value);
	return list;
}

LinkedList* Ll_createNewComparable(int(*comparer)(void*, void*)) {
	LinkedList* list = Ll_createNewEmpty();
	list->comparator = comparer;
	return list;
}

LinkedList* Ll_createNewBasedComparable(int(*comparer)(void*, void*), void* value) {
	LinkedList* list = Ll_createNewEmpty();
	list->comparator = comparer;
	Ll_addLast(list, value);
	return list;
}

void Ll_addFirst(LinkedList* list, void* value) {
	Node* newFirst = (Node*) malloc(sizeof(Node));
	newFirst->chld = list->head;
	newFirst->val = value;

	list->head = newFirst;
	list->len++;
	if (list->tail == NULL) {
		list->tail = list->head;
	}
}

void Ll_addLast(LinkedList* list, void* value) {
	Node* newLast =  (Node*) malloc(sizeof(Node));
	newLast->chld = NULL;
	newLast->val = value;
	
	if (list->tail == NULL) {
		list->tail = newLast;
		list->head = list->tail;
	} else {
		(list->tail)->chld = newLast;
		list->tail = newLast;
	}
	list->len++;
}

void Ll_addAt(LinkedList* list, int index, void* value) {
	if (index <= 0) { Ll_addFirst(list, value); }
	else if (index >= list->len) { Ll_addLast(list, value); }
	else {
		Node* pre_index = list->head;

		for (int i = 1; i < index; i++) {
			pre_index = pre_index->chld;
		}

		Node* old_index = pre_index->chld;
		Node* newNode = (Node*) malloc(sizeof(Node));

		newNode->chld = old_index;
		newNode->val = value;
		pre_index->chld = newNode;
		list->len++;
	}
}

void* Ll_removeFirst(LinkedList* list) {
	if (list->len == 0) { return NULL; }
	else {
		Node* target = list->head;
		list->head = (list->head)->chld;
		if (list->head == NULL) { list->tail = NULL; }
		list->len--;
		return target->val;
	}
}

void* Ll_removeLast(LinkedList* list) {
	if (list->len == 0) { return NULL; }
	
	Node* target;
	if (list->len == 1) {
		target = list->head;
		list->head = NULL;
		list->tail = NULL;		
	}
	else {
		Node* actual = list->head;
		for (int i = 1; i < list->len-1; i++) {
			actual = actual->chld;
		}
		target = list->tail;
		list->tail = actual;
		(list->tail)->chld = NULL;
	}
	list->len--;
	return target->val;
}

void* Ll_removeElementAt(LinkedList* list, int index) {
	if (index < 0 || index >= list->len) { return NULL; }
	if (index == 0) { return Ll_removeFirst(list); }
	if (index == list->len - 1) { return Ll_removeLast(list); }

	Node* actual = list->head;
	for (int i = 1; i < index; i++) {
		actual = actual->chld;
	}

	Node* target = actual->chld;
	actual->chld = target->chld;
	list->len--;
	return target->val;
}

void Ll_clear(LinkedList* list) {
	if (list->len == 0) return;

	Node* current = list->head;
	Node* next;

	while (current != NULL) {
		next = current->chld;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}

int Ll_contains(LinkedList* list, void* value) {
	Node* current = list->head;
	while (current != NULL) {
		if (list->comparator(value, current->val) == 0) { return 1; }
		current = current->chld;
	}
	return 0;
}

void* Ll_getElementFrom(LinkedList* list, int index) {
	if (index < 0 || index >= list->len) { return NULL; }

	Node* current = list->head;
	for (int i = 0; i < index; i++) { current = current->chld; }
	return current->val;
}

int Ll_isEmpty(LinkedList* list) {
	return (list->len == 0);
}

int Ll_indexOf(LinkedList* list, void* element) {
	Node* current = list->head;
	int i = 0;

	while (current != NULL) {
		if (list->comparator(element, current->val) == 0) { return i; }
		current = current->chld;
		i++;
	}
	return -1;
}

int Ll_lastIndexOf(LinkedList* list, void* element) {
	Node* current = list->head;
	int lastIndex = -1, i = 0;

	while (current != NULL) {
		if (list->comparator(element, current->val) == 0) { lastIndex = i; }
		current = current->chld;
		i++;
	}
	return lastIndex;
}

void* Ll_setElementAt(LinkedList* list, int index, void* element) {
	if (index < 0 || index >= list->len) { return NULL; }
	
	Node* current = list->head;
	void* oldValue;

	for (int i = 0; i < index; i++) { current = current->chld; }
	oldValue = current->val;
	current->val = element;
	return oldValue;
}