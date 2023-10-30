#include <stdio.h>
#include "map_album.h"

// gcc map_album.c driver_album.c ../../function.c -o driver_album

int main() {
    MapAlbumSinger M;
    Album A1 = {"Album One"};
    Album A2 = {"Album Two"};
    ListMapAlbum LM;

    CreateEmptyMapAlbum(&M);
    CreateEmptyListMapAlbum(&LM);

    SalinString(M.SingerName, "Singer A");

    InsertAlbum(&M, A1);
    InsertAlbum(&M, A2);
    
    InsertListMapAlbum(&LM, M);

    // Test display functions
    printf("Displaying MapAlbumSinger:\n");
    DisplayMapAlbum(M);
    printf("\n");

    printf("Displaying ListMapAlbum:\n");
    DisplayListMapAlbum(LM);

    return 0;
}

