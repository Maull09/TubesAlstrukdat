#include <stdio.h>
#include "set.h"

// gcc set.c driver_set.c ../../function.c -o driver_set

int main() {
    // Inisialisasi
    SetSong mySet;
    CreateEmptySet(&mySet);
    ListofSetSong ListofMyset;
    CreateEmptyListSet(&ListofMyset);

    // Buat beberapa data dummy
    Song song1;
    SalinString(song1.songName, "Lagu A");

    Song song2;
    SalinString(song2.songName, "Lagu B");

    Song song3;
    SalinString(song3.songName, "Lagu C");

    SalinString(mySet.albumName, "Album A");

    // Tambahkan lagu ke dalam set
    AddSongToSet(&mySet, song1);
    AddSongToSet(&mySet, song2);
    AddSongToSet(&mySet, song3);

    // Cek apakah sebuah lagu ada dalam set
    char query[] = "Lagu A";
    if (IsSongInSet(mySet, query)) {
        printf("Lagu %s ada dalam set!\n", query);
    } else {
        printf("Lagu %s tidak ada dalam set.\n", query);
    }

    // Menampilkan isi dari SetSong dan ListofSetSong
    printf("Displaying SetSong:\n");
    DisplaySetSong(mySet);
    printf("\n");

    AddSetSongToListSetSong(&ListofMyset, mySet);
    printf("Displaying ListofSetSong:\n");
    DisplayListOfSetSong(ListofMyset);

    return 0;
}
