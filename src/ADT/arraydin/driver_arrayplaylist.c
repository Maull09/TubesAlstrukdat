#include "arrayplaylist.h"
#include <stdio.h>

// gcc arrayplaylist.c driver_arrayplaylist.c ../../function.c -o driver_arrayplaylist

int main() {
    ArrayPlaylists arrPlaylist;
    Playlist p1, p2;

    SalinString(p1.name, "Pop Hits");
    SalinString(p2.name, "Chill Vibes");

    CreateEmptyArrayPlaylists(&arrPlaylist);

    AddPlaylist(&arrPlaylist, p1);
    AddPlaylist(&arrPlaylist, p2);

    // Test Display function
    printf("Displaying Playlists:\n");
    DisplayPlaylist(arrPlaylist);
    printf("\n");

    char searchName[255];
    SalinString(searchName, "Pop Hits");

    if (FindPlaylist(arrPlaylist, searchName)) {
        printf("%s is in the list of playlists.\n", searchName);
    } else {
        printf("%s is not in the list of playlists.\n", searchName);
    }

    // Cleanup
    DeallocateArrayPlaylists(&arrPlaylist);

    return 0;
}

