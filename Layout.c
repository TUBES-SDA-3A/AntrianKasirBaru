#include "Header.h"

void credit()
{
    koor(30, 5), printf("db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b \n");
    koor(30, 6), printf("88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'     \n");
    koor(30, 7), printf("88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo \n");
    koor(30, 8), printf("Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ \n");
    koor(30, 9), printf("`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.     \n");
    koor(30, 10), printf(" `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P \n");

    koor(40, 14), printf("                 Credit :\n");
    koor(40, 15), printf("          This Program Made By:\n");
    koor(40, 16), printf("  - Hasna Fitriyani Khairunissa (221524011)\n");
    koor(40, 17), printf("  - Muhammad Azharuddin Hamid (221524018)\n");

    sleep(5);
}

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

// void tampilanStruk(Kasir kasir, Pembeli pembeli, DataBarang barangBelian, int uangBayar, int kembalian) {
//     // Deklarasi Variabel
//     Struk struk;
//     time(&struk.timestamp);

//     // Mengisi Data Struk
//     strcpy(struk.namaPembeli, pembeli.namaPembeli);
//     strcpy(struk.namaKasir, kasir.namaKasir);
//     strcpy(struk.namaBarang, barangBelian.nama);
//     struk.hargaBarang = barangBelian.harga;
//     struk.jumlahBarang = pembeli.barangBelian->jumlahBarang;
//     struk.uangBayar = uangBayar;
//     struk.totalHarga = pembeli.hargaTotal;
//     struk.kembalian = kembalian;

//     // Menampilkan Struk
//     system("cls");
//     koor(35, 3), printf("=============== SUPERMARKET JAYA ===============");
//     koor(35, 4), printf("           STRUK PEMBAYARAN BARANG");
//     koor(5, 6), printf("Nama Pembeli: %s", struk.namaPembeli);
//     koor(60, 6), printf("Kasir: %s", struk.namaKasir);
//     koor(5, 7), printf("Barang Belian: %s", struk.namaBarang);
//     koor(60, 7), printf("Harga: %d", struk.hargaBarang);
//     koor(5, 8), printf("Jumlah Beli: %d", struk.jumlahBarang);
//     koor(60, 8), printf("Total Harga: %d", struk.totalHarga);
//     koor(5, 10), printf("Uang Bayar: %d", struk.uangBayar);
//     koor(60, 10), printf("Kembalian: %d", struk.kembalian);
//     koor(5, 12), printf("Timestamp: %s", ctime(&struk.timestamp));
//     koor(5, 15), printf("Terima Kasih Telah Berbelanja di SUPERMARKET JAYA");
//     getch();
// }

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

    koor(33, y + 1), printf("%c", 192);
    for (int i = 0; i < 57; i++)
    {
        printf("%c", 196);
    }
    koor(91, y + 1), printf("%c", 217);
}

void tampilListAntrian(DataKasir kasir[3], int flagAntrian)
{
    int x = 10, i;
    address_A transA;
    koor(45, 1), printf("Antrian di kasir Supermarket Jaya");
    for (i = 0; i < 3; i++)
    {
        int j = 1;
        int y = 3;

        koor(x, y), printf("Kasir %d (%s)", kasir[i].Nomor, kasir[i].namaKasir);

        if (kasir[i].next == Nil)
        {
            koor(x, y + 2), printf("Antrian masih kosong");
        }
        else
        {
            transA = kasir[i].next;
            y = y + 1;
            while ((transA) != Nil)
            {
                y++;
                koor(x, y), printf("%d. %s", j, transA->Pembeli->namaPembeli);
                transA = (transA)->next;
                j++;
            }
        }
        x = x + 40;
    }
    if (flagAntrian == 1)
    {
        koor(5, 25), printf("Ketik apapun untuk kembali ke menu!!");
        getch();
    }
}

void closeProgram()
{
    system("cls");
    koor(10, 9), printf("d8b   db d888888b  .o88b. d88888b d888888b  .d88b.  .d8888. d88888b d88888b db    db  .d88b.  db    db \n");
    koor(10, 10), printf("888o  88   `88'   d8P  Y8 88'     `~~88~~' .8P  Y8. 88'  YP 88'     88'     `8b  d8' .8P  Y8. 88    88 \n");
    koor(10, 11), printf("88V8o 88    88    8P      88ooooo    88    88    88 `8bo.   88ooooo 88ooooo  `8bd8'  88    88 88    88 \n");
    koor(10, 12), printf("88 V8o88    88    8b      88~~~~~    88    88    88   `Y8b. 88~~~~~ 88~~~~~    88    88    88 88    88 \n");
    koor(10, 13), printf("88  V888   .88.   Y8b  d8 88.        88    `8b  d8' db   8D 88.     88.        88    `8b  d8' 88b  d88 \n");
    koor(10, 14), printf("VP   V8P Y888888P  `Y88P' Y88888P    YP     `Y88P'  `8888Y' Y88888P Y88888P    YP     `Y88P'  ~Y8888P'");
    sleep(5);
    exit(0);
}
