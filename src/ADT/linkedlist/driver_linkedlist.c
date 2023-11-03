#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List L;
    infotype lagu1 = {"Beatles", "Abbey Road", "Come Together"};
    infotype lagu2 = {"Queen", "News of the World", "We Will Rock You"};
    infotype lagu3 = {"Adele", "25", "Hello"};

    // Membuat list kosong
    CreateEmpty(&L);

    // Menambahkan lagu ke list
    InsVFirst(&L, lagu1);
    InsVLast(&L, lagu2);
    InsVLast(&L, lagu3);

    // Menampilkan semua lagu
    printf("Daftar lagu:\n");
    PrintInfo(L);

    // Menghapus lagu dari list
    DelVFirst(&L, &lagu1);
    printf("\nSetelah menghapus lagu pertama:\n");
    PrintInfo(L);

    // Menghapus lagu dari list
    DelVLast(&L, &lagu3);
    printf("\nSetelah menghapus lagu terakhir:\n");
    PrintInfo(L);

    return 0;
}
