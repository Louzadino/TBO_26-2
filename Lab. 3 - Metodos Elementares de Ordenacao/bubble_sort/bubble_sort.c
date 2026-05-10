#include "bubble_sort.h"

void sort(Item* a, int lo, int hi) {
    int N = hi - lo + 1;
    int trocou = 1;

    for (int i = 0; i <= N - 2; i++) {
        trocou = 0;
        for (int j = 1; j <= N - i - 1; j++) {
            if (less(a[j], a[j-1])) {
                exch(a[j], a[j-1]);
                trocou = 1;
            }
        }
        if (trocou == 0) break;
    }
}