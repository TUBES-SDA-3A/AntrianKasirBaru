#include "Header.h"

int main()
{
    // Deklarasi Variabel
    DataBarang dataBarang[MAX_BARANG];
    DataKasir kasir[3];
    address_P headPembeli;
    // Kasir kasir;
    Pembeli pembeli;
    DataBarang barangBelian;
    int uangBayar, kembalian;


    bool status = true;
    int pilihan;

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
            break;

        case 5:
            closeProgram();
            break;

        // case 6:
        //     tampilanStruk(kasir, pembeli, barangBelian, uangBayar, kembalian);
        //     break;

        default:
            koor(43, 22), printf("Masukan tidak valid. Silahkan masukan kembali!");
            getch();
            break;
        }
    }
    return 0;
}
