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
}

void displayPersedianBarang()
{
}

// void generateKodeStruk(char *kodeStruk, char *idPembeli) {
//     strcpy(kodeStruk, "SPRMRKTJY");
//     strcat(kodeStruk, idPembeli);
// }

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

void displayListBarang(DataBarang dataBarang[MAX_BARANG])
{
	int i;
	printf("\t\t\t\tList Barang Toko Corona\n");
	printf("Nama Barang\t\t\t\t\tStok Barang\t\t\t\tHarga\n");

	for (i = 0; i < MAX_BARANG; i++)
	{
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n", i + 1, dataBarang[i].nama, dataBarang[i].stok, dataBarang[i].harga);
	}

}
