#include "status.h"
#include "ADT/queue/queue.c"
#include "ADT/mesin_kalimat/mesinkalimat.c"

void STATUS(Lagu *playing, QueueLagu *antrian){
    printf("Now Playing:");
    printf("%s - %s - %s",*playing->artist,*playing->album,*playing->titlesong);
    printf("Queue:");
    if (isEmptyQueue(*antrian)){
        printf("Your queue is empty.");
    }
    else{
        displayQueue(*antrian);
    }
}

