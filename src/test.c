#include <stdio.h>
#include "function.h"
#include "ADT/listadt.h"
#include "ADT/boolean.h"
#include "ADT/arraystatis/arraySinger.h"
#include "ADT/map/map_album.h"
#include "ADT/map/map_song.h"
#include "ADT/arraydin/arrayplaylist.h"
#include "ADT/linkedlist/linkedlist.h"

// #include "ADT/mesin_input/mesininput.h"

int main(){
    ListSinger LS;
    Singer singerInput;
    SalinString(singerInput.singerName, "Arctic Monkeys");
    InsertSinger(&LS, singerInput);
    SalinString(singerInput.singerName, "BLACKPINK");
    InsertSinger(&LS, singerInput);
    CreateEmptyListSinger(&LS);
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



//==============================================
    // Input singers
    displaySinger(LS);
    printf("\n");

    char choice;
    char SelectedArtist;
    char SelectedAlbum;
    printf("Ingin melihat album yang ada?(Y/N) : ");
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y'){
        printf("Pilih penyanyi untuk melihat album mereka : ");
        scanf("%s", &SelectedArtist);
        if(FindArtist(AlbumSinger, SelectedArtist)){
            DisplayListMapAlbum(&ListAlbum, SelectedArtist); 
            scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y'){
                printf("Pilih album untuk melihat lagu yang ada di album : ");
                scanf("%s", &SelectedAlbum);
                if (FindAlbum(AlbumSinger, SelectedAlbum)){
                    DisplayListMapSong(&arrMapSong, SelectedAlbum);
                }
                    
            } 

        }else {
            printf("Tidak ada nama penyanyi");
        }
        
    } 
    

    
    // printf("Displaying MapAlbumSinger:\n");
    // printf("\nDisplaying ListMapAlbum:\n");
    // DisplayListMapAlbum(&ListAlbum);
    printf("\n");
    
    //input y/n
    //input nama album kalau y


    // printf("Displaying MapSong:\n");
    DisplayMapSong(SongAlbum);
    // printf("\nDisplaying ListMapSong:\n");
    // DisplayListMapSong(&arrMapSong);

    // ArrayPlaylists arrPlaylist;
    // Playlist p1, p2;

    // SalinString(p1.name, "Pop Hits");
    // SalinString(p2.name, "Chill Vibes");

    // CreateEmptyArrayPlaylists(&arrPlaylist);

    // AddPlaylist(&arrPlaylist, p1);
    // AddPlaylist(&arrPlaylist, p2);

    // // Test Display function
    // printf("Displaying Playlists:\n");
    // DisplayPlaylist(arrPlaylist);
    // printf("\n");

    return 0;
}

// gcc test.c function.c ADT/arraystatis/arraySinger.c ADT/map/map_album.c ADT/map/map_song.c ADT/mesin_input/mesininput.c -o test 