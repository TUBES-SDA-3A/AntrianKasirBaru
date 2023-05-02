#include "Header.h"

void banner()
{
    setColor(4);
    koor(0, 1), printf("========================================================================================================================");
    koor(0, 2), printf("==      ===========================================================  =========================    ======================");
    koor(0, 3), printf("=  ====  ==========================================================  ==========================  =======================");
    koor(0, 4), printf("=  ====  ==========================================================  =============  ===========  =======================");
    koor(0, 5), printf("==  =======  =  ==    ====   ===  =   ===  =  = ====   ===  =   ===  =  ===   ===    ==========  ====   ===  =  ===   ==");
    koor(0, 6), printf("====  =====  =  ==  =  ==  =  ==    =  ==        ==  =  ==    =  ==    ===  =  ===  ===========  ===  =  ==  =  ==  =  =");
    setColor(1);
    koor(0, 7), printf("======  ===  =  ==  =  ==     ==  =======  =  =  =====  ==  =======   ====     ===  ===========  ======  ===    =====  =");
    koor(0, 8), printf("=  ====  ==  =  ==    ===  =====  =======  =  =  ===    ==  =======    ===  ======  ======  ===  ====    =====  ===    =");
    koor(0, 9), printf("=  ====  ==  =  ==  =====  =  ==  =======  =  =  ==  =  ==  =======  =  ==  =  ===  ======  ===  ===  =  ==  =  ==  =  =");
    koor(0, 10), printf("==      ====    ==  ======   ===  =======  =  =  ===    ==  =======  =  ===   ====   ======     =====    ===   ====    =");
    koor(0, 11), printf("========================================================================================================================");
    setColor(7);
}

void displayMenu()
{
    banner();
    koor(45, 14), printf("1. Persediaan stok barang");
    koor(45, 15), printf("2. Datang pembeli baru");
    koor(45, 16), printf("3. Tampil antrian kasir");
    koor(45, 17), printf("4. Proses antrian semua kasir");
    koor(45, 18), printf("5. Tutup Toko");
    koor(45, 20), printf("Masukan Pilihan : ");
}

void tampilanStruk(address_P pembeli, DataBarang dataBarang[MAX_BARANG])
{
    int barangBelian, namaPembeli, jumlahBarang, hargaTotal;
    char kodeStruk[10], idPembeli[5];
    int noBarang = 1, kodeBarang;

    printf("\t\t\t\tSUPERMARKET JAYA\n");
    printf("\t\t\t");
    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\t\t\t%s\n\n", idPembeli[5]);
    printf("\t\t\t%s\n\n", pembeli->namaPembeli);
    while (pembeli->barangBelian->next != Nil)
    {
        kodeBarang = searchBarang(dataBarang, pembeli->barangBelian->namaBarang);
        printf("%d. %s", noBarang, pembeli->barangBelian->namaBarang);
        printf("%d X %d = %d", pembeli->barangBelian->jumlahBarang, dataBarang[kodeBarang].harga, pembeli->barangBelian->jumlahBarang * dataBarang[kodeBarang].harga);
    }

    printf("\t\t\tTotal = %d\n\n", pembeli->hargaTotal);
    printf("\t\t\t");
    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\t\t\t%s\n\n", kodeStruk[10]);
    printf("\t\tTekan apa saja untuk kembali ke menu utama");
    getchar();
    displayMenu();
}

void displayListBarang(DataBarang dataBarang[MAX_BARANG], int flagListBarang)
{
    int y;
    if (flagListBarang == 1)
    {
        y = 8;
    }
    else
    {
        y = 5;
    }

    koor(45, y - 3), printf("List Barang di Supermarket Jaya");
    koor(35, y), printf("No. ");
    koor(45, y), printf("Nama Barang");
    koor(75, y), printf("Stok");
    koor(85, y), printf("Harga");
    for (int i = 0; i < MAX_BARANG; i++)
    {
        y++;
        koor(35, y), printf("%d. ", i + 1);
        koor(45, y), printf("%s", dataBarang[i].nama);
        koor(75, y), printf("%d", dataBarang[i].stok);
        koor(85, y), printf("%d", dataBarang[i].harga);
    }

    if (flagListBarang == 1)
    {
        kotakPersediaanBarang(1);
        koor(5, 25), printf("Ketik apapun untuk kembali ke menu!!");
        getch();
    }
    else
    {
        kotakPersediaanBarang(2);
    }
}

void kotakPersediaanBarang(int flagKotak)
{
    int y;

    if (flagKotak == 1)
    {
        y = 7;
    }
    else
    {
        y = 4;
    }

    koor(33, y), printf("%c", 218);
    for (int i = 0; i < 57; i++)
    {
        printf("%c", 196);
    }
    koor(91, y), printf("%c", 191);

    for (int i = 0; i < 11; i++)
    {
        y++;
        koor(33, y), printf("%c", 179);
        koor(91, y), printf("%c", 179);
    }

    koor(33, y+1), printf("%c", 192);
    for (int i = 0; i < 57; i++)
    {
        printf("%c", 196);
    }
    koor(91, y+1), printf("%c", 217);
}
