#include <stdio.h>
#include "mesinkarakter.h"

// gcc mesinkarakter.c driver_mesinkarakter.c -o driver_mesinkarakter

int main() {
    char filename[] = "../src/data/test_mesinkarakter.txt";
    printf("Memulai pembacaan dari file %s...\n\n", filename);

    STARTFILE(filename);
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }

    printf("\n\nPembacaan karakter dari file selesai!\n");

    printf("\nMemulai pembacaan dari input standar (stdin). Ketik beberapa karakter dan akhiri dengan tanda ;\n\n");

    START();
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV2();
    }

    printf("\n\nPembacaan karakter dari stdin selesai!\n");

    return 0;
}
