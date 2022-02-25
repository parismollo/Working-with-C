#include <stdio.h>
#include <stdlib.h>

void exercice1() {
    int t[] = {1, 2, 3};
    // int t[3] = {1, 2, 3};
    int *pt;
    pt = t;
    // pt = t + 1 ou autre chose
    printf("\n[LOG]: Exercice 1.1 -> %d", *pt);
}

void exercice2() {
    // int t[] = {1, 2, 3};
    // int *pt;
    // t = pt; Interdit de toucher un "pointeur constant comme t"
    printf("\n[LOG]: Exercice 1.2 -> Cela est interdit et va pas marcher.");
}

void exercice3() {
    int t[3];
    int *pt;
    pt = malloc(5*sizeof(int));
    pt = t;
    // On écrase la mémoire alloué et il retoure n'importe quelle valeur, car c'est ce qu'il y avait avant la bas. 

    // int x[5] = malloc(5*sizeof(int)); cela marche pas car malloc retoure un adresse 
    printf("\n[LOG]: Exercice 1.3 -> %d", *pt);
    // printf("\n x[5] -> %d", *x); // ici on écrase pas la mémoire alloué
}

int main () {
    exercice1();
    exercice2();
    exercice3();
    return EXIT_SUCCESS;
}

