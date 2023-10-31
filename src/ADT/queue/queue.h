/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../../function.h"
#include "../listadt.h"

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(QueueLagu *q);

/* ********* Prototype ********* */
boolean isEmptyQueue(QueueLagu q);
boolean isFullQueue(QueueLagu q);
int lengthQueue(QueueLagu q);

/* *** Primitif Add/Delete *** */
void enqueue(QueueLagu *q, ElTypeQueue val);
void dequeue(QueueLagu *q, ElTypeQueue *val);

/* *** Display Queue *** */
void displayQueue(QueueLagu q);

void SalinLagu(Lagu *dest, Lagu src);

void removeSong(QueueLagu *q, int id);

void clearQueue(QueueLagu *q);
#endif
