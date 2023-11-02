#include <stdio.h>
#include <string.h>
#include "queue.h"

// #include "../mesin_karakter/mesinkarakter.h"
// #include "../mesin_kata/mesinkata.h"
// #include "../mesin_input/mesininput.h"
// #include "../mesin_kalimat/mesinkalimat.h"

/* *** Kreator *** */
void CreateQueue(QueueLagu *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyQueue(QueueLagu q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFullQueue(QueueLagu q) {
    if (IDX_TAIL(q) > IDX_HEAD(q)) {
        return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1);
    } else {
        return (IDX_HEAD(q) - 1 == IDX_TAIL(q));
    }
}

int lengthQueue(QueueLagu q) {
    if (isEmptyQueue(q)) {
        return 0;
    } else if (IDX_TAIL(q) >= IDX_HEAD(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1;
    }
}

void enqueue(QueueLagu *q, ElTypeQueue val) {
    if (isEmptyQueue(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else if (IDX_TAIL(*q) == CAPACITY - 1) {
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) += 1;
    }
    SalinLagu(&TAIL(*q), val);
}

void dequeue(QueueLagu *q, ElTypeQueue *val) {
    SalinLagu(val, HEAD(*q));

    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else if (IDX_HEAD(*q) == CAPACITY - 1) {
        IDX_HEAD(*q) = 0;
    } else {
        IDX_HEAD(*q) += 1;
    }
}

void displayQueue(QueueLagu q) {
    if (isEmptyQueue(q)) {
        printf("[]\n");
    } else {
        int i, nomor = 1;
        printf("[");

        if (IDX_TAIL(q) >= IDX_HEAD(q)) {
            for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
                printf("%d. %s - %s: %s", nomor, q.buffer[i].artist, q.buffer[i].album, q.buffer[i].titlesong);
                if (i != IDX_TAIL(q)) printf(",\n ");
                nomor++;
            }
        } else {
            for (i = IDX_HEAD(q); i < CAPACITY; i++) {
                printf("%d. %s - %s: %s,\n ", nomor, q.buffer[i].artist, q.buffer[i].album, q.buffer[i].titlesong);
                nomor++;
            }
            for (i = 0; i <= IDX_TAIL(q); i++) {
                printf("%d. %s - %s: %s", nomor, q.buffer[i].artist, q.buffer[i].album, q.buffer[i].titlesong);
                if (i != IDX_TAIL(q)) printf(",\n ");
                nomor++;
            }
        }

        printf("]\n");
    }
}


void SalinLagu(Lagu *dest, Lagu src) {
    SalinString(dest->artist, src.artist);
    SalinString(dest->album, src.album);
    SalinString(dest->titlesong, src.titlesong);
}

void removeSong(QueueLagu *q, int id){
    int n = lengthQueue(*q);
    if (isEmptyQueue(*q)) {
        printf("Queue kosong. Tidak ada lagu yang dapat dihapus.\n");
    } else {
        // Cek apakah ID lagu valid
        if (id < 1 || id > n){
            printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        } else {
            ElTypeQueue removed_song;
            removed_song = q->buffer[id];
            for (int i = id; i < n; i++){
                q->buffer[i] = q->buffer[i+1];
            }
            printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", removed_song.titlesong, removed_song.artist);
        }
    }
    IDX_TAIL(*q) -= 1;
}

void clearQueue(QueueLagu *q){
    CreateQueue(q);
    printf("Queue berhasil dikosongkan\n");
}

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
    lagu_x = q->buffer[x];
    lagu_y = q->buffer[y];
    temp = q->buffer[y];
    q->buffer[y] = q->buffer[x];
    q->buffer[x] = temp;

    printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"!\n", lagu_x.titlesong, lagu_y.titlesong);

}