#include <stdio.h>
#include "queue.h"
#include "../arraystatis/arraySinger.h"
#include "../map/map_album.h"
#include "../map/map_song.h"

//  gcc queue.c driver_queue.c ../../function.c ../arraystatis/arraySinger.c ../map/map_album.c ../map/map_song.c -o driver_queue

int main() {
    QueueLagu q;
    ElTypeQueue lagu1, lagu2, lagu3, lagu4, lagu5, laguHapus;

    // Queue operations
    CreateQueue(&q);
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
    enqueue(&q, lagu1);
    enqueue(&q, lagu2);
    enqueue(&q, lagu3);
    enqueue(&q, lagu4);
    enqueue(&q, lagu5);

    printf("Setelah menambahkan 5 lagu:\n");
    displayQueue(&q);
    dequeue(&q, &laguHapus);
    printf("\nSetelah menghapus lagu %s - %s: %s dari queue:\n", laguHapus.artist, laguHapus.album, laguHapus.titlesong);
    displayQueue(&q);
    printf("\n");
    removeSong(&q, 2);
    displayQueue(&q);

    printf("\n");
    int x = 1, y = 2;
    printf("Tukar Queue ke %d dengan %d \n", x, y);
    QueueSwap(&q, x, y);
    displayQueue(&q);

    printf("\nKosongkan Queue\n");
    clearQueue(&q);
    displayQueue(&q);

    return 0;
}
