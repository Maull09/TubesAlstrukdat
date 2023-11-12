#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P) {
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean Search (List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (StringSama(titlesong(P), X.titlesong) && StringSama(album(P), X.album) && StringSama(artist(P), X.artist)) {
            return true;
        }
        P = Next(P);
    }
    return false;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVFirst (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelP (List *L, infotype X) {
    address P = First(*L);
    address Prec = Nil;

    while (P != Nil && !StringSama(titlesong(P), X.titlesong) && !StringSama(album(P), X.album) && !StringSama(artist(P), X.artist)) {
        Prec = P;
        P = Next(P);
    }

    if (P != Nil) {
        if (Prec == Nil) { // delete first
            DelFirst(L, &P);
        } else {
            DelAfter(L, &P, Prec);
        }
        Dealokasi(&P);
    }
}

void DelVLast (List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

void DelFirst (List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelLast (List *L, address *P) {
    address Last = First(*L), PrecLast = Nil;
    while (Next(Last) != Nil) {
        PrecLast = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (PrecLast == Nil) First(*L) = Nil;
    else Next(PrecLast) = Nil;
}

void DelAfter (List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    address P = First(L);
    int number = 0;
    if(IsEmpty(L)){
        printf("Playlist tidak terdapat lagu\n");
    } else {
        while (P != Nil) {
            number += 1;
            printf("%d. %s - %s - %s\n", number, artist(P), album(P), titlesong(P));
            P = Next(P);
        }
    }
}

int NbElmt (List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

boolean isValidSong(List L, int Id){
    return(Id >= 1 && Id <= NbElmt(L));
}
