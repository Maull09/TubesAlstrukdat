#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P) {
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil && (StringSama(Artist(P), X.artist) || StringSama(Album(P), X.album)|| StringSama(TitleSong(P), X.titlesong)|| StringSama(IdSong(P), X.SongId))) {
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVFirst(List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst(List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = P;
    }
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP(List *L, infotype X) {
    address P = First(*L), prev = Nil;
    while (P != Nil && (StringSama(Artist(P), X.artist)|| StringSama(Album(P), X.album)|| StringSama(TitleSong(P), X.titlesong)|| StringSama(IdSong(P), X.SongId) != 0)) {
        prev = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (prev == Nil) {
            DelFirst(L, &P);
        } else {
            DelAfter(L, &P, prev);
        }
        Dealokasi(&P);
    }
}

void DelLast(List *L, address *P) {
    if (Next(First(*L)) == Nil) {
        *P = First(*L);
        CreateEmpty(L);
    } else {
        address last = First(*L);
        while (Next(Next(last)) != Nil) {
            last = Next(last);
        }
        *P = Next(last);
        Next(last) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    printf("[");
    address P = First(L);
    while (P != Nil) {
        printf("%s-%s-%s-%s", Artist(P), Album(P), TitleSong(P), IdSong(P));
        P = Next(P);
        if (P != Nil) {
            printf(", ");
        }
    }
    printf("]");
}

int NbElmt(List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}