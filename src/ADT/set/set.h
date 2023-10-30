#include "../boolean.h"

// ADT Set untuk Lagu dalam sebuah Album [set_song.h]
#include "../listadt.h"

// PROTOTYPE
void CreateEmptySet(SetSong *S);
void CreateEmptyListSet(ListofSetSong *S);
void AddSongToSet(SetSong *S, Song song);
boolean IsSongInSet(SetSong S, char *songName);
void AddSetSongToListSetSong(ListofSetSong *list, SetSong setsong);
void DisplaySetSong(SetSong S);
void DisplayListOfSetSong(ListofSetSong list);