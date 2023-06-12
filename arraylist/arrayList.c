#include <stdlib.h>
#include "arrayList.h"
#define CODE_ERR 1
#define CODE_GDD 0

ArrayList* Al_createNew() {
	ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
	if (list == NULL) { return NULL; }

	list->data = (void**) malloc(sizeof(void*) * DEF_ARL_SIZE);
	if (list->data == NULL) { 
		free(list);
		return NULL; 
	}

	list->capacity = DEF_ARL_SIZE;
	list->len = 0;
	return list;
}

ArrayList* Al_createNewSized(size_t size) {
	ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
	if (list == NULL) { return NULL; }

	list->data = (void**) malloc(sizeof(void*) * size);
	if (list->data == NULL) { 
		free(list);
		return NULL; 
	}

	list->capacity = size;
	list->len = 0;
	return list;
}

void add(ArrayList* list, void* element) {

}

void add(ArrayList* list, void* element, size_t index) {

}

size_t Al_clear(ArrayList* list) {
	if (list == NULL || list->data == NULL) { return CODE_ERR; }

	for (size_t i = 0; i < list->len; i++)
		free(list->data[i]);
	list->len = 0;

	void** new_data = (void**) realloc(list->data, sizeof(void*) * DEF_ARL_SIZE);
	if (new_data == NULL) { return CODE_ERR; }
	
	list->data = new_data;
	list->capacity = DEF_ARL_SIZE;
	return CODE_GDD;
}