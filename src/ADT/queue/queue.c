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

void enqueueFirst(QueueLagu *q, ElTypeQueue val) {
    if (isEmptyQueue(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        SalinLagu(&HEAD(*q), val);
    } else {
        if (IDX_HEAD(*q) == 0) {
            IDX_HEAD(*q) = CAPACITY - 1;
        } else {
            IDX_HEAD(*q) -= 1;
        }
        SalinLagu(&HEAD(*q), val);
    }
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

void displayQueue(QueueLagu *q) {
    if (isEmptyQueue(*q)) {
        printf("[]\n");
    } else {
        int i, nomor = 1;
        if (IDX_TAIL(*q) >= IDX_HEAD(*q)) {
            for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                printf("%d. %s - %s: %s\n", nomor, q->buffer[i].artist, q->buffer[i].album, q->buffer[i].titlesong);
                nomor++;
            }
        } else {
            for (i = IDX_HEAD(*q); i < CAPACITY; i++) {
                printf("%d. %s - %s: %s\n", nomor, q->buffer[i].artist, q->buffer[i].album, q->buffer[i].titlesong);
                nomor++;
            }
            for (i = 0; i <= IDX_TAIL(*q); i++) {
                printf("%d. %s - %s: %s\n", nomor, q->buffer[i].artist, q->buffer[i].album, q->buffer[i].titlesong);
                nomor++;
            }
        }
    }
}


void SalinLagu(Lagu *dest, Lagu src) {
    SalinString(dest->artist, src.artist);
    SalinString(dest->album, src.album);
    SalinString(dest->titlesong, src.titlesong);
}

void removeSong(QueueLagu *q, int id) {
    if (isEmptyQueue(*q)) {
        printf("Queue kosong. Tidak ada lagu yang dapat dihapus.\n");
        return;
    }

    int n = lengthQueue(*q);

    // Cek apakah ID lagu valid
    if (id < 1 || id > n) {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        return;
    }

    int idxToRemove = (IDX_HEAD(*q) + id - 1) % CAPACITY;
    ElTypeQueue removed_song = q->buffer[idxToRemove];

    for (int i = idxToRemove; i != IDX_TAIL(*q); i = (i + 1) % CAPACITY) {
        int nextIdx = (i + 1) % CAPACITY;
        q->buffer[i] = q->buffer[nextIdx];
    }

    if (IDX_TAIL(*q) == 0) {
        IDX_TAIL(*q) = CAPACITY - 1;
    } else {
        IDX_TAIL(*q) -= 1;
    }

    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }

    printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", removed_song.titlesong, removed_song.artist);
}


void clearQueue(QueueLagu *q){
    CreateQueue(q);
    printf("Queue berhasil dikosongkan.\n");
}

void QueueSwap (QueueLagu *q, int x, int y){
    if (isEmptyQueue(*q)){
        printf("Queue kosong. Tidak ada lagu yang dapat ditukar.\n");
        return;
    }

    int length = lengthQueue(*q);
    int idx_x = (IDX_HEAD(*q) + x - 1) % CAPACITY;
    int idx_y = (IDX_HEAD(*q) + y - 1) % CAPACITY;

    if ((x<1 || x>length)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        return;
    }
    else if (y<1 || y>length){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        return; 
    }

    if(x == y){
        printf("Lagu yang swap adalah lagu dengan indeks yang sama\n");
        return;
    }
    
    ElTypeQueue temp = q->buffer[idx_x];
    q->buffer[idx_x] = q->buffer[idx_y];
    q->buffer[idx_y] = temp;

    printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"!\n", q->buffer[idx_x].titlesong, q->buffer[idx_y].titlesong);

}