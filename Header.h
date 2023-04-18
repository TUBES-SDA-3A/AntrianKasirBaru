/*
Kelompok : 3A
Anggota :
        * Daniel Reinhard Pandapotan Butar butar 221524006
        * Hasna Fitriyani Khairunissa  221524011
        * Muhammad Azharuddin Hamid  221524018
*/

#ifndef header_h
#define header_h
#define Nil NULL
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_BARANG 20

typedef const char *infochar;
typedef struct Pembeli *address_P;
typedef struct List_Barang *address_B;
typedef struct List_BarangBelian *address_BB;
typedef struct Antrian *address_A;

typedef struct Pembeli
{
    infochar namaPembeli;
    address_BB barangBelian;
    int uangPembeli;
    int hargaTotal;
    int noKasir;
    address_P next;
} Pembeli;

typedef struct List_Barang
{
    infochar nama;
    int stok;
    int harga;
} DataBarang;

typedef struct List_BarangBelian
{
    infochar namaBarang;
    int jumlahBarang;
    address_BB next;
} List_BarangBelian;

typedef struct Antrian
{
    address_P Pembeli;
    address_A next;
} Antrian;

typedef struct Kasir
{
    int Nomor;
    address_A next;
    infochar namaKasir;
} dataKasir;

bool isEmptyPembeli(address_P p);
void createNodePembeli(address_P *headPembeli, address_P *newPembeli, address_BB *q, infochar Nama_Pembeli, int No_Kasir, int uangPembeli);
void persediaanBarang(DataBarang dataBarang[MAX_BARANG]);
bool isEmptyBarangBelian(address_BB p);
void createNodeBarangBelian(address_BB *headBarangBelian, address_BB *newBarangBelian, infochar nama_barang, int jumlah_barang);
void delAwalBarangBelian(address_BB *barangBelian);


#endif