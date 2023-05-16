#include "Header.h"

/********************* Validasi *********************/
int inputPilihan(int flagInput)
{
	int pilihan, x, y = 20;

	if (flagInput == 5)
	{
		x = 63;
	}
	else if (flagInput == 2)
	{
		x = 64;
		y = 13;
	}

	else
	{
		x = 80;
	}

	do
	{
		koor(x, y), scanf("%d", &pilihan);
	} while (!validasiMasukan(pilihan, flagInput));

	return pilihan;
}

bool validasiMasukan(int pilihan, int flagValidasi)
{
	if (pilihan > 0 && pilihan <= flagValidasi)
	{
		return true;
	}
	else
	{
		if (flagValidasi != 5)
		{
			koor(40, 21), printf("Masukan tidak tersedia, silahkan masukan kembali!!");
			getch();
			koor(80, 20), printf("         ");
			koor(40, 21), printf("                                                  ");
		}

		return false;
	}
}

void checkBarangSama(address_K *transkeranjang, DataBarang dataBarang[MAX_BARANG], int kodeBarangBaru, bool *statusSama)
{
	while (*transkeranjang != Nil)
	{
		if (strcmp(dataBarang[kodeBarangBaru].nama, (*transkeranjang)->namaBarang) == 0)
		{
			*statusSama = true;
			return;
		}
		else
		{
			*statusSama = false;
			*transkeranjang = (*transkeranjang)->next;
		}
	}
}

/****************** Mengantrikan Pembeli *******************/
void mengantrikanPembeli(address_P *headPembeli, DataBarang (*dataBarang)[MAX_BARANG], DataKasir (*kasir)[3])
{
	infochar namaPembeli = (infochar)malloc(sizeof(infochar));
	int noKasir;
	address_P newPembeli;

	alokasiNodePembeli(&newPembeli);

	banner();

	koor(40, 16), printf("Masukan nama untuk pembeli : ");
	scanf(" %[^\n]", namaPembeli);

	catatKeranjang(&(*dataBarang), &newPembeli);

	system("cls");
	tampilListAntrian((*kasir), 2);
	koor(40, 20), printf("Masukan No kasir yang di pilih (1-3) : ");
	noKasir = inputPilihan(3);

	createNodePembeli(&(*headPembeli), &newPembeli, namaPembeli, noKasir);
	masukAntrian(&(*kasir)[noKasir - 1], newPembeli);

	system("cls");
	koor(35, 10), printf("%s sudah masuk kedalam antrian pada kasir %d", newPembeli->namaPembeli, newPembeli->noKasir);
	koor(5, 25), printf("Ketik apapun untuk kembali ke menu!!");
	getch();
}

void catatKeranjang(DataBarang (*dataBarang)[MAX_BARANG], address_P *newPembeli)
{
	int kodeBarang, jumlahBarang, pilihanLagi = 1;

	while (pilihanLagi == 1)
	{
		bool statusSama = false;
		address_K transKeranjang = (*newPembeli)->Keranjang;

		system("cls");
		displayPersediaanBarang((*dataBarang), 2);
		koor(45, 20), printf("Masukan kode barang yang dipilih :");
		kodeBarang = inputPilihan(10);
		kodeBarang -= 1;

		koor(45, 21), printf("Masukan jumlah barang : ");
		scanf("%d", &jumlahBarang);

		checkBarangSama(&transKeranjang, (*dataBarang), kodeBarang, &statusSama);

		if ((*dataBarang)[kodeBarang].stok > 0 && (*dataBarang)[kodeBarang].stok >= jumlahBarang && jumlahBarang != 0)
		{
			if (statusSama)
			{
				transKeranjang->jumlahBarang += jumlahBarang;
				(*newPembeli)->hargaTotal += (*dataBarang)[kodeBarang].harga * jumlahBarang;
			}
			else
			{
				(*newPembeli)->hargaTotal += (*dataBarang)[kodeBarang].harga * jumlahBarang;
				(*dataBarang)[kodeBarang].stok = (*dataBarang)[kodeBarang].stok - jumlahBarang;
				createNodeKeranjang(&(*newPembeli)->Keranjang, (*dataBarang)[kodeBarang].nama, jumlahBarang);
			}
			koor(30, 22), printf("%s berhasil ditambahkan ke dalam keranjang.", (*dataBarang)[kodeBarang].nama);

			system("cls");
			koor(45, 10), printf("Apakah ada yang ingin di tambah lagi ? ");
			koor(45, 11), printf("1. YA");
			koor(45, 12), printf("2. Tidak");
			koor(45, 13), printf("Masukan pilihan : ");
			pilihanLagi = inputPilihan(2);
		}
		else if ((*dataBarang)[kodeBarang].stok < 0)
		{
			koor(30, 22), printf("Maaf persediaan habis. Silahkan beli yang lain!!");
			getch();
		}
		else if ((*dataBarang)[kodeBarang].stok < jumlahBarang)
		{
			koor(25, 22), printf("Maaf persediaan kurang. Silahkan ubah jumlah barang atau beli yang lain!!");
			getch();
		}
		else if (jumlahBarang == 0)
		{
			koor(25, 22), printf("Maaf jumlah barang yang di masukan salah. Silahkan ubah jumlah barang!!");
			getch();
		}
	}
}

