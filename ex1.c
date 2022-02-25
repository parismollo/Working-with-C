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

void exercice4() {
    int *pt;
    pt = malloc(5*sizeof(int));
    if(pt==NULL) {perror("malloc"); exit(1);}
    *pt = 10;
    *(pt+1) = 20;
    *(pt + 12) = 30; // C'est pas bien ça, cela sert à faire comprendre que le compilateur peut pas comprendre qu'on a depassé la mémoire alloué, c'est à nous de faire attention à cela.

    int *pt2;
    pt2 = malloc(5*sizeof(int));
    if(pt2==NULL) {perror("malloc"); exit(1);}
    pt2[0] = 10;
    pt2[1] = 20;
    pt2[12] = 30;

    printf("\n[LOG]: Exercice 1.4-> pt=%d, pt+1=%d, pt+12=%d", *pt, *(pt+1), *(pt+12));
    printf("\n[LOG]: -> pt2[0]=%d, pt2[1]=%d, pt2[12]=%d", pt2[0], pt2[1], pt2[12]);
}

int main () {
    exercice1();
    exercice2();
    exercice3();
    exercice4();
    return EXIT_SUCCESS;
}

