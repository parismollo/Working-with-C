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

void array_append(array *t, int val) {
    assert(t!=NULL);
    if(t->capacite > t->taille) {
        t->ptr[t->taille] = val;
        t->taille+=1;
    }else {
        printf("\n[LOG]: No space available in the array");
    }
}

void array_print(array *t) {
    assert(t!=NULL);
    for(int i=0; i<(t->taille); i++) {
        printf("\nValue at pos x[%d]: %d", i, t->ptr[i]);
    }
}

int array_search(array *t, int val) {
    assert(t!=NULL);
    for(int i=0; i<(t->capacite); i++) {
        if(val == t->ptr[i]) return i;
    }
    return -1;
}


int main () {
    array* x = array_init(10);
    printf("\n[LOG]: Exercice 2.1- > x*: %p", x);
    printf("\n[LOG]: x*.capacite=%d; x*.taille=%d; x*.ptr=%p", x->capacite, x->taille, x->ptr);
    // array_set(x, 2, 36);
    array_append(x, 10);
    array_append(x, 55);
    array_append(x, 36);
    array_append(x, 96);
    array_print(x);
    printf("\nSearching for 36. Position found at: %d",array_search(x, 36));
    printf("\nSearching for 100. Position found at: %d",array_search(x, 100));
    printf("\n[LOG]: x*.capacite=%d; x*.taille=%d; x*.ptr=%p", x->capacite, x->taille, x->ptr);
    // printf("\nArray get: %d", array_get(x, (x->taille)-2));
    // array_destroy(x);
    return EXIT_SUCCESS;
}