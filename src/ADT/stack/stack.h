#ifndef STACKSONG_H
#define STACKSONG_H

#include "../boolean.h"
#include "../../function.h"

#define NilStack -1
#define MaxEl 100

typedef struct {
    char singer[100];
    char album[100];
    char song[100];
} SongInfo;

typedef int addressstack;

typedef struct {
    SongInfo Songs[MaxEl];
    addressstack TOP;
} StackSong;

#define Top(S) (S).TOP
#define InfoTop(S) (S).Songs[(S).TOP]

void CreateEmptyStackSong(StackSong *S);
boolean IsEmptyStackSong(StackSong S);
boolean IsFullStackSong(StackSong S);
void PushStackSong(StackSong *S, SongInfo X);
void PopStackSong(StackSong *S, SongInfo* X);

#endif
