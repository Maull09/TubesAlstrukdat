#include "stack.h"
#include <stdio.h>

void CreateEmptyStackSong(StackSong *S) {
    S->TOP = IDX_UNDEF;
}

void clearStack(StackSong *S){
    CreateEmptyStackSong(S);
}

boolean IsEmptyStackSong(StackSong S) {
    return (S.TOP == IDX_UNDEF);
}

boolean IsFullStackSong(StackSong S) {
    return (S.TOP == CAPACITY - 1);
}

void PushStackSong(StackSong *S, Lagu X) {
    if (!IsFullStackSong(*S)) {
        S->TOP++;
        S->Songs[S->TOP] = X;
    }
}

void PopStackSong(StackSong *S, Lagu* X) {
    if (!IsEmptyStackSong(*S)) {
        *X = S->Songs[S->TOP];
        S->TOP--;
    }
}

void displayStack(StackSong *S) {
    if (IsEmptyStackSong(*S)) {
        printf("[]\n");
    } else {
        int i, nomor = 1;
        printf("[");
            for (i = 0; i <= S->TOP; i++) {
                printf("%d. %s - %s: %s", nomor, S->Songs[i].artist, S->Songs[i].album, S->Songs[i].titlesong);
                if (i != S->TOP) printf(",\n ");
                nomor++;
            }
        printf("]\n");
    }
}