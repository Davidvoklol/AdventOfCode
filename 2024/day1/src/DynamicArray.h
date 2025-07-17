#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct DArray {
	size_t membsize;
	size_t size;
	size_t length;
	void* array;
};

struct DArray* NewDArray(size_t init_size, size_t membsize);
void FreeDArray(struct DArray* array, void (*const free_member)(const void* member));
void* SetDArray(
		struct DArray* array,
		const void* item,
		const unsigned int index,
		void* (*const copy_item)(void* dest, const void* item, size_t size),
		void* (*const free_overriden_member)(const void* member)
);
 void* GetDArray(const struct DArray* array, const unsigned int index);
 void* InsertDArray(
		struct DArray* array,
		const void* item,
		const unsigned int index,
		void* (*const copy_item)(void* dest, const void* item, size_t size)
);
void* RemoveDArray(struct DArray* array, unsigned int index, void (*const free_member)(const void* member));
void* AppendDArray(
		struct DArray* array, 
		const void* item, 
		void* (*const copy_item)(void* dest, const void* item, size_t size)
);
void* PopDArray(struct DArray* array, void (*const free_member)(const void* member));
