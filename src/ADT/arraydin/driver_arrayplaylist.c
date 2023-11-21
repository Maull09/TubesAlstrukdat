#include "arrayplaylist.h"
#include <stdio.h>

int main() {
    ArrayPlaylists arr;
    CreateEmptyArrayPlaylists(&arr);

    // Demonstrasi penambahan playlist
    Playlist p1, p2;
    SalinString(p1.name, "Playlist 1");
    SalinString(p2.name, "Playlist 2");

    AddPlaylist(&arr, p1);
    AddPlaylist(&arr, p2);

    // Menampilkan isi array playlist
    printf("Isi ArrayPlaylists:\n");
    DisplayPlaylist(&arr);

    // Menghapus playlist
    printf("\nMenghapus Playlist 2...\n");
    DeletePlaylist(&arr, 1);  // Menghapus playlist di indeks 1

    // Menampilkan isi array playlist setelah penghapusan
    printf("Isi ArrayPlaylists setelah penghapusan:\n");
    DisplayPlaylist(&arr);

    // Memeriksa validitas indeks playlist
    if (isValidPlaylist(&arr, 1)) {
        printf("\nPlaylist 1 adalah playlist yang valid.\n");
    } else {
        printf("\nPlaylist 1 bukan playlist yang valid.\n");
    }

    // Menemukan ID playlist berdasarkan nama
    int id = IdPlaylist(&arr, "Playlist 2");
    if (id != -1) {
        printf("\nID dari Playlist 2 adalah: %d\n", id + 1);
    } else {
        printf("\nPlaylist 2 tidak ditemukan.\n");
    }

    // Membersihkan array playlist
    DeallocateArrayPlaylists(&arr);

    return 0;
}
