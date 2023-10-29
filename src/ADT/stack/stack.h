#ifndef STACKSONG_H
#define STACKSONG_H

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"

#define Top(S) (S).TOP
#define InfoTop(S) (S).Songs[(S).TOP]

void CreateEmptyStackSong(StackSong *S);
boolean IsEmptyStackSong(StackSong S);
boolean IsFullStackSong(StackSong S);
void PushStackSong(StackSong *S, Lagu X);
void PopStackSong(StackSong *S, Lagu* X);

#endif
