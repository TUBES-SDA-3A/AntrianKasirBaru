#include "Header.h"

/****************** Datang Pembeli *******************/
void datangPembeli(address_P *headPembeli, DataBarang (*dataBarang)[MAX_BARANG], DataKasir (*kasir)[3])
{
	infochar namaPembeli = (infochar)malloc(sizeof(infochar));
	int noKasir;
	address_P newPembeli;

	alokasiNodePembeli(&newPembeli);

	banner();

	koor(40, 16), printf("Masukan nama untuk pembeli : ");
	scanf(" %[^\n]", namaPembeli);

	beliBarang(&(*dataBarang), &newPembeli);

	system("cls");
	tampilListAntrian((*kasir), 2);
	koor(40, 25), printf("Masukan No kasir yang di pilih (1-3): ");
	scanf("%d", &noKasir);

	createNodePembeli(&(*headPembeli), &newPembeli, namaPembeli, noKasir);
	masukAntrian(&(*kasir)[noKasir - 1], newPembeli);

	koor(35, 10), printf("%s sudah masuk kedalam antrian pada kasir %d", newPembeli->namaPembeli, newPembeli->noKasir);
	getch();
}

void beliBarang(DataBarang (*dataBarang)[MAX_BARANG], address_P *newPembeli)
{
	int kodeBarang, jumlahBarang, pilihanLagi = 1;
	int tempHargaTotal = 0;

	alokasiNodeBarangBelian(&(*newPembeli)->barangBelian);

	while (pilihanLagi == 1)
	{
		system("cls");
		displayListBarang((*dataBarang), 2);
		koor(45, 17), printf("Masukan kode barang yang dipilih : ");
		scanf("%d", &kodeBarang);
		kodeBarang -= 1;

		koor(45, 18), printf("Masukan jumlah barang : ");
		scanf("%d", &jumlahBarang);

		if ((*dataBarang)[kodeBarang].stok > 0 && (*dataBarang)[kodeBarang].stok >= jumlahBarang)
		{
			(*newPembeli)->hargaTotal = (*dataBarang)[kodeBarang].harga * jumlahBarang;
			(*dataBarang)[kodeBarang].stok = (*dataBarang)[kodeBarang].stok - jumlahBarang;
			createNodeBarangBelian(&(*newPembeli)->barangBelian, (*dataBarang)[kodeBarang].nama, jumlahBarang);
			koor(30, 20), printf("%s berhasil ditambahkan ke dalam keranjang.", (*dataBarang)[kodeBarang].nama);
			system("cls");
			koor(45, 10), printf("Ingin pesan lagi ? ");
			koor(45, 11), printf("1. YA");
			koor(45, 12), printf("2. Tidak");
			koor(45, 13), printf("Masukan pilihan : ");
			scanf("%d", &pilihanLagi);
		}
		else if ((*dataBarang)[kodeBarang].stok < 0)
		{
			koor(30, 20), printf("Maaf persediaan habis. Silahkan beli yang lain!!");
			getch();
		}
		else if ((*dataBarang)[kodeBarang].stok < jumlahBarang)
		{
			koor(25, 20), printf("Maaf persediaan kurang. Silahkan ubah jumlah barang atau beli yang lain!!");
			getch();
		}
	}
}

/****************** Pembeli *******************/
void alokasiNodePembeli(address_P *tempPembeli)
{
	*tempPembeli = (address_P)malloc(sizeof(Pembeli));
	(*tempPembeli)->barangBelian = Nil;
	(*tempPembeli)->next = Nil;
}

void createNodePembeli(address_P *headPembeli, address_P *newPembeli, infochar namaPembeli, int noKasir)
{
	/* 	I.S : headPembeli dan newPembeli belum memiliki nilai atau masih kosong, dan address_BB q, infochar namaPembeli, int No_Kasir, dan int uangPembeli diisi dengan nilai yang sesuai.
		F.S : terbentuknya sebuah node baru pada linked list pembeli dengan informasi yang sudah diisi dan disambungkan ke linked list.
	*/

	address_P Traversal;

	(*newPembeli)->namaPembeli = namaPembeli;
	(*newPembeli)->noKasir = noKasir;
	(*newPembeli)->uangPembeli = 0;

	if ((*headPembeli)->next == Nil)
	{
		*headPembeli = *newPembeli;
	}
	else
	{
		Traversal = *headPembeli;
		while ((*headPembeli)->next == Nil)
		{
			Traversal = Traversal->next;
		}
		(Traversal)->next = *newPembeli;
	}
}

