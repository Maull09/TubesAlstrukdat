#include <stdio.h>
#include "queue.h"

// gcc queue.c driver_queue.c ../../function.c -o driver_queue

int main() {
    QueueLagu q;
    ElTypeQueue lagu1, lagu2, lagu3;
    ElTypeQueue laguHapus;

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
