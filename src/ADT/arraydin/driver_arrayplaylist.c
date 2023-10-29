#include "arrayplaylist.h"
#include <stdio.h>

// gcc arrayplaylist.c driver_arrayplaylist.c ../../function.c -o driver_arrayplaylist


int main() {
    ArrayPlaylists arrPlaylists;

    // Membuat ArrayListPlaylists kosong
    CreateEmptyArrayPlaylists(&arrPlaylists);

    // Menambahkan beberapa playlist
    Playlist p1, p2, p3;
    CreatePlaylist(&p1, "Rock Classics", 1);
    CreatePlaylist(&p2, "Jazz Favorites", 2);
    CreatePlaylist(&p3, "Pop Hits", 3);

    AddPlaylist(&arrPlaylists, p1);
    AddPlaylist(&arrPlaylists, p2);
    AddPlaylist(&arrPlaylists, p3);

    // Mencari playlist berdasarkan nama
    char query[] = "Jazz Favorites";
    int idx = FindPlaylist(arrPlaylists, query);
    if (idx != -1) {
        printf("Playlist \"%s\" ditemukan di indeks %d dengan ID %d.\n", query, idx, arrPlaylists.playlists[idx].id);
    } else {
        printf("Playlist \"%s\" tidak ditemukan.\n", query);
    }

    // Pembersihan memori
    DeallocateArrayPlaylists(&arrPlaylists);

    return 0;
}
