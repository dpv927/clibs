#pragma once
#define DEF_ARL_SIZE 16

typedef struct ArrayList ArrayList;
typedef unsigned char Bool;
typedef unsigned int uint;

struct ArrayList {
	int (*comparator)(void*, void*);
	void** data;
	uint len;
	uint capacity;
};

/**
 * @brief Creates a new ArrayList with default capacity.
 *
 * @return A pointer to the newly created ArrayList. **/
ArrayList* Al_createNew(void);

/**
 * @brief Creates a new ArrayList with the specified initial capacity.
 *
 * @param size The initial capacity of the ArrayList.
 * @return A pointer to the newly created ArrayList. **/
ArrayList* Al_createNewSized(const uint size);

/**
 * @brief Creates a new ArrayList with the specified element comparer function.
 *
 * @param comparer The function used to compare elements in the ArrayList.
 * @return A pointer to the newly created ArrayList. **/
ArrayList* Al_createNewComparable(const int(*comparer)(void*, void*));

/**
 * @brief Creates a new ArrayList with the specified element comparer function and
 * initial capacity.
 *
 * @param comparer The function used to compare elements in the ArrayList.
 * @param size The initial capacity of the ArrayList.
 * @return A pointer to the newly created ArrayList. **/
ArrayList* Al_createNewComparableSized(const int(*comparer)(void*, void*), const uint size);

/**
 * @brief Adds an element to the end of the ArrayList.
 *
 * @param list The ArrayList to which the element will be added.
 * @param element The element to be added.
 * @return True if the element was successfully added, False otherwise. **/
Bool Al_add(ArrayList* list, const void* element);

/**
 * @brief Adds an element at the specified index in the ArrayList.
 *
 * @param list The ArrayList to which the element will be added.
 * @param element The element to be added.
 * @param index The index at which the element will be added.
 * @return True if the element was successfully added, False otherwise. **/
Bool Al_addAt(ArrayList* list, const void* element, const uint index);

/**
 * @brief Removes the first occurrence of the specified element from the ArrayList.
 *
 * @param list The ArrayList from which the element will be removed.
 * @param element The element to be removed.
 * @return A pointer to the removed element, or NULL if the element was not found. **/
void* Al_remove(ArrayList* list, const void* element);

/**
 * @brief Removes the element at the specified index from the ArrayList.
 *
 * @param list The ArrayList from which the element will be removed.
 * @param index The index of the element to be removed.
 * @return A pointer to the removed element, or NULL if the index is out of range. **/
void* Al_removeFrom(ArrayList* list, const uint index);

/**
 * @brief Retrieves the element at the specified index from the ArrayList.
 *
 * @param list The ArrayList from which the element will be retrieved.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index, or NULL if the index
 * is out of range. **/
void* Al_get(const ArrayList* list, const uint index);

/**
 * @brief Returns the index of the first occurrence of the specified element in the
 * ArrayList.
 *
 * @param list The ArrayList to search for the element.
 * @param element The element to search for.
 * @return The index of the first occurrence of the element, or -1 if the element 
 * was not found. **/
int Al_indexOf(const ArrayList* list, const void* element);

/**
 * @brief Returns the index of the last occurrence of the specified element in the
 * ArrayList.
 *
 * @param list The ArrayList to search for the element.
 * @param element The element to search for.
 * @return The index of the last occurrence of the element, or -1 if the element was
 * not found. **/
int Al_lastIndexOf(const ArrayList* list, const void* element);

/**
 * @brief Checks if the ArrayList contains the specified element.
 *
 * @param list The ArrayList to check.
 * @param element The element to check for.
 * @return True if the element is found in the ArrayList, False otherwise. **/
Bool Al_contains(const ArrayList* list, const void* element);

/**
 * @brief Ensures that the ArrayList has enough capacity to accommodate 
 * additional elements.
 *
 * @param list The ArrayList to ensure the capacity for.
 * @return True if the capacity was successfully ensured, False otherwise. **/
Bool Al_ensureCapacity(ArrayList* list);

/**
 * @brief Trims the capacity of the ArrayList to match its current length.
 *
 * @param list The ArrayList to trim.
 * @return True if the ArrayList was successfully trimmed, False otherwise. **/
Bool Al_trimToSize(ArrayList* list);

/**
 * @brief Clears the ArrayList, removing all elements.
 *
 * @param list The ArrayList to clear.
 * @return True if the ArrayList was successfully cleared, False otherwise. **/
Bool Al_clear(ArrayList* list);