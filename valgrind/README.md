1. compile
```bash
gcc -g leaktest.c -o leaktest
```
2. run valgrind
```bash
valgrind --tool=memcheck --leak-check=full ./leaktest
```

reference
http://senlinzhan.github.io/2017/12/31/valgrind/
