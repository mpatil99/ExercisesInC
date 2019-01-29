#include <stdio.h>

int main() {
    int x = 5;
    printf("%i",x);
    int y = x + 1;
    printf("%i",y);
    return 0;
}
/*
1subq	$16, %rsp
movl	$5, -4(%rbp)

These were the lines added
the number following the $ is the value stored at an address?
2  The assembly file becomes shorter

3 Again, the assembly file shrinks

4 Once, more the number of lines is reduced

5 I would assume that that the optimize function optimize the number of lines
produced in the assembly file
*/
