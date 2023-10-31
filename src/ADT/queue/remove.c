#include <stdio.h>
#include "queue.h"


void removeSong(QueueLagu *q, int id){
    if (isEmptyQueue(*q)) {
        printf("Queue kosong. Tidak ada lagu yang dapat dihapus.\n");
    } else {
        // Cek apakah ID lagu valid
        if (id < 1 || id > lengthQueue(*q)){
            printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        } else {
            ElTypeQueue removed_song;
            removed_song = q->buffer[id-1];
            for (int i = id-1; i < lengthQueue(*q); i++){
                q->buffer[i] = q->buffer[i+1];
            }

            printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", removed_song.titlesong, removed_song.artist);
        }
    }
}

// gcc queue.c driver_queue.c ../../function.c -o driver_queue
