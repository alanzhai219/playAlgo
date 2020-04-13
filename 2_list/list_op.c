#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// defind a basic list
typedef struct Table {
  int * head;
  int length;
  int size;
} table;

table initTable() {
  table t;
  t.head = (int*)malloc(SIZE * sizeof(int));
  if (!t.head) {
    printf("failed init!");
    exit(0);
  }
  t.length = 0;
  t.size = SIZE;

  return t;
}

table addTable(table t, int ele, int loc) {
  // judge spare space for storing
  if (loc > t.length + 1 | loc < 1) {
    printf("check insertion location!");
    return t;
  }

  if (t.length >= t.size) {
    printf("will remalloc space.");
    t.head = (int*)realloc(t.head, (t.size+1) * sizeof(int));
    if (!t.head) {
      printf("failed remalloc");
      return t;
    }
    t.size += 1;
  }
  for (int i=t.length-1; i>=loc-1; i--) {
    t.head[i+1] = t.head[i];
  }

  t.head[loc-1] = ele;
  t.length++;
  return t;
}

table delTable(table t, int loc) {
  if (loc > t.length | loc < 1) {
    printf("no such index");
    return t;
  }
  for (int i=loc-1; i<=t.length-1; i++) {
    t.head[i] = t.head[i+1];
  }
  t.length--;
  return t;
}

int selectTable(table t, int ele) {
  for (int i=0; i<t.length; i++) {
    if (t.head[i] == ele) {
      return i+1;
    }
  }
  return -1;
}

table amendTable(table t, int ele, int newEle) {
  int loc = selectTable(t, ele);
  t.head[loc-1] = newEle;
  return t;
}

void displayTable(table t) {
  for (int i=0; i<t.length; i++) {
    printf("%d ", t.head[i]);
  }
  printf("\n");
}

int main() {
  table t1 = initTable();
  for (int i=1; i<SIZE; i++) {
    t1.head[i-1] = i;
    t1.length++;
  }

  printf("origin table: \n");
  displayTable(t1);

  printf("delete table: \n");
  t1 = delTable(t1, 1);
  displayTable(t1);

  printf("insert 5 @ index 2");
  table t2 = addTable(t1, 5, 2);
  displayTable(t2);

  printf("search 3 in table: \n");
  int loc = selectTable(t1, 3);
  printf("%d\n", loc);

  printf("change element in table: \n");
  t1 = amendTable(t1, 3, 6);
  displayTable(t1);

  return 0;
}