/****************** Persediaan Barang *****************/
void persediaanBarang(DataBarang (*dataBarang)[MAX_BARANG])
{
	(*dataBarang)[0].nama = "Shampo", (*dataBarang)[0].stok = 50, (*dataBarang)[0].harga = 12000;
	(*dataBarang)[1].nama = "Sabun Cuci Piring", (*dataBarang)[1].stok = 100, (*dataBarang)[1].harga = 5000;
	(*dataBarang)[2].nama = "Sendok & Garpu", (*dataBarang)[2].stok = 30, (*dataBarang)[2].harga = 25000;
	(*dataBarang)[3].nama = "Bubur Bayi", (*dataBarang)[3].stok = 150, (*dataBarang)[3].harga = 10000;
	(*dataBarang)[4].nama = "Susu UHT", (*dataBarang)[4].stok = 60, (*dataBarang)[4].harga = 25000;
	(*dataBarang)[5].nama = "Mie Instan", (*dataBarang)[5].stok = 300, (*dataBarang)[5].harga = 2500;
	(*dataBarang)[6].nama = "Air Mineral", (*dataBarang)[6].stok = 160, (*dataBarang)[6].harga = 4000;
	(*dataBarang)[7].nama = "P3K", (*dataBarang)[7].stok = 70, (*dataBarang)[7].harga = 50000;
	(*dataBarang)[8].nama = "Kue Kering", (*dataBarang)[8].stok = 40, (*dataBarang)[8].harga = 60000;
	(*dataBarang)[9].nama = "Chiki", (*dataBarang)[9].stok = 100, (*dataBarang)[9].harga = 12000;
}

/****************** Barang Belian *******************/
void alokasiNodeBarangBelian(address_BB *tempBarangBelian)
{
	*tempBarangBelian = (address_BB)malloc(sizeof(List_BarangBelian));
	(*tempBarangBelian)->next = Nil;
}

void createNodeBarangBelian(address_BB *headBarangBelian, infochar namaBarang, int jumlahBarang)
{
	/* I.S : - headAntrian merupakan pointer ke list antrian yang awalnya kosong atau NULL.
			 - newAntrian merupakan pointer yang belum dialokasikan ke memori.
			 - Pembeli merupakan data pembeli yang akan ditambahkan ke dalam node antrian.
	   F.S : newAntrian telah dialokasikan ke memori, memiliki nilai next yang diisi dengan NULL, dan memiliki nilai Pembeli yang diisi dengan Pembeli.
	*/

	address_BB transBB;

	address_BB newBarangBelian;

	alokasiNodeBarangBelian(&newBarangBelian);

	(newBarangBelian)->next = Nil;
	(newBarangBelian)->namaBarang = namaBarang;
	(newBarangBelian)->jumlahBarang = jumlahBarang;

	if ((*headBarangBelian)->next == Nil)
	{
		*headBarangBelian = newBarangBelian;
	}
	else
	{
		transBB = *headBarangBelian;
		while (transBB->next != Nil)
		{
			transBB = (transBB)->next;
		}
		transBB = newBarangBelian;
	}
}

void delAwalBarangBelian(address_BB *barangBelian)
{
	/* I.S : Terdapat sebuah node yang menjadi inputan fungsi Del_Awal_BarangBelian, dan pada awalnya node tersebut menunjuk ke head dari sebuah list.
	   F.S : Node pertama dari list telah dihapus dan nilai nama barang dari node tersebut disimpan pada variabel X.
	*/

	address_BB tempBarangBelian;

	if ((*barangBelian)->next == Nil)
	{
		printf("List Kosong");
	}
	else
	{
		tempBarangBelian = *barangBelian;
		*barangBelian = (*barangBelian)->next;
		tempBarangBelian = NULL;
		free(tempBarangBelian);
	}
}

/****************List Antrian****************/
void initKasir(DataKasir (*kasir)[3])
{
	(*kasir)[0].namaKasir = "Daniel Reinhard";
	(*kasir)[0].Nomor = 1;
	(*kasir)[0].next = Nil;
	(*kasir)[1].namaKasir = "Hasna Fitriyani";
	(*kasir)[1].Nomor = 2;
	(*kasir)[1].next = Nil;
	(*kasir)[2].namaKasir = "Muhammad Azhar";
	(*kasir)[2].Nomor = 3;
	(*kasir)[2].next = Nil;
}

