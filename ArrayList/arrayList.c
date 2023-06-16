#include <stdlib.h>
#include <limits.h>
#include "arrayList.h"

#define CODE_ERR 1
#define CODE_GDD 0

ArrayList* Al_createNewSized(const uint size) {
	if (size == 0) { return NULL; }

	ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
	if (list == NULL) { return NULL; }

	list->data = (void**) malloc(sizeof(void*) * size);
	if (list->data == NULL) { 
		free(list);
		return NULL; 
	}

	list->comparator = NULL;
	list->capacity = size;
	list->len = 0;
	return list;
}

ArrayList* Al_createNew() {
	return Al_createNewSized(DEF_ARL_SIZE);
}

ArrayList* Al_createNewComparable(const int(*comparer)(void*, void*)) {
	ArrayList* list = Al_createNewSized(DEF_ARL_SIZE);
	list->comparator = comparer;
	return list;
}

ArrayList* Al_createNewComparableSized(const int(*comparer)(void*, void*), const uint size) {
	ArrayList* list = Al_createNewSized(size);
	list->comparator = comparer;
	return list;
}

Bool Al_add(ArrayList* list, const void* element) {
	if (Al_ensureCapacity(list)) { return CODE_ERR; }
	list->data[list->len++] = element;
	return CODE_GDD;
}

Bool Al_addAt(ArrayList* list, const void* element, const uint index) {
	if (index > list->len || Al_ensureCapacity(list)) {
		return CODE_ERR;
	}

	for (uint i = list->len - 1; i >= index; i--) {
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = element;
	list->len++;
	return CODE_GDD;
}

void* Al_remove(ArrayList* list, const void* element) {
	if (list->comparator == NULL) { return NULL; }

	void** removed = NULL;
	int index = -1;

	for (uint i = 0; i < list->len-1; i++) {
		if (list->comparator(list->data[i], element) == 0) {
			removed = list->data[i];
			index = i;
			break;
		}
	}
	if (index == -1) { return NULL; } // not found
	
	for (uint i = index; i < list->len - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	list->data[list->len - 1] = NULL;
	list->len--;
	return removed;
}

void* Al_removeFrom(ArrayList* list, const uint index) {
	if (index < 0 || index > list->len - 1) { return NULL; }

	void* removed = list->data[index];
	for (uint i = index; i < list->len-1; i++) { 
		list->data[i] = list->data[i + 1];
	}
	list->data[list->len - 1] = NULL;
	list->len--;
	return removed;
}

void* Al_get(const ArrayList* list, const uint index) {
	if (index < 0 || list->len - 1 > index) { return NULL; }
	return list->data[index];
}

int Al_indexOf(const ArrayList* list, const void* element) {
	if (list->comparator == NULL) { return -1; }

	for (uint i = 0; i < list->len; i++) {
		if (list->comparator(list->data[i], element) == 0) {
			return i;
		}
	}
	return -1;
}

int Al_lastIndexOf(const ArrayList* list, const void* element) {
	if (list->comparator == NULL) { return -1; }

	int index = -1;
	for (uint i = 0; i < list->len; i++) {
		if (list->comparator(list->data[i], element) == 0) {
			index = i;
		}
	}
	return index;
}

Bool Al_contains(const ArrayList* list, const void* element) {
	if (list->comparator == NULL) { return 0; }
	for (uint i = 0; i < list->len; i++) {
		if (list->comparator(list->data[i], element) == 0) {
			return 1;
		}
	}
	return 0;
}

Bool Al_ensureCapacity(ArrayList* list) {
	if (list->len == list->capacity) {
		if (list->capacity == INT_MAX) { return CODE_ERR; }

		uint oldLength = list->capacity;
		uint minGrowth = (list->len + 1) - oldLength;
		uint prefGrowth = oldLength >> 1;

		uint prefLength = oldLength + (minGrowth > prefGrowth)? minGrowth : prefGrowth;
		prefLength = (prefLength > INT_MAX) ? INT_MAX : prefLength;

		// Reallocate the old arr at a bigger spot
		void** new_data = (void**) realloc(list->data, sizeof(void*) * prefLength);
		if (new_data == NULL) {
			return CODE_ERR;
		}
		list->data = new_data;
		list->capacity = prefLength;
	}
	return CODE_GDD;
}

Bool Al_trimToSize(ArrayList* list) {
	if (list->len != list->capacity) {
		void** new_data = (void**) realloc(list->data, sizeof(void*) * list->len);
		if (new_data == NULL) {
			return CODE_ERR;
		}

		list->data = new_data;
		list->capacity = list->len;
	}
	return CODE_GDD;
}

Bool Al_clear(ArrayList* list) {
	if (list == NULL || list->data == NULL) { return CODE_ERR; }

	for (uint i = 0; i < list->len; i++)
		free(list->data[i]);
	list->len = 0;

	void** new_data = (void**) realloc(list->data, sizeof(void*) * DEF_ARL_SIZE);
	if (new_data == NULL) { return CODE_ERR; }
	
	list->data = new_data;
	list->capacity = DEF_ARL_SIZE;
	return CODE_GDD;
}