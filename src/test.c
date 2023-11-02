#include <stdio.h>
#include "function.h"
#include "ADT/listadt.h"
#include "ADT/boolean.h"
#include "ADT/arraystatis/arraySinger.h"
#include "ADT/map/map_album.h"
#include "ADT/map/map_song.h"
// #include "ADT/mesin_input/mesininput.h"

int main(){
    ListSinger LS;
    Singer singerInput;
    CreateEmptyListSinger(&LS);

    // Input singers
    SalinString(singerInput.singerName, "Arctic Monkeys");
    InsertSinger(&LS, singerInput);
    SalinString(singerInput.singerName, "BLACKPINK");
    InsertSinger(&LS, singerInput);
    displaySinger(LS);
    printf("\n");

    //input y/n
    //input nama artis kalau y

    MapAlbum AlbumSinger;
    Album A1 = {"Album One"};
    Album A2 = {"Album Two"};
    ListMapAlbum ListAlbum;
    CreateEmptyMapAlbum(&AlbumSinger);
    CreateEmptyListMapAlbum(&ListAlbum);
    SalinString(AlbumSinger.SingerName, "Singer A");
    InsertAlbum(&AlbumSinger, A1);
    InsertAlbum(&AlbumSinger, A2);
    InsertListMapAlbum(&ListAlbum, AlbumSinger);
    
    // printf("Displaying MapAlbumSinger:\n");
    DisplayMapAlbum(AlbumSinger);
    // printf("\nDisplaying ListMapAlbum:\n");
    // DisplayListMapAlbum(&ListAlbum);
    printf("\n");
    
    //input y/n
    //input nama album kalau y

    MapSong SongAlbum;
    Song S1 = {"Song One"};
    Song S2 = {"Song Two"};
    ListMapSong arrMapSong; 
    CreateEmptyMapSong(&SongAlbum);
    CreateEmptyListMapSong(&arrMapSong);
    SalinString(SongAlbum.albumName, "Album A");
    InsertSong(&SongAlbum, S1);
    InsertSong(&SongAlbum, S2);
    InsertListMapSong(&arrMapSong, SongAlbum);

    // printf("Displaying MapSong:\n");
    DisplayMapSong(SongAlbum);
    // printf("\nDisplaying ListMapSong:\n");
    // DisplayListMapSong(&arrMapSong);

    return 0;
}

// gcc test.c function.c ADT/arraystatis/arraySinger.c ADT/map/map_album.c ADT/map/map_song.c ADT/mesin_input/mesininput.c -o test 