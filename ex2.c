#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


typedef struct array {
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
}array;

array* array_init(unsigned int cap) {
    array* a = malloc(sizeof(array));
    if(a==NULL) {perror("Error...;("); exit(1);}
    // assert sinon on retourne -1
    a -> ptr = malloc(cap*sizeof(int));
    if (a==NULL) {perror("Error...;("); exit(1);}
    // assert sinon on retourne -1
    a -> capacite = cap;
    a -> taille = 0;
    return a;
}

void array_destroy(array *t) {
    printf("\nCleaning memory allocation...");
    assert(t!=NULL);
    free(t->ptr);
    free(t);
    printf("Memory is clean.");
}

int array_get(array *t, unsigned int index) {
    assert(t!=NULL); // Check if array structure exists
    assert(index<=t->capacite); // Check if index is inside array defined
    return t->ptr[index];
}
void array_set(array *t, unsigned int index, int valeur) {
    assert(t!=NULL); // Check if array structure exists
    assert(t->capacite>=index); // Check if position has something
    t->taille = t->taille + 1; 
    t->ptr[index] = valeur;
}


int main () {
    array* x = array_init(10);
    printf("\n[LOG]: Exercice 2.1- > x*: %p", x);
    printf("\n[LOG]: x*.capacite=%d; x*.taille=%d; x*.ptr=%p", x->capacite, x->taille, x->ptr);
    array_set(x, 2, 36);
    printf("\nArray get: %d", array_get(x, 2));
    // array_destroy(x);
    return EXIT_SUCCESS;
}