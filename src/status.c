#include "status.h"
#include "ADT/queue/queue.c"
#include "ADT/mesin_kalimat/mesinkalimat.c"

void STATUS(Lagu *playing, QueueLagu *antrian){
    printf("Now Playing: ");
    if (StringSama(playing->titlesong, "\0") && StringSama(playing->artist, "\0") && StringSama(playing->album, "\0")){
        printf("No songs have been played yet. Please search for a song to begin playback.");
    } else {
        printf("%s - %s - %s\n",*playing->artist,*playing->album,*playing->titlesong);
    }
    
    printf("Queue:");
    if (isEmptyQueue(*antrian)){
        printf("Your queue is empty.\n");
    }
    else{
        displayQueue(*antrian);
    }
}

