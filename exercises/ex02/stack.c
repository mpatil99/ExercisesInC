/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
/*
1. The code appears to be be filling and array of size 5 with the element 42 in
each position.
The main method than prints it

2. I get a warning that foo returns the address of a local variable. Because an
array is created directly in stack space, the address is in the current stack
frame. This could cause issues when another stack frame is plopped on top.

3. I get a segmentation fault. This probably occurs because the bar() method
creates another stack frame where the array is previously stored.

4. The address of the array created in bar() is the same as the address of the
 array created in the foo() method.

5. Weird things happen when you return a pointer to stack allocated memory.
First, when a new stack frame is created you will run into issues because that
area is being overwritten, which C will happily do.
Second, when a pointer to a new address is created it will return a pointer to
the same address that held the older array
*/
