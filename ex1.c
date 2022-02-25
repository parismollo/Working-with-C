#include <stdio.h>
#include <stdlib.h>

void exercice1() {
    int t[] = {1, 2, 3};
    // int t[3] = {1, 2, 3};
    int *pt;
    pt = t;
    // pt = t + 1 ou autre chose
    printf("%d", *pt);
}

int main () {
    exercice1();
    return EXIT_SUCCESS;
}

