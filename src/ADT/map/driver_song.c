#include <stdio.h>
#include "map_song.h"

// gcc map_song.c driver_song.c ../../function.c -o driver_song

int main() {
    MapSong M;
    Song S1 = {"Song One"};
    Song S2 = {"Song Two"};
    ListMapSong LM;

    CreateEmptyMapSong(&M);
    CreateEmptyListMapSong(&LM);

    SalinString(M.albumName, "Album A");

    InsertSong(&M, S1);
    InsertSong(&M, S2);
    
    InsertListMapSong(&LM, M);

    // Test display functions
    printf("Displaying MapSongAlbum:\n");
    DisplayMapSong(M);
    printf("\n");

    printf("Displaying ListMapSong:\n");
    DisplayListMapSong(LM);

    return 0;
}
