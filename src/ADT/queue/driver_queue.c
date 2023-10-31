#include <stdio.h>
#include "queue.h"

#include "../mesin_karakter/mesinkarakter.h"
#include "../mesin_kata/mesinkata.h"
#include "../mesin_input/mesininput.h"
#include "../queue/queue.h"
#include "../set/set.h"
#include "../arraystatis/arraySinger.h"
#include "../map/map_album.h"
#include "../map/map_song.h"

// gcc queue.c driver_queue.c ../../function.c -o driver_queue

int main() {
    QueueLagu q;
    ElTypeQueue lagu1, lagu2, lagu3;
    ElTypeQueue laguHapus;
    ListSinger LS;
    Singer singerInput;
    int foundIdx;
    MapSongAlbum SM;
    Song S1 = {"Song One"};
    Song S2 = {"Song Two"};
    ListMapSong LM;
    MapAlbumSinger AlbumSinger;
    Album A1 = {"Album One"};
    Album A2 = {"Album Two"};
    ListMapAlbum LMA;

    CreateEmptyListSinger(&LS);

    SalinString(singerInput.singerName, "Arctic Monkeys");
    InsertSinger(&LS, singerInput);

    SalinString(singerInput.singerName, "BLACKPINK");
    InsertSinger(&LS, singerInput);

    printf("Display listsinger: \n");
    displaySinger(LS);


    CreateEmptyMapAlbum(&AlbumSinger);
    CreateEmptyListMapAlbum(&LMA);
    SalinString(AlbumSinger.SingerName, "Singer A");
    InsertAlbum(&AlbumSinger, A1);
    InsertAlbum(&AlbumSinger, A2);
    InsertListMapAlbum(&LMA, AlbumSinger);


    printf("Displaying MapAlbumSinger:\n");
    DisplayMapAlbum(AlbumSinger);
    printf("\n");

    printf("Displaying ListMapAlbum:\n");
    DisplayListMapAlbum(LMA);
    

    CreateEmptyMapSong(&SM);
    CreateEmptyListMapSong(&LM);

    SalinString(SM.albumName, "Album A");

    InsertSong(&SM, S1);
    InsertSong(&SM, S2);
    InsertListMapSong(&LM, SM);
    
    // Test display functions
    printf("Displaying MapSongAlbum:\n");
    DisplayMapSong(SM);
    printf("\n");

    printf("Displaying ListMapSong:\n");
    DisplayListMapSong(LM);

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

    CreateQueue(&q);
    // Menambahkan lagu ke queue
    enqueue(&q, lagu1);
    enqueue(&q, lagu2);
    enqueue(&q, lagu3);
    
    printf("Setelah menambahkan 3 lagu:\n");
    displayQueue(q);

    // Menghapus lagu dari queue
    dequeue(&q, &laguHapus);
    printf("\nSetelah menghapus lagu %s - %s: %s dari queue:\n", laguHapus.artist, laguHapus.album, laguHapus.titlesong);
    displayQueue(q);

    return 0;
}
// gcc ../../function.c ../arraystatis/arraySinger.c ../map/map_album.c ../map/map_song.c ../mesin_karakter/mesinkarakter.c ../mesin_kata/mesinkata.c ../mesin_input/mesininput.c ../mesin_kalimat/mesinkalimat.c ../queue/queue.c ../arraydin/arrayplaylist.c ../linkedlist/linkedlist.c ../set/set.c ../stack/stack.c -o driver_queue
