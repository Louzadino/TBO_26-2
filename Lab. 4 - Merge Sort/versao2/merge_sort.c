#include <stdlib.h>
#include "item.h"
#include "insertion_sort.h"

#define CUTOFF 10

void merge(Item* a, Item* aux, int lo, int mid, int hi) {
    // Copiar do array principal para auxiliar
    for (int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }

    // Definir iteradores do array aux
    int i = lo, j = mid+1;

    // Fazer o processo de merge
    for (int k = lo; k <= hi; k++) {
        if (i > mid)                        a[k] = aux[j++]; // Caso i passe da metade
        else if (j > hi)                    a[k] = aux[i++]; // Caso j passe do final
        else if (less(aux[j], aux[i]))      a[k] = aux[j++];
        else                                a[k] = aux[i++];
    }
}

void merge_sort(Item* a, Item* aux, int lo, int hi) {
    // CUTOFF para insertion sort (caso para arrays pequenos)
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;           
    }

    int mid = lo + (hi - lo) / 2;   // Criação da variável que marca o meio
    merge_sort(a, aux, lo, mid);    // Aplica recursão na parte esquerda
    merge_sort(a, aux, mid+1, hi);  // Aplica recursão na parte direite
    merge(a, aux, lo, mid, hi);     // Da merge nas metades
}

void sort(Item* a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item* aux = (Item*) malloc(n * sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}
