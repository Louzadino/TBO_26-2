#include "shaker_sort.h"
#include <stdio.h>

void sort(Item* a, int lo, int hi) {
    int trocou = 1;
    int esquerda = lo, direita = hi;

    while(trocou && esquerda < direita) {
        trocou = 0;

        for (int j = esquerda; j < direita; j++) {
            if (less(a[j + 1], a[j])) {
                exch(a[j + 1], a[j]);
                trocou = 1;
            }
        }

        if (trocou == 0) break;

        direita = direita - 1;

        for (int j = direita; j > esquerda; j--) {
            if (less(a[j], a[j-1])) {
                exch(a[j], a[j-1]);
                trocou = 1;
            }
        }

        esquerda = esquerda + 1;
    }
}