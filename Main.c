#include "Header.h"

int main()
{
    // Deklarasi Variabel
    DataBarang dataBarang[MAX_BARANG];
    DataKasir kasir[3];
    address_P headPembeli;

    bool status = true;
    int pilihan;

    // Inisialisasi
    persediaanBarang(&dataBarang);
    initKasir(&kasir);

    // Alokasi Node
    alokasiNodePembeli(&headPembeli);

    // Algoritma
    while (status)
    {
        system("cls");
        displayMenu();
        scanf(" %d", &pilihan);
        switch (pilihan)
        {
        case 1:
            system("cls");
            displayListBarang(dataBarang, 1);
            break;

        case 2:
            system("cls");
            datangPembeli(&headPembeli, &dataBarang, &kasir);
            break;

        case 3:
            system("cls");
            tampilListAntrian(kasir, 1);
            break;

        case 4:
            system("cls");
            prosesAntrian(&kasir);
        case 5:

            status = false;
            break;

        default:
            koor(43, 22), printf("Masukan tidak valid. Silahkan masukan kembali!");
            getch();
            break;
        }
    }
    return 0;
}
