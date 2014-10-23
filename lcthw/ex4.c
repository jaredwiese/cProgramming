#include <stdio.h>

/* Warning: This program is wrong on purpose.
Using this to learn Valgrind
http://valgrind.org/ */

int main()
{
    int age = 10;
    int height;

    printf("I am %d years old.\n");
    printf("I am %d inches tall.\n", height);

    return 0;
}
