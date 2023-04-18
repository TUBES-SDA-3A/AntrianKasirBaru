#include "Header.h"

/****************** Pembeli *******************/
bool isEmptyPembeli(address_P p)
{
	/* 	I.S : tidak ada yang berubah, hanya menerima satu parameter berupa alamat dari node pembeli.
		F.S : fungsi ini mengembalikan nilai boolean, yaitu 1 jika queue pembeli kosong dan 0 jika queue pembeli tidak kosong.
	*/

	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void createNodePembeli(address_P *headPembeli, address_P *newPembeli, address_BB *q, infochar Nama_Pembeli, int No_Kasir, int uangPembeli)
{
	/* 	I.S : headPembeli dan newPembeli belum memiliki nilai atau masih kosong, dan address_BB q, infochar Nama_Pembeli, int No_Kasir, dan int uangPembeli diisi dengan nilai yang sesuai.
		F.S : terbentuknya sebuah node baru pada linked list pembeli dengan informasi yang sudah diisi dan disambungkan ke linked list.
	*/
	*newPembeli = (address_P)malloc(sizeof(Pembeli));

	address_P Traversal;

	if (isEmpty_Pembeli(*newPembeli))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newPembeli)->next = Nil;
		(*newPembeli)->barangBelian = *q;
		(*newPembeli)->namaPembeli = Nama_Pembeli;
		(*newPembeli)->noKasir = No_Kasir;
		(*newPembeli)->hargaTotal = 0;
		(*newPembeli)->uangPembeli = uangPembeli;
	}
	if (isEmptyPembeli(*headPembeli))
	{
		*headPembeli = *newPembeli;
	}
	else
	{
		Traversal = *headPembeli;
		while (!isEmptyPembeli(Traversal->next))
		{
			Traversal = Traversal->next;
		}
		(Traversal)->next = *newPembeli;
	}
}

/****************** Persediaan Barang *****************/
void persediaanBarang(DataBarang dataBarang[MAX_BARANG])
{
	dataBarang[0].nama = "Shampo", dataBarang[0].stok = 50, dataBarang[0].harga = 15000;
	dataBarang[1].nama = "Sabun Cuci Piring", dataBarang[1].stok = 50, dataBarang[1].harga = 10000;
	dataBarang[2].nama = "Sendok & Garpu", dataBarang[2].stok = 50, dataBarang[2].harga = 30000;
	dataBarang[3].nama = "Bubur Bayi", dataBarang[3].stok = 50, dataBarang[3].harga = 15000;
	dataBarang[4].nama = "Susu UHT", dataBarang[4].stok = 50, dataBarang[4].harga = 40000;
}

/****************** Barang Belian *******************/
bool isEmptyBarangBelian(address_BB p)
{
	/* I.S : Alamat node barang belian (p) mungkin kosong (NULL) atau tidak kosong.
	   F.S : mengetahui apakah suatu node barang belian kosong atau tidak dengan melihat nilai boolean yang dikembalikan oleh fungsi ini.
	*/

	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void createNodeBarangBelian(address_BB *headBarangBelian, address_BB *newBarangBelian, infochar nama_barang, int jumlah_barang)
{ // check
	/* I.S : - headAntrian merupakan pointer ke list antrian yang awalnya kosong atau NULL.
			 - newAntrian merupakan pointer yang belum dialokasikan ke memori.
			 - Pembeli merupakan data pembeli yang akan ditambahkan ke dalam node antrian.
	   F.S : newAntrian telah dialokasikan ke memori, emiliki nilai next yang diisi dengan NULL, dan memiliki nilai Pembeli yang diisi dengan Pembeli.
	*/

	address_BB transBB;

	*newBarangBelian = (address_BB)malloc(sizeof(List_BarangBelian));

	if (isEmptyBarangBelian(*newBarangBelian))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newBarangBelian)->next = Nil;
		(*newBarangBelian)->namaBarang = nama_barang;
		(*newBarangBelian)->jumlahBarang = jumlah_barang;
	}

	if (isEmptyBarangBelian(*headBarangBelian))
	{
		*headBarangBelian = *newBarangBelian;
	}
	else
	{
		transBB = *headBarangBelian;
		while (!isEmptyBarangBelian(transBB->next))
		{
			transBB = (transBB)->next;
		}
		transBB = *newBarangBelian;
	}
}

void delAwalBarangBelian(address_BB *barangBelian)
{
	/* I.S : Terdapat sebuah node yang menjadi inputan fungsi Del_Awal_BarangBelian, dan pada awalnya node tersebut menunjuk ke head dari sebuah list.
	   F.S : Node pertama dari list telah dihapus dan nilai nama barang dari node tersebut disimpan pada variabel X.
	*/

	address_BB tempBarangBelian;

	if (isEmpty_BarangBelian(*barangBelian))
	{
		printf("List Kosong");
	}
	else
	{
		tempBarangBelian = *barangBelian;
		*barangBelian = next(*barangBelian);
		tempBarangBelian = NULL;
		free(tempBarangBelian);
	}
}