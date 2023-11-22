#include <stdio.h>
#include "mesinkalimat.h"
#include "../mesin_kata/mesinkata.h"
#include "../mesin_kalimat/mesinkalimat.h"
#include "../mesin_input/mesininput.h"

// gcc mesinkalimat.c driver_mesinkalimat.c ../mesin_kata/mesinkata.c ../mesin_karkater/mesinkarakter.c -o driver_mesinkalimat

int main() {
    char filename[] = "../src/data/config.txt"; 
    printf("Memulai pembacaan dari file %s...\n\n", filename);

    STARTKALIMATFILE(filename);
    int kalimatCount = 1;

    while (!EndKalimat) {
        printf("Kalimat %d: %s\n", kalimatCount, CKalimat.TabKalimat);
        kalimatCount++;
        ADVKALIMATFILE();
    }

    printf("\nPembacaan selesai!\n");
    return 0;
}
