#include "Header.h"

int main()
{
    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Deklarasi Variabel
    DataBarang dataBarang[MAX_BARANG];
    address_P headPembeli;

    bool status = true;
    int pilihan;

    // Inisialisasi Persediaan Barang 
    persediaanBarang(&dataBarang);

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
            datangPembeli(&headPembeli, &dataBarang);
            getch();
            break;
        case 5:
            status = false;
            break;

        default:
            break;
        }
    }
    return 0;
}
