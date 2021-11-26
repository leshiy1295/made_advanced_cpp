#include "030_static_inline.h"

// try without extern keyword in .h file
// the only extern declaration for inline in .h is needed in all translation units
// void foo2();

void bar() {
    foo();
    foo2();
}