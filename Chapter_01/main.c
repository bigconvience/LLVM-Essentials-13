#include <stdio.h>

extern int add(int);

int main() {
    int a = add(2);
    printf("%d\n", a);
    return 0;
}