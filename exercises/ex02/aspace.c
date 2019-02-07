/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
void aprinter(int var);

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *t = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of main is %p\n", aprinter);
    printf ("Address of var1 is %p\n", &var1);
    aprinter(var2);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("t points to %p\n", t);
    printf ("s points to %p\n", s);

    int *n = malloc(32);
    int *k = malloc(32);

    printf ("n points to %p\n", n);
    printf ("k points to %p\n", k);



    return 0;
}

void aprinter(int var){
  printf ("Address of var is %p\n", &var);
}
/*
3. Image in Notes
4. The Heap does grow upwords
5. I am rather confused about what the question is asking. But the area in the
stack did grow down when this function was called
6. The space between them is 33 bytes
*/
