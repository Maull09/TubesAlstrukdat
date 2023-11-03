#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = NULL;
}

void CreateEmptyListofPlaylist(ListofPlaylist *LoP) {
    LoP->Neff = 0;
    for (int i = 0; i < 100; i++) {
        CreateEmpty(&LoP->listplaylist[i]);
    }
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    } else {
        return NULL;
    }
}

void Dealokasi(address *P) {
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    address P = First(L);
    while (P != NULL) {
        if (StringSama(Info(P).titlesong, X.titlesong) == 0) {
            return P;
        }
        P = Next(P);
    }
    return NULL;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
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

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != NULL) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NULL;
}

void DelP(List *L, infotype X) {
    address P = First(*L), Prec = NULL;
    while (P != NULL && StringSama(Info(P).titlesong, X.titlesong)) {
        Prec = P;
        P = Next(P);
    }
    if (P != NULL) {
        if (Prec == NULL) { 
            DelFirst(L, &P);
        } else {
            DelAfter(L, &P, Prec);
        }
        Dealokasi(&P);
    }
}

void DelLast(List *L, address *P) {
    address Prec = NULL;
    *P = First(*L);
    while (Next(*P) != NULL) {
        Prec = *P;
        *P = Next(*P);
    }
    if (Prec == NULL) {
        DelFirst(L, P);
    } else {
        DelAfter(L, P, Prec);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    printf("[");
    address P = First(L);
    while (P != NULL) {
        printf("%s", Info(P).titlesong);
        if (Next(P) != NULL) printf(", ");
        P = Next(P);
    }
    printf("]\n");
}

int NbElmt(List L) {
    int count = 0;
    address P = First(L);
    while (P != NULL) {
        count++;
        P = Next(P);
    }
    return count;
}

void InserttoListofPlaylist(ListofPlaylist *LoP, List L) {
    if (LoP->Neff < 100) {
        LoP->listplaylist[LoP->Neff] = L;
        LoP->Neff++;
    }
}

boolean IsEmpty(List L) {
    return First(L) == NULL;
}