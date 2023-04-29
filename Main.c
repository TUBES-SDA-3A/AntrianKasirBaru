#include "Header.h"

int main()
{
    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Deklarasi Variabel
    DataBarang dataBarang[MAX_BARANG];
    int pilihan;

    // Algoritma
    for (;;)
    {
        system("cls");
        persediaanBarang(&dataBarang);
        displayMenu();
        scanf(" %d", &pilihan);
        switch (pilihan)
        {
        case 1:
            system("cls");
            displayListBarang(&dataBarang[MAX_BARANG]);

            break;

        case 2:

            break;

        default:
            break;
        }

        getchar();
    }
    return 0;
}