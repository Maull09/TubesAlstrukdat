#include <stdio.h>
#include "queue.h"
#include "../set/set.h"
#include "../arraystatis/arraySinger.h"
#include "../map/map_album.h"
#include "../map/map_song.h"

int main() {
    QueueLagu q;
    ElTypeQueue lagu1, lagu2, lagu3, lagu4, lagu5;
    ElTypeQueue laguHapus;

    ListSinger LS;
    Singer singerInput;

    CreateEmptyListSinger(&LS);

    SalinString(singerInput.singerName, "Arctic Monkeys");
    InsertSinger(&LS, singerInput);

    SalinString(singerInput.singerName, "BLACKPINK");
    InsertSinger(&LS, singerInput);

    displaySinger(LS);
    printf("\n");


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

    printf("Displaying MapAlbumSinger:\n");
    DisplayMapAlbum(AlbumSinger);
    printf("\n");

    printf("Displaying ListMapAlbum:\n");
    DisplayListMapAlbum(ListAlbum);

    printf("\n");

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
    
    // Test display functions
    printf("Displaying MapSong:\n");
    DisplayMapSong(SongAlbum);
    printf("\n");

    printf("Displaying ListMapSong:\n");
    DisplayListMapSong(arrMapSong);

    CreateQueue(&q);
    // Data dummy
    SalinString(lagu1.artist, "Coldplay");
    SalinString(lagu1.album, "A Head Full of Dreams");
    SalinString(lagu1.titlesong, "Adventure of a Lifetime");

    SalinString(lagu2.artist, "Ed Sheeran");
    SalinString(lagu2.album, "Divide");
    SalinString(lagu2.titlesong, "Shape of You");

    SalinString(lagu3.artist, "Taylor Swift");
    SalinString(lagu3.album, "1989");
    SalinString(lagu3.titlesong, "Blank Space");

    SalinString(lagu4.artist, "Taylor Swift");
    SalinString(lagu4.album, "Speak Now");
    SalinString(lagu4.titlesong, "Enchanted");

    SalinString(lagu5.artist, "Taylor Swift");
    SalinString(lagu5.album, "Lover");
    SalinString(lagu5.titlesong, "Daylight");

    // Menambahkan lagu ke queue
    enqueue(&q, lagu1);
    enqueue(&q, lagu2);
    enqueue(&q, lagu3);
    enqueue(&q, lagu4);
    enqueue(&q, lagu5);

    
    printf("Setelah menambahkan 5 lagu:\n");
    displayQueue(q);

    // Menghapus lagu dari queue
    dequeue(&q, &laguHapus);
    printf("\nSetelah menghapus lagu %s - %s: %s dari queue:\n", laguHapus.artist, laguHapus.album, laguHapus.titlesong);
    displayQueue(q);

    printf("\n");
    removeSong(&q, 2);

    displayQueue(q);
    
    printf("\nKosongkan Queue\n");
    clearQueue(&q);


    displayQueue(q);
    

    return 0;
}
