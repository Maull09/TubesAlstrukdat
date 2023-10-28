#include <stdio.h>
#include "map_song.h"

// gcc map_song.c driver_song.c ../../function.c -o driver_song

int main() {
    MapSong M;
    Song s1, s2, s3;

    // Inisialisasi lagu
    s1.id = 1;
    SalinString(s1.songName, "Song1");
    s1.albumID = 101;

    s2.id = 2;
    SalinString(s2.songName, "Song2");
    s2.albumID = 102;

    s3.id = 3;
    SalinString(s3.songName, "Song3");
    s3.albumID = 103;

    // Membuat map kosong
    CreateEmptyMapSong(&M);

    // Memasukkan lagu ke dalam map
    InsertSong(&M, s1);
    InsertSong(&M, s2);
    InsertSong(&M, s3);

    // Pencarian lagu berdasarkan nama
    char songToFind[] = "Song2";
    int position = FindSong(M, songToFind);
    if (position != UndefinedMapSong) {
        printf("Lagu %s ditemukan pada posisi %d dengan ID album %d\n", songToFind, position+1, M.songs[position].albumID);
    } else {
        printf("Lagu %s tidak ditemukan.\n", songToFind);
    }

    return 0;
}
