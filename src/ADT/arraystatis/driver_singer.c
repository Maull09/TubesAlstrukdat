#include <stdio.h>
#include "arraySinger.h"

// gcc arraySinger.c driver_singer.c ../../function.c -o driver_singer

int main() {
    ListSinger LS;
    Singer singerInput;
    int foundIdx;

    CreateEmptyListSinger(&LS);

    printf("ListSinger Application\n");
    printf("=====================\n");
    
    // Simulasi menambahkan 2 penyanyi ke dalam list
    printf("Inserting singers into the list...\n");

    SalinString(singerInput.singerName, "Arctic Monkeys");
    InsertSinger(&LS, singerInput);

    SalinString(singerInput.singerName, "BLACKPINK");
    InsertSinger(&LS, singerInput);

    // Mencari penyanyi dalam list
    printf("\nSearching for singers in the list...\n");
    foundIdx = FindSinger(LS, "Arctic Monkeys");
    if (foundIdx != IdxUndef) {
        printf("Found Arctic Monkeys at index: %d\n", foundIdx);
    } else {
        printf("Arctic Monkeys not found!\n");
    }

    foundIdx = FindSinger(LS, "Taylor Swift");
    if (foundIdx != IdxUndef) {
        printf("Found Taylor Swift at index: %d\n", foundIdx);
    } else {
        printf("Taylor Swift not found!\n");
    }

    return 0;
}
