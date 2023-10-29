#include "stack.h"

void CreateEmptyStackSong(StackSong *S) {
    S->TOP = IDX_UNDEF;
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
