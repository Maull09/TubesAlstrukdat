# IF2111 Algoritma dan Struktur Data STI

Suatu hari, Bondowoso jatuh cinta kepada Roro, si teteh geulis yang hanya suka dengan lagu hip-hop terbaru dari walkman-nya. Bondowoso yang memiliki sense musik yang sangat berkelas pada masanya, merasakan bahwa Roro belum melihat seluruh dunia musik yang luas.

Saya akan buatkan kamu aplikasi WayangWave yang dapat meluluhkan hati Roro”.
## Tentang Sistem Wayangwave
WayangWave merupakan sebuah aplikasi yang bisa mensimulasikan service pemutaran musik. WayangWave ini memiliki memiliki beberapa fitur utama, yaitu:
1. Memutar lagu
2. Menampilkan daftar lagu
3. Membuat dan menghapus playlist
4. Mengatur urutan dimainkannya lagu
5. Menampilkan status dari aplikasi

## Struktur Program
```
│ README.md
│ .gitignore
│
├─── bin
│       │ Makefile
│
├─── doc
│       │ Pedoman Tugas Besar.pdf
│       │ Spesifikasi Tugas Besar IF2111 2023_2024.pdf
│
├─── src
│       ├─── ADT
│       │       ├─── linkedlist
│       │       ├─── list
│       │       ├─── machine
│       │       ├─── queuestack
│       │       ├─── setmap
│       │       └─── stack
│       ├─── data
│       │       │ default.txt
│       │       │ test.txt
│       │ boolean.h
│       │ console.c
│       │ console.h
│       │ main.c
```

## Cara Menjalankan
1. Pastikan Terminal Berada di src ini
2. Cara Menjalankan ada 2 cara yaitu dengan menggunakan Makefile atau compile biasa

### a. Dengan `Makefile`

1. Pastikan `Makefile` sudah terinstall
   ```
   `Makefile`
   ```

2. buka terminal di folder src

3. ketik `make` pada terminal
   
   ```
   `make`
   ```
4. selesai

note : program akan otomatis membuild, clean dan menjalankan main


### b. Tanpa Makefile

1. Buka terminal di folder src

2. ketik ini diterminal :
   
```
  `gcc main.c function.c console.c ADT/arraystatis/arraySinger.c ADT/map/map_album.c ADT/map/map_song.c ADT/mesin_karakter/mesinkarakter.c ADT/mesin_kata/mesinkata.c ADT/mesin_input/mesininput.c ADT/mesin_kalimat/mesinkalimat.c ADT/queue/queue.c ADT/arraydin/arrayplaylist.c ADT/linkedlist/linkedlist.c ADT/set/set.c ADT/stack/stack.c ADT/graph/graph.c -o main`
```

3. Jalankan Program WayangWave diterminal
   
   ```
   ./main
   ```

4. selesai

## Command
- `START` : Command ini digunakan untuk menjalankan program BNMO
- `LOAD <filename>` : Command ini digunakan untuk membaca file yang telah disimpan dan menjalankan program WayangWave
- `LIST` : command ini digunakan untuk menampilkan list playlist yang ada, list penyanyi, list album dari penyanyi, dan list lagu yang ada di album. Terdapat dua jenis list, `DEFAULT` dan `PLAYLIST`.
- `LIST DEFAULT` : Command ini digunakan untuk melihat list penyanyi yang ada. Selanjutnya dapat memilih untuk melihat album dari penyanyi yang dipilih. Kemudian melihat lagu yang ada dari album yang dipilih. Terdapat konfirmasi apakah ingin melihat album/lagu
- `LIST PLAYLIST` : Command ini digunakan untuk menampilkan playlist yang ada pada pengguna.
- `PLAY` : Command yang digunakan untuk memutar lagu atau playlist yang dipilih. Ketika command PLAY dieksekusi, queue yang ada dihapus ketika memainkan lagu atau digantikan oleh lagu dalam playlist ketika memainkan playlist. Terdapat dua jenis play, `SONG` dan `PLAYLIST`.
- `PLAY SONG` : Command ini digunakan untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu. Ketika command ini berhasil dieksekusi, queue dan riwayat lagu akan menjadi kosong.
- `PLAY PLAYLIST` : Command ini digunakan untuk memainkan lagu berdasarkan id playlist. Ketika command ini berhasil dieksekusi, current song akan menjadi lagu pada urutan pertama playlist dan queue akan berisi semua lagu yang ada dalam playlist yang akan dimainkan dan isi riwayat lagu sama dengan queue, tetapi dengan urutan yang di-reverse.
- `QUEUE` : command yang digunakan untuk memanipulasi queue lagu. Command ini memiliki 5 tipe, yaitu `SONG`, `PLAYLIST`, `SWAP`, `REMOVE`, dan `CLEAR`.
- `QUEUE SONG` : Command ini digunakan untuk menambahkan lagu ke dalam queue
- `QUEUE PLAYLIST` : Command ini digunakan untuk menambahkan lagu yang ada dalam playlist ke dalam queue
- `QUEUE SWAP <x> <y>` : Command ini digunakan untuk menukar lagu pada urutan ke x dan juga urutan ke y.
- `QUEUE REMOVE <id>` : Command QUEUE REMOVE digunakan untuk menghapus lagu dari queue. Command ini menerima input berupa urutan lagu (id) yang ingin dihapus dari queue.
- `QUEUE CLEAR` : Command QUEUE CLEAR digunakan untuk mengosongkan queue.
- `SONG` : command yang digunakan untuk navigasi lagu yang ada pada queue lagu saat ini. Terdapat 2 tipe navigasi yaitu `NEXT` dan `PREVIOUS`.
- `SONG NEXT` : Command SONG NEXT digunakan untuk memutar lagu yang berada di dalam queue.
- `SONG PREVIOUS` : Command SONG PREVIOUS digunakan untuk memutar lagu yang terakhir kali diputar.
- `PLAYLIST`: Command ini digunakan untuk melakukan basic command untuk playlist yaitu `CREATE`, `ADD`, `SWAP`, `REMOVE` dan `DELETE`.
- `PLAYLIST CREATE` : Command ini digunakan untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna.
- `PLAYLIST ADD` : Command ini digunakan untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.
- `PLAYLIST SWAP <id> <x> <y>` : Command ini digunakan untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id.
- `PLAYLIST REMOVE <id> <n>` : Command ini digunakan untuk menghapus lagu dengan urutan n pada playlist dengan index id.
- `PLAYLIST DELETE` : Command ini digunakan untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna
- `STATUS` : command yang digunakan untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.
- `SAVE <filename>` : command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
- `QUIT` : merupakan  command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
- `HELP` : HELP merupakan command yang digunakan menampilkan daftar command yang mungkin untuk dieksekusi dengan deskripsinya.
- `<INVALID COMMAND>` : Command-command selain yang disebutkan di atas dinyatakan akan tidak valid dan hanya akan mengeluarkan teks error.

## Cara Menjalankan Driver Abstract Data Type
1. Buka folder bin
2. Ketik ini diterminal :
```

```


## Anggota Kelompok 7
| No. | NIM | Nama |
|-----|-----|------|
| 1 | 18222106 | Audra Zelvania Putri Harjanto |
| 2 | 18222120 | Aqila Ataa |
| 3 | 18222122 | Regan Adiesta Mahendra |
| 4 | 18222125 | Sekar Anindita Nurjadini |
| 5 | 18222126 | Alfaza Naufal Zakiy |
| 6 | 18222140 | Mohamad Maulana Firdaus R |
