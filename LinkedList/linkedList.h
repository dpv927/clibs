#pragma once

typedef struct Ll_Node Ll_Node;
typedef struct LinkedList LinkedList;
typedef unsigned char Bool;
typedef unsigned int uint;

struct Ll_Node {
	Ll_Node* chld;
	void* val;
};

struct LinkedList {
	int (*comparator)(void*, void*);
	Ll_Node* head;
	Ll_Node* tail;
	uint len;
};

/**
 * @brief Creates a new empty linked list.
 * 
 * @return Pointer to the new empty linked list. **/
LinkedList* Ll_createNewEmpty(void);

/**
 * @brief Creates a new linked list with a comparator for the elements.
 *
 * @param comparer Pointer to the comparator function that compares two elements.
 * @return Pointer to the new linked list with the specified comparator. */
LinkedList* Ll_createNewComparable(int(*comparer)(void*, void*));

/**
 * @brief Adds an element to the beginning of the linked list.
 *
 * @param list Pointer to the linked list.
 * @param value Pointer to the element to be added. **/
void Ll_addFirst(LinkedList* list, void* value);

/**
 * @brief Adds an element to the end of the linked list.
 *
 * @param list Pointer to the linked list.
 * @param value Pointer to the element to be added. **/
void Ll_addLast(LinkedList* list, void* value);

/**
 * @brief Adds an element at a specific position in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param index The index at which the element should be added.
 * @param element Pointer to the element to be added. **/
void Ll_addAt(LinkedList* list, const uint index, void* element);

/**
 * @brief Removes and returns the first element from the linked list.
 *
 * @param list Pointer to the linked list.
 * @return Pointer to the removed element. **/
void* Ll_removeFirst(LinkedList* list);

/**
 * @brief Removes and returns the last element from the linked list.
 *
 * @param list Pointer to the linked list.
 * @return Pointer to the removed element. **/
void* Ll_removeLast(LinkedList* list);

/**
 * @brief Removes and returns the element at a specific position in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param index The index of the element to be removed.
 * @return Pointer to the removed element. **/
void* Ll_removeElementAt(LinkedList* list, const uint index);

/**
 * @brief Clears the linked list, removing all elements and freeing all the 
 * allocated memory if necessary.
 * 
 * @param list Pointer to the linked list. 
 * @param clrfun Pointer to a function that frees the memory of the type
 * of data that is being stored in the list. This pointer must be NULL if the stored
 * data is not being allocated with a function like malloc, realloc, etc.**/
void Ll_clear(LinkedList* list, void(*clrfun)(void*));

/**
 * @brief Checks if the linked list contains a specific element.
 *
 * @param list Pointer to the linked list.
 * @param element Pointer to the element to be checked.
 * @return 1 if the element is found, 0 otherwise. **/
Bool Ll_contains(LinkedList* list, void* element);

/**
 * @brief Retrieves the element at a specific index in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param index The index of the element to retrieve.
 * @return Pointer to the element at the specified index. **/
void* Ll_getElementFrom(LinkedList* list, const uint index);

/**
 * @brief Checks if the linked list is empty.
 *
 * @param list Pointer to the linked list.
 * @return 1 if the linked list is empty, 0 otherwise. **/
Bool Ll_isEmpty(LinkedList* list);

/**
 * @brief Returns the last index of a specific element in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param element Pointer to the element to search for.
 * @return The last index of the element, or -1 if it is not found. **/
int Ll_lastIndexOf(LinkedList* list, void* element);

/**
 * @brief Returns the index of the first occurrence of a specific element in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param element Pointer to the element to search for.
 * @return The index of the element, or -1 if it is not found. **/
int Ll_indexOf(LinkedList* list, void* element);

/**
 * @brief Sets the element at a specific index in the linked list.
 *
 * @param list Pointer to the linked list.
 * @param index The index of the element to be set.
 * @param element Pointer to the new element.
 * @return Pointer to the previous element at the specified index. **/
void* Ll_setElementAt(LinkedList* list, const uint index, void* element);
