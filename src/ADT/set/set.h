#include "../boolean.h"

// ADT Set untuk Lagu dalam sebuah Album [set_song.h]
#include "../listadt.h"

// PROTOTYPE
void CreateEmptySet(SetSong *S);
void AddSongToSet(SetSong *S, Song song);
boolean IsSongInSet(SetSong S, char *songName);
