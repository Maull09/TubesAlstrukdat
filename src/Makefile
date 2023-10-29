# Compiler yang akan digunakan (gcc)
CC = gcc

# Semua file sumber yang dibutuhkan untuk build target
start: bulid
	./main

bulid : clean
	$(CC) -o main main.c function.c console.c ADT/arraystatis/arraySinger.c ADT/map/map_album.c ADT/map/map_song.c ADT/mesin_karakter/mesinkarakter.c ADT/mesin_kata/mesinkata.c ADT/mesin_input/mesininput.c ADT/mesin_kalimat/mesinkalimat.c ADT/queue/queue.c ADT/arraydin/arrayplaylist.c ADT/linkedlist/linkedlist.c ADT/set/set.c ADT/stack/stack.c


clean:
	rm -f *.o main

