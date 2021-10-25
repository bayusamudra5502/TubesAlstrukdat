# Mobilita

Ini adalah repository Tugas Besar Alstrukdat Kelompok 7 Kelas K03

## Setup Environment

### Install gcc dan make

1. Install `gcc` dan `make` di komputer anda. Jika menggunakan windows, kita bisa pake mingw, mingw-w64, msys2, atau yang lainnya. Jika menggunakan linux berdistro ubuntu, gunakan perintah berikut:

```bash
sudo apt install build-essential
```

2. Setup PATH environment untuk `gcc` dan `make`

### Install libcheck

1. Jika menggunakan debian atau turunannya, gunakan perintah berikut

```shell
sudo apt install check
```

2. Jika menggunakan windows, lihat intruksi [disini](https://libcheck.github.io/check/web/install.html#mingwsource).

## Kompilasi dan Run Program

### Melakukan Kompilasi

Untuk melakukan kompilasi, kita hanya perlu menjalankan perintah berikut

```shell
make build
```

### Menjalankan Program

Untuk melakukan kompilasi dan menjalankan program, kita dapat menggunakan perintaah berikut

```shell
make run
```

### Menjalankan Main Point dari ADT

Untuk menjalankan ADT, gunakan perintah sebagai berikut:

```
./run_adt.sh <Nama ADT>
```

Berikut ini adalah contoh menjalankan main point ADT `point`:

```bash
./run_adt.sh point
```

Pastikan anda telah mengubah file permission agar bisa dieksekusi:

```bash
chmod +x run_adt.sh
```

#### Dapat Kendala saat menjalankan Script?

Jika pake WSL, coba install `dos2unix`. Gunakan perintah

```shell
sudo apt install dos2unix -y
```

Lalu, jalankan perintah berikut untuk membuat run_adt versi wsl:

```shell
dos2unix -n -- run_adt.sh run_adt.wsl.sh
```

Lalu, jalankan perintah:

```shell
chmod +x run_adt.wsl.sh
./run_adt.wsl.sh
```

### Testing Unit Test

Untuk melakukan unit testing, kita dapat menjalankan perintah berikut

```shell
make test
```

Dalam project ini, kita menggunakan libcheck sebagai library untuk melakukan asersi, pastikan sudah menginstall libcheck. Jika belum, lihat Olympia carannya.

## Stuktur Project

Dalam project ini ada beberapa folder diantaranya sebagai berikut:

1. Folder `bin` merupakan isi program kita.
2. Folder `build` berisi object file dari setiap file pada src dan test.
3. Folder `src` merupakan source code kita. Dalam folder ini terdapat beberapa folder lagi, yaitu
   - Folder `components`, berisi prosedur yang dapat reusable untuk menampilkan ke layar.
   - Folder `lib`, berisi implementasi dari ADT beserta header filenya. Selain itu, bisa berisi fungsi/prosedur yang dapat membantu kita dalam menyusun file.
   - Folder `views` berisi prosedur yang digunakan untuk mencetak sebuah halaman pada layar. Contohnya seperti Menu Utama.
   - File `main.c` adalah start point program kita
4. Folder `test` berisi semua Unit Test.

## Aturan Kontribusi

Bisa dilihat di [CONTRIBUTE.md](CONTRIBUTE.md)
