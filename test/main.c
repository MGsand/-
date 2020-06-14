#include <stdio.h>

#define CTEST_MAIN

#define CTEST_SEGFAULT

#include "ctest.h"

int main(int argc, const char** argv)
{
    printf("\nNOTE: some tests will fail, just to show how ctest works! ;)\n");
    return ctest_main(argc, argv);
}
