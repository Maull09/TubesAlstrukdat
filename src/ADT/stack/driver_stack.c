#include <stdio.h>
#include "stack.h"

// gcc stack.c driver_stack.c ../../function.c -o driver_stack


int main() {
    StackSong S;
    Lagu songInput, songPopped;

    CreateEmptyStackSong(&S);

    printf("StackSong Application\n");
    printf("=====================\n");
    
    // Simulasi menambahkan 2 lagu ke dalam stack
    printf("Pushing songs into the stack...\n");

    SalinString(songInput.artist, "Arctic Monkeys");
    SalinString(songInput.album, "Favourite Worst Nightmare");
    SalinString(songInput.titlesong, "505");
    PushStackSong(&S, songInput);

    SalinString(songInput.artist, "BLACKPINK");
    SalinString(songInput.album, "BORN PINK");
    SalinString(songInput.titlesong, "Pink Venom");
    PushStackSong(&S, songInput);

    // Menampilkan lagu di puncak stack
    if (!IsEmptyStackSong(S)) {
        songPopped = InfoTop(S);
        printf("Song at the top: %s; %s; %s\n", songPopped.artist, songPopped.album, songPopped.titlesong);
    }

    // Simulasi menghapus lagu dari stack
    printf("\nPopping songs from the stack...\n");
    while (!IsEmptyStackSong(S)) {
        PopStackSong(&S, &songPopped);
        printf("Popped: %s; %s; %s\n", songPopped.artist, songPopped.album, songPopped.titlesong);
    }

    // Menampilkan pesan ketika stack sudah kosong
    if (IsEmptyStackSong(S)) {
        printf("\nThe stack is now empty!\n");
    }

    return 0;
}
