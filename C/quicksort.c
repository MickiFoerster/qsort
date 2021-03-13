/*
 * Quicksort:
 * Wähle zuerst Element a[r] als das Element w3elches in seine endgültige
 * Position gebracht werden soll. Durchsuche Feld von links bis ein Element
 * grösser als a[r] und von rechts bis ein Element kleiner als a[r] ist und
 * tauscht sie aus. Wenn Zeiger sich treffen ist a[r] mit dem am weitesten
 * links stehenden (Elemnt auf den linker Zeiger zeigt, nachdem sie sich
 * getroffen haben) zu vertauschen.
 */

#define swap(a, i, j)   \
    {                   \
        int tmp = a[i]; \
        a[i] = a[j];    \
        a[j] = tmp;     \
    }

void quicksort(int a[], int l, int r) {
    int i, j;
    int v;
    if (r > l) {
        v = a[r];
        i = l - 1;
        j = r;
        for (;;) {
            while (a[++i] < v)
                ;
            while (a[--j] > v)
                ;
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, i, r);
        quicksort(a, l, i - 1);
        quicksort(a, i + 1, r);
    }
}
