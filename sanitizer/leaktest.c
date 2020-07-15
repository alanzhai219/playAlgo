#include <stdlib.h>

char leaktest() {
  char *x = (char*)malloc(10 * sizeof(char*));
  return x[5];
}

int main(int argc, char* argv) {
  leaktest();
  return 0;
}
