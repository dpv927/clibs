#include <stdlib.h>
#include "linkedList.h"

LinkedList* Ll_createNewEmpty(void) {
	LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
	if (list == NULL) { return NULL; }

	list->comparator = NULL;
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
	return list;
}

LinkedList* Ll_createNewComparable(const int(*comparer)(void*, void*)) {
	LinkedList* list = Ll_createNewEmpty();
	list->comparator = comparer;
	return list;
}

void Ll_addFirst(LinkedList* list, const void* value) {
	Ll_Node* newFirst = (Ll_Node*) malloc(sizeof(Ll_Node));
	newFirst->chld = list->head;
	newFirst->val = value;

	list->head = newFirst;
	list->len++;
	if (list->tail == NULL) {
		list->tail = list->head;
	}
}

void Ll_addLast(LinkedList* list, const void* element) {
	Ll_Node* newLast =  (Ll_Node*) malloc(sizeof(Ll_Node));
	newLast->chld = NULL;
	newLast->val = element;
	
	if (list->tail == NULL) {
		list->tail = newLast;
		list->head = list->tail;
	} else {
		(list->tail)->chld = newLast;
		list->tail = newLast;
	}
	list->len++;
}

void Ll_addAt(LinkedList* list, const uint index, const void* element) {
	if (index >= list->len) { Ll_addLast(list, element); }
	else {
		Ll_Node* pre_index = list->head;

		for (int i = 1; i < index; i++) {
			pre_index = pre_index->chld;
		}

		Ll_Node* old_index = pre_index->chld;
		Ll_Node* newNode = (Ll_Node*) malloc(sizeof(Ll_Node));

		newNode->chld = old_index;
		newNode->val = element;
		pre_index->chld = newNode;
		list->len++;
	}
}

void* Ll_removeFirst(LinkedList* list) {
	if (list->len == 0) { return NULL; }
	else {
		Ll_Node* target = list->head;
		list->head = (list->head)->chld;
		if (list->head == NULL) { list->tail = NULL; }
		list->len--;
		return target->val;
	}
}

void* Ll_removeLast(LinkedList* list) {
	if (list->len == 0) { return NULL; }
	
	Ll_Node* target;
	if (list->len == 1) {
		target = list->head;
		list->head = NULL;
		list->tail = NULL;		
	}
	else {
		Ll_Node* actual = list->head;
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

void* Ll_removeElementAt(LinkedList* list, const uint index) {
	if (index >= list->len) { return NULL; }
	if (index == 0) { return Ll_removeFirst(list); }
	if (index == list->len - 1) { return Ll_removeLast(list); }

	Ll_Node* actual = list->head;
	for (size_t i = 1; i < index; i++) {
		actual = actual->chld;
	}

	Ll_Node* target = actual->chld;
	actual->chld = target->chld;
	list->len--;
	return target->val;
}

void Ll_clear(LinkedList* list) {
	if (list->len == 0) return;

	Ll_Node* current = list->head;
	Ll_Node* next;

	while (current != NULL) {
		next = current->chld;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}

Bool Ll_contains(LinkedList* list, const void* value) {
	if (list->comparator == NULL) { return; }

	Ll_Node* current = list->head;
	while (current != NULL) {
		if (list->comparator(value, current->val) == 0) { return 1; }
		current = current->chld;
	}
	return 0;
}

void* Ll_getElementFrom(LinkedList* list, const uint index) {
	if (index >= list->len) { return NULL; }

	Ll_Node* current = list->head;
	for (size_t i = 0; i < index; i++) { current = current->chld; }
	return current->val;
}

Bool Ll_isEmpty(LinkedList* list) {
	return (list->len == 0);
}

int Ll_indexOf(LinkedList* list, const void* element) {
	if (list->comparator == NULL) { return -1; }

	Ll_Node* current = list->head;
	int i = 0;
	while (current != NULL) {
		if (list->comparator(element, current->val) == 0) { return i; }
		current = current->chld;
		i++;
	}
	return -1;
}

int Ll_lastIndexOf(LinkedList* list, const void* element) {
	if (list->comparator == NULL) { return -1; }

	Ll_Node* current = list->head;
	int lastIndex = -1, i = 0;

	while (current != NULL) {
		if (list->comparator(element, current->val) == 0) { lastIndex = i; }
		current = current->chld;
		i++;
	}
	return lastIndex;
}

void* Ll_setElementAt(LinkedList* list, const uint index, const void* element) {
	if (index >= list->len) { return NULL; }
	
	Ll_Node* current = list->head;
	void* oldValue;

	for (size_t i = 0; i < index; i++) { current = current->chld; }
	oldValue = current->val;
	current->val = element;
	return oldValue;
}