#include <stdio.h>
#include "mesinkalimat.h"

// gcc mesinkalimat.c driver_mesinkalimat.c ../mesin_kata/mesinkata.c ../mesin_karakater/mesinkarakter.c -o driver_mesinkalimat

int main() {
    char filename[] = "../../data/config.txt"; // Anda perlu membuat file bernama test.txt dengan beberapa kalimat di dalamnya
    printf("Memulai pembacaan dari file %s...\n\n", filename);

    STARTKALIMATFILE(filename);
    int kalimatCount = 1;

    while (!EndKalimat) {
        printf("Kalimat %d: %s\n", kalimatCount, CKalimat.TabKalimat);
        kalimatCount++;
        ADVKALIMATFILE();
    }

    printf("\nPembacaan selesai!\n");
    
    char namefile[] = "../../data/config.txt"; // Anda perlu membuat file bernama test.txt dengan beberapa kalimat di dalamnya
    printf("Memulai pembacaan dari file %s...\n\n", namefile);

    STARTKALIMATFILE(namefile);
    int CountKalimat = 1;
    printf("\nPembacaan Kedua!\n");
    while (!EndKalimat) {
        printf("Kalimat %d: %s\n", CountKalimat, CKalimat.TabKalimat);
        CountKalimat++;
        ADVKALIMATFILE2();
    }

    printf("\nPembacaan selesai!\n");
    return 0;
}
