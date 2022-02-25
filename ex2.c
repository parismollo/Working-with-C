#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct array {
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
}array;

array* array_init(unsigned int cap) {
    array* a = malloc(sizeof(array));
    if(a==NULL) {perror("Error...;("); exit(1);}
    // assert sinon ou retourne -1
    a -> ptr = malloc(cap*sizeof(int));
    if (a==NULL) {perror("Error...;("); exit(1);}
    // assert sinon ou retourne -1
    a -> capacite = cap;
    a -> taille = 0;
    return a;
}

int main () {
    array* x = array_init(10);
    printf("\n[LOG]: Exercice 2.1- > x*: %p", x);
    printf("\n[LOG]: x*.capacite=%d; x*.taille=%d; x*.ptr=%p", x->capacite, x->taille, x->ptr);
    return EXIT_SUCCESS;
}