#include "Header.h"

int main()
{
    // Pengaturan ukuran console dengan lebar 1000 dan tinggi 600
    HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 180, 50, 1000, 600, TRUE);

    // Deklarasi Variabel
    int pilihan;

    // Algoritma
    for (;;)
    {
        system("cls");
        displayMenu();
        scanf(" %d", &pilihan);
        switch (pilihan)
        {
        case 1:
            
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