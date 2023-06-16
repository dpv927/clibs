#pragma once
#define DEF_ARL_SIZE 16

typedef struct ArrayList ArrayList;

struct ArrayList {
	void** data;
	size_t len;
	size_t capacity;
};

ArrayList* Al_createNew();
ArrayList* Al_createNewSized(size_t size);
void add(ArrayList* list, void* element);
void add(ArrayList* list, void* element, size_t index);
size_t Al_clear(ArrayList* list);