/****************** Pembeli *******************/
void initPembeli(address_P nextP, Pembeli *pembeli)
{
	(*pembeli).namaPembeli = nextP->namaPembeli;
	(*pembeli).Keranjang = nextP->Keranjang;
	(*pembeli).hargaTotal = nextP->hargaTotal;
	(*pembeli).noKasir = nextP->noKasir;
}

void alokasiNodePembeli(address_P *tempPembeli)
{
	*tempPembeli = (address_P)malloc(sizeof(Pembeli));
	(*tempPembeli)->Keranjang = Nil;
	(*tempPembeli)->hargaTotal = 0;
	(*tempPembeli)->next = Nil;
}

void createNodePembeli(address_P *headPembeli, address_P *newPembeli, infochar namaPembeli, int noKasir)
{
	/* 	I.S : headPembeli dan newPembeli belum memiliki nilai atau masih kosong, dan address_K q, infochar namaPembeli, int No_Kasir, dan int uangPembeli diisi dengan nilai yang sesuai.
		F.S : terbentuknya sebuah node baru pada linked list pembeli dengan informasi yang sudah diisi dan disambungkan ke linked list.
	*/

	address_P Traversal;

	(*newPembeli)->namaPembeli = namaPembeli;
	(*newPembeli)->noKasir = noKasir;

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

/****************** Keranjang *******************/
void alokasiNodeKeranjang(address_K *tempKeranjang)
{
	*tempKeranjang = (address_K)malloc(sizeof(ListKeranjang));
	(*tempKeranjang)->next = Nil;
}

void createNodeKeranjang(address_K *headKeranjang, infochar namaBarang, int jumlahBarang)
{
	/* I.S : - headAntrian merupakan pointer ke list antrian yang awalnya kosong atau NULL.
			 - newAntrian merupakan pointer yang belum dialokasikan ke memori.
			 - Pembeli merupakan data pembeli yang akan ditambahkan ke dalam node antrian.
	   F.S : newAntrian telah dialokasikan ke memori, memiliki nilai next yang diisi dengan NULL, dan memiliki nilai Pembeli yang diisi dengan Pembeli.
	*/

	address_K transBB;

	address_K newKeranjang;

	alokasiNodeKeranjang(&newKeranjang);

	(newKeranjang)->namaBarang = namaBarang;
	(newKeranjang)->jumlahBarang = jumlahBarang;

	if ((*headKeranjang) == Nil)
	{
		*headKeranjang = newKeranjang;
	}
	else
	{
		transBB = *headKeranjang;
		while (transBB->next != Nil)
		{
			transBB = (transBB)->next;
		}
		transBB->next = newKeranjang;
		transBB->next->next = Nil;
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
		initPembeli(newPembeli, &(tempAntrian)->next->pembeliDiAntrian);
		(tempAntrian)->next->next = Nil;
	}
	else
	{
		alokasiAntrian(&tempAntrian);
		initPembeli(newPembeli, &tempAntrian->pembeliDiAntrian);
		tempAntrian->next = Nil;
		(*kasir).next = tempAntrian;
	}
}

void prosesAntrian(DataKasir (*kasir)[3], DataBarang dataBarang[MAX_BARANG])
{
	int uangPembeli, noKasir;
	bool status = true;

	system("cls");
	tampilListAntrian((*kasir), 2);
	koor(34, 20), printf("Masukan no kasir yang akan melayani pembeli : ");
	noKasir = inputPilihan(3);
	if ((*kasir)[noKasir - 1].next != Nil) // cek apakah ada pembeli dalam antrian kasir
	{
		address_A tempAntrian = (*kasir)[noKasir - 1].next;
		while (status)
		{
			system("cls");
			displayListKeranjang(tempAntrian->pembeliDiAntrian);
			koor(45, 10), printf("Harga Total %s  sebesar %d", tempAntrian->pembeliDiAntrian.namaPembeli, tempAntrian->pembeliDiAntrian.hargaTotal);
			koor(45, 11), printf("Masukan uang pembayaran : ");
			scanf("%d", &uangPembeli);
			if (tempAntrian->pembeliDiAntrian.hargaTotal > uangPembeli)
			{
				koor(45, 13), printf("Uang tidak cukup.");
				koor(45, 14), printf("Tekan apapun untuk masukan ulang!");
				getch();
			}
			else
			{
				status = false;
			}
		}

		tampilanStruk(tempAntrian->pembeliDiAntrian, dataBarang, (*kasir)[noKasir - 1].namaKasir, uangPembeli);
		(*kasir)[noKasir - 1].next = tempAntrian->next; // Antrian kedua maju menjadi antrian pertama
		free(tempAntrian);								// hapus pembeli pertama dalam antrian
		koor(80, 2), printf("Ketik apapun untuk kembali ke menu!!");
		getch();
	}
	else
	{
		koor(45, 21), printf("Belum ada antrian didalam kasir!");
		koor(5, 25), printf("Ketik apapun untuk kembali ke menu!!");
		getch();
	}
}

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
