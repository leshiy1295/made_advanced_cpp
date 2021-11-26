#include "030_static_inline.h"

/*
// try without include .h

#include <stdio.h>

void foo() {
    printf("another foo\n");
}

static void foo2();

inline void foo2() {
    printf("another foo2\n");
}
*/

void bar();

// try without extern keyword in .h file
// the only extern declaration for inline in .h is needed in all translation units
void foo2();

int main() {
    foo();
    bar();
    foo2();
}