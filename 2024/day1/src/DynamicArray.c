#include "./DynamicArray.h"

struct DArray* NewDArray(size_t init_size, size_t membsize) {
	if (membsize == 0 || init_size == 0) return NULL;

	void* array = calloc(init_size, membsize);
	if (!array) return NULL;

	struct DArray* darray = malloc(sizeof(struct DArray));
	if (!darray) {
		free(array);
		return NULL;
	}

	darray->membsize = membsize;
	darray->size = init_size;
	darray->array = array;
	darray->length = 0;

	return darray;
}

void FreeDArray(struct DArray* array, void (*const free_member)(const void* member)) {
	if (array) {
		if (free_member) {
			for (size_t i = 0; i < array->length; i++) {
				void* current = array->array + i * array->membsize;
				if (current) free_member(current);
			}
		}
		free(array->array);
		free(array);
	}
}

struct DArray* _GrowArray(struct DArray* array, size_t new_size) {
	if (!array || new_size <= array->size) return NULL;
	void* new_array = realloc(array->array, new_size * array->membsize);
	if (!new_array) return NULL;
	const size_t old_size = array->size;
	array->array = new_array;
	array->size = new_size;
	return memset(array->array + old_size * array->membsize, 0, (new_size - old_size) * array->membsize);
}

void* SetDArray(
		struct DArray* array,
		const void* item,
		const unsigned int index,
		void* (*const copy_item)(void* dest, const void* item, size_t size),
		void* (*const free_overriden_member)(const void* member)
) {
	if (!array) return NULL;

	if (index >= array->size) {
		int new_size = array->size * 2;
		while (index >= new_size) new_size *= 2;
		if (!_GrowArray(array, new_size)) return NULL;
	}
	void* dest = array->array + index * array->membsize;

	if (free_overriden_member && index < array->length) free_overriden_member(array->array + index * array->membsize);

	void* success;
	if (item && copy_item) success = (void*)copy_item(dest, item, array->membsize);
	else if (!item && index < array->length) success = memset(dest, 0, array->membsize);

	if (item && index >= array->length)
		array->length = index + 1;
	else if (!item && index == array->length - 1)
		array->length--;

	return success;
}

void* GetDArray(const struct DArray* array, const unsigned int index) {
	if (array && index < array->length) return array->array + index * array->membsize;
	return NULL;
}

void* InsertDArray(
		struct DArray* array,
		const void* item,
		const unsigned int index,
		void* (*const copy_item)(void* dest, const void* item, size_t size)
) {
	if (!array || index > array->length) return NULL;
	if (array->length + 1 > array->size && !_GrowArray(array, array->size * 2)) return NULL;
	void* src = array->array + index * array->membsize;
	void* dest = array->array + (index + 1) * array->membsize;
	void* success = memmove(dest, src, (array->length - index) * array->membsize);
	if (success) array->length++;
	success = SetDArray(array, item, index, copy_item, NULL);
	return success;
}

void* RemoveDArray(struct DArray* array, unsigned int index, void (*const free_member)(const void* member)) {
	if (!array || index >= array->length) return NULL;
	void* src = array->array + (index + 1) * array->membsize;
	void* dest = array->array + index * array->membsize;
	if (free_member) free_member(array->array + index * array->membsize);
	void* success = memmove(dest, src, (array->length - index - 1) * array->membsize);
	if (success) {
		memset(array->array + array->length * array->membsize, 0, array->membsize);
		array->length--;
		return array->array;
	}
	return NULL;
}

void* AppendDArray(
		struct DArray* array, 
		const void* item, 
		void* (*const copy_item)(void* dest, const void* item, size_t size)
) {
	if (!array) return NULL;
	return SetDArray(array, item, array->length, copy_item, NULL);
}

void* PopDArray(struct DArray* array, void (*const free_member)(const void* member)) {
	if (array) return RemoveDArray(array, (array->length - 1), free_member);
	else return NULL;
}