void alokasiAntrian(address_A *tempAntrian)
{
	*tempAntrian = (address_A)malloc(sizeof(Antrian));
	(*tempAntrian)->next = Nil;
	(*tempAntrian)->Pembeli = Nil;
}

void masukAntrian(DataKasir *kasir, address_P newPembeli)
{
	/* I.S : - headAntrian: pointer menuju node pertama dari list antrian
			 - newPembeli: pointer menuju pada node pembeli
	   F.S : Jika newAntrian berhasil dialokasikan, maka newAntrian akan menjadi node baru pada list antrian yang menunjuk ke Pembeli.
			 Jika headAntrian masih kosong, maka headAntrian akan menunjuk ke newAntrian.
			 Jika headAntrian tidak kosong, maka newAntrian akan ditambahkan pada akhir list antrian.
	*/

	address_A tempAntrian;

	if ((*kasir).next != Nil)
	{
		tempAntrian = (*kasir).next;
		while ((tempAntrian)->next != Nil)
		{
			tempAntrian = (tempAntrian)->next;
		}
		alokasiAntrian(&(tempAntrian)->next);
		(tempAntrian)->next->Pembeli = newPembeli;
		(tempAntrian)->next->next = Nil;
	}
	else
	{
		alokasiAntrian(&tempAntrian);
		tempAntrian->Pembeli = newPembeli;
		tempAntrian->next = Nil;
		(*kasir).next = tempAntrian;
	}
}

void prosesAntrian(DataKasir (*kasir)[3]) {
	//proses antrian ini memproses alias menghapus antrian pertama di setiap kasir.
    for (int i = 0; i < 3; i++) {
        if ((*kasir)[i].next != Nil) { // cek apakah ada pembeli dalam antrian kasir
            address_A temp = (*kasir)[i].next;
            (*kasir)[i].next = temp->next; // hapus pembeli pertama dalam antrian
            free(temp);
        }
    }
}

// void cetakStruk(DataKasir (*kasir)[3]) {
	//untuk cetak struk belum terkoneksi dengan antrian
//     for (int i = 0; i < 3; i++) {
//         if ((*kasir)[i].next != Nil) { // cek apakah ada pembeli dalam antrian kasir
//             printf("=========================================\n");
//             printf("              Struk Belanja\n");
//             printf("=========================================\n");
//             printf("Nama Kasir: %s\n", (*kasir)[i].namaKasir);
//             address_P temp = (*kasir)[i].next->Pembeli;
//             printf("Nama Pembeli: %s\n", temp->namaPembeli);
//             printf("No Kasir: %d\n", temp->noKasir);
//             printf("=========================================\n");
//             printf("Barang\t\tJumlah\t\tHarga Satuan\n");
//             printf("-----------------------------------------\n");
//             address_BB current = temp->barangBelian;
//             while (current != Nil) {
//                 printf("%s\t\t%d\t\tRp %d\n", current->namaBarang, current->jumlahBarang, getHarga(current->namaBarang));
//                 current = current->next;
//             }
//             printf("=========================================\n");
//             printf("Total Harga: Rp %d\n", temp->hargaTotal);
//             printf("Bayar: Rp %d\n", temp->uangPembeli);
//             printf("Kembalian: Rp %d\n", temp->uangPembeli - temp->hargaTotal);
//             printf("=========================================\n");
//         }
//     }
// }

// void prosesAntrian(DataKasir (*kasir)[3]) {
	// proses antrian yang telah adding modul cetakStruk
//     for (int i = 0; i < 3; i++) {
//         if ((*kasir)[i].next != Nil) { // cek apakah ada pembeli dalam antrian kasir
//             address_A temp = (*kasir)[i].next;
//             (*kasir)[i].next = temp->next; // hapus pembeli pertama dalam antrian
//             cetakStruk(kasir); // cetak struk setelah pembeli diproses
//             free(temp);
//         }
//     }
// }



int searchBarang(DataBarang dataBarang[MAX_BARANG], infochar namaBarang)
{
	for (int i = 0; i < MAX_BARANG; i++)
	{
		if (strcmp(dataBarang[i].nama, namaBarang) == 0)
		{
			return i;
		}
	}
}
