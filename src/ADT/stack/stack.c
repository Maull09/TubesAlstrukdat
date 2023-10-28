#include "stack.h"

void CreateEmptyStackSong(StackSong *S) {
    S->TOP = NilStack;
}

boolean IsEmptyStackSong(StackSong S) {
    return (S.TOP == NilStack);
}

boolean IsFullStackSong(StackSong S) {
    return (S.TOP == MaxEl - 1);
}

void PushStackSong(StackSong *S, SongInfo X) {
    if (!IsFullStackSong(*S)) {
        S->TOP++;
        S->Songs[S->TOP] = X;
    }
}

void PopStackSong(StackSong *S, SongInfo* X) {
    if (!IsEmptyStackSong(*S)) {
        *X = S->Songs[S->TOP];
        S->TOP--;
    }
}
