#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Table {
  int * head; // 声明一个名为head的数组，长度不定。即动态数组
  int length; // 记录当前表的长度
  int size; // 记录分配的容量
} table;

table initTable() {
  table t;
  t.head = (int*)malloc(SIZE * sizeof(int));

  if (!t.head) {
    printf("init failed.");
    exit(0);
  }

  t.length = 0;
  t.size = SIZE;

  return t;
}

void displayTable(table t) {
  for (int i=0; i<SIZE; i++) {
    printf("%d ", t.head[i]);
  }
  printf("\n");
}

int main() {
  table t = initTable();

  for (int i=1; i<=SIZE; i++) {
    t.head[i-1] = i;
    t.length++;
  }

  printf("display elements: \n");
  displayTable(t);

  return 0;
}
