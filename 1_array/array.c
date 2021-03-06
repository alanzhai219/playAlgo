#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
  int size;
  int used;
  int *arr;
};

void dump(struct array *array) {
  int idx;
  for (idx=0; idx < array->used; idx++) {
    printf("[%02d]: %08d\n", idx, array->arr[idx]);
  }
}

int insert(struct array *array, int elem) {
  int idx;
  if (array->used >= array->size) {
    return -1;
  }
  
  for (idx = 0; idx < array->used; idx++) {
    if (array->arr[idx] > elem) {
      break;
    }
  }

  if (idx < array->used) {
    memmove(&array->arr[idx+1], &array->arr[idx],
        (array->used - idx) * sizeof(int));
  }

  array->arr[idx] = elem;
  array->used++;
  return idx;
}

void alloc(struct array *array) {
  array->arr = (int *)malloc(array->size * sizeof(int));
}

int main() {
  int idx;
  struct array ten_int = {10, 0, NULL};

  alloc(&ten_int);
  if (!ten_int.arr) {
    return -1;
  }

  insert(&ten_int, 1);
  insert(&ten_int, 3);
  insert(&ten_int, 2);
  dump(&ten_int);

  return 0;
}
