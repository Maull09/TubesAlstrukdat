#include <stdio.h>
#include <stdlib.h>
#include "mesininput.h" // Asumsi berisi definisi semua variabel dan fungsi yang Anda sebutkan di atas

// gcc mesininput.c driver_mesininput.c ../mesin_kata/mesinkata.c ../mesin_karkater/mesinkarakter.c -o driver_mesininput

int main() {
    printf("Masukkan sejumlah kata (akhiri dengan tanda ;):\n");
    boolean start = true;
    // Mulai membaca input
    while (start) {
        STARTINPUT();
        // Cetak kata yang telah diakuisisi
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");

        // Baca kata berikutnya
        ADVINPUT();
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
    }

    printf("Pembacaan selesai.\n");
    return 0;
}
