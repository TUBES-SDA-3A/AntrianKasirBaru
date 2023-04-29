#include "Header.h"

int main()
{
    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Deklarasi Variabel
    bool status = true;
    DataBarang dataBarang[MAX_BARANG];
    int pilihan;
    persediaanBarang(&dataBarang);

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
            displayListBarang(dataBarang);
            getch();
            break;

        case 2:
            system("cls");
            printf("test");
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
