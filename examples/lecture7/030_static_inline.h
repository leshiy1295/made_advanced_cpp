#include <stdio.h>

static inline void foo() {
    printf("foo()\n");
}

// try to uncomment extern
/*extern*/ inline void foo2() {
    printf("foo2()\n");
}