/*
Kelompok : 3A
Anggota :
        * Hasna Fitriyani Khairunissa  221524011
        * Muhammad Azharuddin Hamid  221524018
*/

#ifndef header_h
#define header_h
#define Nil NULL
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#define MAX_BARANG 10

typedef const char *infochar;
typedef struct Pembeli *address_P;
typedef struct ListKeranjang *address_K;
typedef struct Antrian *address_A;

typedef struct Pembeli
{
    infochar namaPembeli;
    address_K Keranjang;
    int hargaTotal;
    int noKasir;
    address_P next;
} Pembeli;

typedef struct DataBarang
{
    infochar nama;
    int stok;
    int harga;
} DataBarang;

typedef struct ListKeranjang
{
    infochar namaBarang;
    int jumlahBarang;
    address_K next;
} ListKeranjang;

typedef struct Antrian
{
    Pembeli pembeliDiAntrian;
    address_A next;
} Antrian;

typedef struct Kasir
{
    int Nomor;
    address_A next;
    infochar namaKasir;
} DataKasir;

int inputPilihan(int flagInput);
bool validasiMasukan(int pilihan, int flagValidasi);
void checkBarangSama(address_K *transkeranjang, DataBarang dataBarang[MAX_BARANG], int kodeBarangBaru, bool *statusSama);
void initPembeli(address_P nextP, Pembeli *pembeli);
void createNodePembeli(address_P *headPembeli, address_P *newPembeli, infochar namaPembeli, int noKasir);
void alokasiNodePembeli(address_P *tempPembeli);
void mengantrikanPembeli(address_P *headPembeli, DataBarang (*dataBarang)[MAX_BARANG], DataKasir (*kasir)[3]);
void catatKeranjang(DataBarang (*dataBarang)[MAX_BARANG], address_P *newPembeli);
void persediaanBarang(DataBarang (*dataBarang)[MAX_BARANG]);
void alokasiNodeKeranjang(address_K *tempKeranjang);
void createNodeKeranjang(address_K *headKeranjang, infochar namaBarang, int jumlahBarang);
void alokasiAntrian(address_A *tempAntrian);
void masukAntrian(DataKasir *kasir, address_P Pembeli);
void initKasir(DataKasir (*kasir)[3]);
void prosesAntrian(DataKasir (*kasir)[3], DataBarang dataBarang[MAX_BARANG]);
int searchBarang(DataBarang dataBarang[MAX_BARANG], infochar namaBarang);

// Tampilan
void credit();
void banner();
void displayMenu();
void displayPersediaanBarang(DataBarang dataBarang[MAX_BARANG], int flagPersediaanBarang);
void displayListKeranjang(Pembeli pembeli);
void tampilListAntrian(DataKasir kasir[3], int flagAntrian);
void kotakPersediaanBarang(int flagKotak);
void tampilanStruk(Pembeli pembeli, DataBarang dataBarang[MAX_BARANG], infochar namaKasir, int uangBayar);
void displayWaktu(int x, int y);
void closeProgram();

// Teknis
void koor(int x, int y);
void setColor(unsigned short color);



#endif