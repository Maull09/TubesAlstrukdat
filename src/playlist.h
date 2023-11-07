#include "ADT/boolean.h"
#include "ADT/linkedlist/linkedlist.h"
#include "ADT/arraystatis/arraySinger.h"
#include "ADT/map/map_album.h"
#include "ADT/map/map_song.h"
#include "ADT/arraydin/arrayplaylist.h"

#ifndef PLAYLIST_H
#define PLAYLIST_H

void playlistCreate();
void playlistAdd(ArrayPlaylists arrPlaylist, ListSinger LS, MapAlbum M, int pilihan);
void playlistSwap(ArrayPlaylists *arrP, int idx, int idy, int idPlaylist);
void playlistRemove();
void playlistDelete();

#endif