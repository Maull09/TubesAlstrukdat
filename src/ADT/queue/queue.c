#include <stdio.h>
#include <string.h>
#include "queue.h"

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

