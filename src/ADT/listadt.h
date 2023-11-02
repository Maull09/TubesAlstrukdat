// multiadt.h

#ifndef MULTIADT_H
#define MULTIADT_H

#include "boolean.h"
#include "../function.h"
// #include "../listadt.h"

#define IdxMin 1
#define IdxUndef -999
#define MaxSingers 100

// ADT 1 Untuk array Singer [arraySinger.h]
typedef struct {
    char singerName[255];
} Singer;

typedef struct {
    Singer singers[MaxSingers];
    int Neff;   // Jumlah penyanyi sebenarnya
} ListSinger;


// ADT 3 untuk set [set.h]
#define MaxSetSongs 100
typedef struct {
    char songName[100];
} Song;

typedef struct {
    char albumName[100];   // ID album tempat lagu ini berasal
    Song songs[MaxSetSongs];
    int Neff; // Jumlah lagu sebenarnya dalam set
} SetSong;

typedef struct {
    SetSong Songs[100];
    int Neff;
} ListofSetSong;


// ADT 4 Untuk Album dan Map Album [map_album.h]
#define NilMapAlbum 0
#define Undefined -999
#define MaxAlbums 100

typedef struct {
    char albumName[100];
} Album;

typedef struct {
    char SingerName[100];
    Album albums[MaxAlbums];
    int Neff;   // Jumlah album sebenarnya
} MapAlbum;

typedef struct {
    MapAlbum MapAlbums[100];
    int Neff;
} ListMapAlbum;
 

// // ADT 4 Untuk Song dan Map Song [map_song.h]
#define NilMapSong 0
#define UndefinedMapSong -999
#define MaxSongs 100

typedef struct {
    char albumName[100];
    Song songs[MaxSongs];
    int Neff;   // Jumlah lagu sebenarnya
} MapSong;

typedef struct {
    MapSong MapSongs[90];
    int Neff;
} ListMapSong;

// ADT 5 Untuk Queue dan Lagu [queue.h]
#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
    char artist[100];
    char album[100];
    char titlesong[100];
} Lagu;

/* Definisi elemen dan address */
typedef Lagu ElTypeQueue;
typedef struct {
    ElTypeQueue buffer[CAPACITY]; 
    int idxHead;
    int idxTail;
} QueueLagu;


// ADT 6 Untuk stack [stack.h]
typedef int addressstack;

typedef struct {
    Lagu Songs[CAPACITY];
    addressstack TOP;
} StackSong;


// ADT 7 untuk linked list [linkedlist.h]
#define Nil NULL

typedef Song infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
    char PlaylistName[100];
} List;

typedef struct {
    List listplaylist[100];
    int Neff;
} ListofPlaylist;


// ADT 2 Untuk array Playlist [arrayplaylist.h]
#define INIT_SIZE 10 // Ukuran awal array dinamis

typedef struct {
    char name[255]; // Nama dari playlist
} Playlist;

typedef struct {
    Playlist *playlists;  // Pointer ke array dinamis dari playlist
    int Neff;             // Jumlah playlist yang ada saat ini
    int capacity;        // Kapasitas array dinamis saat ini
} ArrayPlaylists;

// ADT 8 untuk mesin karakter [mesinkarakter.h]
#define MARK ';'
#define MARK2 '\0'
#define NEWLINE '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;


// ADT 9 untuk mesin kata [mesinkata.h]
#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;


// ADT 10 untuk mesin kalimat [mesinkalimat.h]
#define KMax 450

typedef struct {
  char TabKalimat[KMax+1];
  int Length;
} Kalimat;


#endif
