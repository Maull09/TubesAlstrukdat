#include <stdio.h>
#include "map_album.h"

// gcc map_album.c driver_album.c ../../function.c -o driver_album


int main() {
    MapAlbum M;
    Album a1, a2, a3;

    // Inisialisasi album
    a1.id = 1;
    SalinString(a1.albumName, "Album1");
    a1.singerID = 101;

    a2.id = 2;
    SalinString(a2.albumName, "Album2");
    a2.singerID = 102;

    a3.id = 3;
    SalinString(a3.albumName, "Album3");
    a3.singerID = 103;

    // Membuat map kosong
    CreateEmptyMapAlbum(&M);

    // Memasukkan album ke dalam map
    InsertAlbum(&M, a1);
    InsertAlbum(&M, a2);
    InsertAlbum(&M, a3);

    // Pencarian album berdasarkan nama
    char albumToFind[] = "Album2";
    int position = FindAlbum(M, albumToFind);
    if (position != Undefined) {
        printf("Album %s ditemukan pada posisi %d dengan ID penyanyi %d\n", albumToFind, position+1, M.albums[position].singerID);
    } else {
        printf("Album %s tidak ditemukan.\n", albumToFind);
    }

    return 0;
}
