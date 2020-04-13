#include <stdio.h>
#include <stdlib.h>

// define a Node
typedef struct Node {
  int elem; // data
  struct Node *next;  // ptr to next Node
} node;

// initialize a link
node * initNode();

// display link
void displayLink(node*);

int main() {
  // init (1,2,3,4)
  printf("init link: \n");
  node *p = initNode();
  displayLink(p);

  return 0;
}

node* initNode() {
  node * p = NULL;  //create head ptr
  node * temp = (node*)malloc(sizeof(node)); // create a first node
  // init first node
  temp->elem = 1;
  temp->next = NULL;

  // link to head ptr
  p = temp;
  for (int i=2; i<5; i++) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->elem = i;
    newNode->next = NULL;
    temp->next = newNode;
    temp = newNode;
  }

  return p;
}

void displayLink(node* p) {
  node* temp=p;
  while(temp) {
    printf("%d ", temp->elem);
    temp = temp->next;
  }
  printf("\n");
}
