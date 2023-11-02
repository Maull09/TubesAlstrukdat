#include <stdio.h>
#include <string.h>
#include "queue.h"

void QueueSwap (QueueLagu *q, int x, int y){
    if (isEmptyQueue(*q)){
        printf("Queue kosong \n");
        return;
    }

    int length = lengthQueue(*q);

    if (x<1 || x>length || y<1 || y>length){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue! \n");
        return;
    }

    ElTypeQueue lagu_x, lagu_y, temp;
    temp = q->buffer[y];
    q->buffer[y] = q->buffer[x];
    q->buffer[x] = temp;

    printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"!\n", lagu_x.titlesong, lagu_y.titlesong);

}