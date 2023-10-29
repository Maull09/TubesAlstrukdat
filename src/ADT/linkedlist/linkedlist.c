#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty(List L) {
    return (First(L) == NULL && Last(L) == NULL);
}

void CreateEmpty(List *L) {
    First(*L) = NULL;
    Last(*L) = NULL;
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != NULL) {
        Info(P) = X;
        Next(P) = NULL;
        Prev(P) = NULL;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infotype X) {
    address P = First(L);
    while (P != NULL) {
        if (StringSama(Artist(P), X.artist) && StringSama(Album(P), X.album) && StringSama(TitleSong(P), X.titlesong)) {
            return P;
        }
        P = Next(P);
    }
    return NULL;
}

void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        InsertLast(L, P);
    }
}

void InsertFirst(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Prev(First(*L)) = P;
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    if (Next(Prec) != NULL) {
        Prev(Next(Prec)) = P;
    } else {
        Last(*L) = P;
    }
    Next(Prec) = P;
}

void InsertBefore(List *L, address P, address Succ) {
    if (Prev(Succ) == NULL) {
        InsertFirst(L, P);
    } else {
        InsertAfter(L, P, Prev(Succ));
    }
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    if (First(*L) == Last(*L)) {
        CreateEmpty(L);
    } else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = NULL;
        Next(*P) = NULL;
    }
}

void DelLast(List *L, address *P) {
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        CreateEmpty(L);
    } else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = NULL;
        Prev(*P) = NULL;
    }
}

void DelP(List *L, infotype X) {
    address P = Search(*L, X);
    if (P != NULL) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else if (P == Last(*L)) {
            DelLast(L, &P);
        } else {
            Prev(Next(P)) = Prev(P);
            Next(Prev(P)) = Next(P);
            Next(P) = NULL;
            Prev(P) = NULL;
            Dealokasi(P);
        }
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != NULL) {
        if (Next(*Pdel) != NULL) {
            Prev(Next(*Pdel)) = Prec;
        }
        Next(Prec) = Next(*Pdel);
        if (*Pdel == Last(*L)) {
            Last(*L) = Prec;
        }
        Next(*Pdel) = NULL;
        Prev(*Pdel) = NULL;
    }
}

void DelBefore(List *L, address *Pdel, address Succ) {
    *Pdel = Prev(Succ);
    if (*Pdel != NULL) {
        if (Prev(*Pdel) != NULL) {
            Next(Prev(*Pdel)) = Succ;
        }
        Prev(Succ) = Prev(*Pdel);
        if (*Pdel == First(*L)) {
            First(*L) = Succ;
        }
        Next(*Pdel) = NULL;
        Prev(*Pdel) = NULL;
    }
}

void PrintForward(List L) {
    address P = First(L);
    printf("[");
    while (P != NULL) {
        printf("(%s, %s, %s)", Artist(P), Album(P), TitleSong(P));
        if (Next(P) != NULL) {
            printf(", ");
        }
        P = Next(P);
    }
    printf("]\n");
}

void PrintBackward(List L) {
    address P = Last(L);
    printf("[");
    while (P != NULL) {
        printf("(%s, %s, %s)", Artist(P), Album(P), TitleSong(P));
        if (Prev(P) != NULL) {
            printf(", ");
        }
        P = Prev(P);
    }
    printf("]\n");
}
