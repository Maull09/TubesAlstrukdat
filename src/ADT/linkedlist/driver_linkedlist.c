#include "linkedlist.h"
#include <stdio.h>

// gcc linkedlist.c driver_linkedlist.c ../../function.c -o driver_linkedlist

int main() {
    List L;
    infotype song1, song2, song3;
    SalinString(song1.songName, "Imagine");
    SalinString(song2.songName, "Bohemian Rhapsody");
    SalinString(song3.songName, "Billie Jean");

    CreateEmpty(&L);
    InsVFirst(&L, song1);
    InsVLast(&L, song2);
    InsVLast(&L, song3);

    printf("List of songs:\n");
    PrintInfo(L);

    infotype songDel;
    DelVFirst(&L, &songDel);
    printf("Deleted: %s\n", songDel.songName);
    PrintInfo(L);

    DelVLast(&L, &songDel);
    printf("Deleted: %s\n", songDel.songName);
    PrintInfo(L);

    return 0;
}