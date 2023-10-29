#include <stdio.h>
#include "set.h"

// gcc set.c driver_set.c ../../function.c -o driver_set

int main() {
    // Inisialisasi
    SetSong mySet;
    InitSetSong(&mySet);

    // Buat beberapa data dummy
    Song song1;
    song1.id = 1;
    SalinString(song1.songName, "Lagu A");
    song1.albumID = 101;

    Song song2;
    song2.id = 2;
    SalinString(song2.songName, "Lagu B");
    song2.albumID = 101;

    Song song3;
    song3.id = 3;
    SalinString(song3.songName, "Lagu C");
    song3.albumID = 102;

    // Tambahkan lagu ke dalam set
    AddSongToSet(&mySet, song1);
    AddSongToSet(&mySet, song2);
    AddSongToSet(&mySet, song3);

    // Cek isi dari set
    printf("Lagu dalam set:\n");
    for (int i = 0; i < mySet.Neff; i++) {
        printf("%d. id : %d nama : %s\n", i+1,mySet.songs->id, mySet.songs[i].songName);
    }

    // Cek apakah sebuah lagu ada dalam set
    char query[] = "Lagu A";
    if (IsSongInSet(mySet, query)) {
        printf("Lagu %s ada dalam set!\n", query);
    } else {
        printf("Lagu %s tidak ada dalam set.\n", query);
    }

    return 0;
}
