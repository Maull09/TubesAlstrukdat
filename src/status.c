#include "status.h"
#include "ADT/queue/queue.c"
#include "ADT/mesin_kalimat/mesinkalimat.c"

void STATUS(Playlist playlist,Lagu playing, QueueLagu antrian){
    if(playlist.name){
        printf("Current Playlist: %s", playlist.name);
        printf("\n");
    }
    printf("Now Playing:");
    if (!playing.artist){
        printf("No songs have been played yet. Please search for a song to begin playback.");
    }
    else{
        printf("%s - %s - %s",playing.artist,playing.album,playing.titlesong);
    }
    printf("\n");
    printf("Queue:");
    if (isEmptyQueue(antrian)){
        printf("Your queue is empty.");
    }
    else{
        displayQueue(antrian);
    }
}

