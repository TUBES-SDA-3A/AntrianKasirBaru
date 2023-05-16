#include "Header.h"

int main()
{
    // Deklarasi Variabel
    DataBarang dataBarang[MAX_BARANG];
    DataKasir kasir[3];
    address_P headPembeli;
    
    int uangBayar, kembalian;
    bool status = true;
    int pilihan = 0;

    // Inisialisasi
    persediaanBarang(&dataBarang);
    initKasir(&kasir);

    // Alokasi Node
    alokasiNodePembeli(&headPembeli);

    credit();

    // Algoritma
    while (status)
    {
        system("cls");
        displayMenu();
        pilihan = inputPilihan(5);
        switch (pilihan)
        {
        case 1:
            system("cls");
            displayPersediaanBarang(dataBarang, 1);
            break;

        case 2:
            system("cls");
            mengantrikanPembeli(&headPembeli, &dataBarang, &kasir);
            break;

        case 3:
            system("cls");
            tampilListAntrian(kasir, 1);
            break;

        case 4:
            system("cls");
            prosesAntrian(&kasir, dataBarang);
            break;

        case 5:
            closeProgram();
            break;

        default:
            koor(37, 22), printf("Masukan tidak valid. Silahkan masukan kembali!");
            getch();
            break;
        }
    }
    return 0;
}
