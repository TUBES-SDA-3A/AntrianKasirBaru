#include "Header.h"

/****************** Datang Pembeli *******************/
void datangPembeli(address_P *headPembeli, DataBarang *dataBarang[MAX_BARANG])
{
	infochar namaPembeli;
	int uangPembeli;
	address_P newPembeli;

	printf("Masukan nama untuk pembeli : ");
	scanf(" %[^\n]", namaPembeli);

	printf("Masukan uang yang dimiliki pembeli : ");
	scanf("%d", &uangPembeli);

	createNodePembeli(&(*headPembeli), &newPembeli, namaPembeli, uangPembeli);
	beliBarang(&(*dataBarang), &newPembeli->hargaTotal);
}

void beliBarang(DataBarang *dataBarang[MAX_BARANG], int *hargaTotal)
{
	int kodeBarang, jumlahBarang, pilihanLagi = 1;

	while (pilihanLagi == 1)
	{
		printf("Masukan kode barang yang dipilih : ");
		scanf("%d", &kodeBarang);
		kodeBarang -= 1;

		printf("Masukan jumlah barang : ");
		scanf("%d", &jumlahBarang);

		if ((*dataBarang)[kodeBarang].stok > 0 || (*dataBarang)[kodeBarang].stok > jumlahBarang)
		{
			*hargaTotal = (*dataBarang)[kodeBarang - 1].harga * jumlahBarang;
			(*dataBarang)[kodeBarang - 1].stok -= jumlahBarang;
			printf("%s berhasil ditambahkan ke dalam keranjang.", (*dataBarang)[kodeBarang].nama);
		}
		else if ((*dataBarang)[kodeBarang].stok < 0)
		{
			printf("Maaf persediaan habis. Silahkan beli yang lain!!");
		}
		else if ((*dataBarang)[kodeBarang].stok < jumlahBarang)
		{
			printf("Maaf persediaan kurang. Silahkan ubah jumlah barang atau beli yang lain!!");
		}
		printf("Ingin pesan lagi ? ");
		printf("1. YA");
		printf("2. Tidak");
		printf("Masukan pilihan : ");
		scanf("%d", &pilihanLagi);
	}
}

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

void createNodePembeli(address_P *headPembeli, address_P *newPembeli, infochar Nama_Pembeli, int uangPembeli)
{
	/* 	I.S : headPembeli dan newPembeli belum memiliki nilai atau masih kosong, dan address_BB q, infochar Nama_Pembeli, int No_Kasir, dan int uangPembeli diisi dengan nilai yang sesuai.
		F.S : terbentuknya sebuah node baru pada linked list pembeli dengan informasi yang sudah diisi dan disambungkan ke linked list.
	*/
	*newPembeli = (address_P)malloc(sizeof(Pembeli));

	address_P Traversal;

	if (isEmptyPembeli(*newPembeli))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newPembeli)->next = Nil;
		(*newPembeli)->barangBelian = Nil;
		(*newPembeli)->namaPembeli = Nama_Pembeli;
		(*newPembeli)->noKasir = 0;
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

	if (isEmptyBarangBelian(*barangBelian))
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
bool isEmptyAntrian(address_A p)
{
	/* I.S : belum mengetahui apakah address_A kosong atau tidak.
	   F.S : address_A p merupakan alamat dari head dari suatu linked list address_A yang akan dicek apakah kosong atau tidak.
	*/

	if (p == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void createNodeAntrian(address_A *headAntrian, address_A *newAntrian, address_P newPembeli)
{
	/* I.S : - headAntrian: pointer menuju node pertama dari list antrian
			 - newAntrian: pointer untuk menunjuk pada node baru yang akan dibuat
			 - Pembeli: pointer menuju pada node pembeli
	   F.S : Jika newAntrian berhasil dialokasikan, maka newAntrian akan menjadi node baru pada list antrian yang menunjuk ke Pembeli.
			 Jika headAntrian masih kosong, maka headAntrian akan menunjuk ke newAntrian.
			 Jika headAntrian tidak kosong, maka newAntrian akan ditambahkan pada akhir list antrian.
	*/

	address_A transA;

	*newAntrian = (address_A)malloc(sizeof(Antrian)); // membuat node sebesar list antrian

	if (isEmptyAntrian(*newAntrian))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newAntrian) = Nil;				 // next yang ditunjuk p disii Nil
		(*newAntrian)->Pembeli = newPembeli; // nama yang ditunjuk p diisi nama
	}

	if (isEmptyAntrian(*headAntrian))
	{
		*headAntrian = *newAntrian; // pointer diisi pNew
	}
	else
	{
		transA = *headAntrian;
		while (!isEmptyAntrian((transA)->next))
		{							 // memeriksa next A apakah kosong
			transA = (transA)->next; // A diisi next A
		}
		(transA)->next = *newAntrian;
	}
}

void tampilListAntrian(address_A p)
{
	// Menampilkan seluruh isi Linked List, p parameter passing by value
	int i = 1;

	if (isEmptyAntrian(p))
	{
		printf("List Kosong\n");
	}
	else
	{
		while (!isEmptyAntrian(p))
		{
			printf("%d. %s", i, p->Pembeli->namaPembeli); // print yang ada di antrian
			p = (p)->next;								  // p diisi next p
			if (p != Nil)
			{ // jika p tidak sama dengan nil
				printf("\n");
			}
			i++; // lakukan ini sebanyak i
		}
		printf("\n");
	}
}

void delAwalAntrian(address_A *p)
{
	address_A tempAntrian;

	if (isEmptyAntrian(*p))
	{								// memeriksa apakah antrian kosong
		printf("Antrian Kosong\n"); // jika kosong print
	}
	else
	{
		tempAntrian = *p;	// Antrian diisi address p
		*p = (*p)->next;	// pointer diisi next p
		tempAntrian = NULL; // A diisi NIL
		free(tempAntrian);	// hampus A dari antrian
	}
}

void DelPBarangBelian(address_BB *BB, infochar X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address_BB TransBB, Prec;
	bool found = false;
	/* Algoritma */
	Prec = Nil;
	TransBB = *BB;
	while ((TransBB != Nil) && (!found))
	{
		if (strcmp((TransBB)->namaBarang, X) == 0)
		{
			found = true;
		}
		else
		{
			Prec = TransBB;
			TransBB = (TransBB)->next;
		}
	}

	if (found)
	{
		if (Prec == Nil && (TransBB)->next == Nil) /* Hanya 1 elemen */
		{
			TransBB->next = Nil;
		}
		else if (Prec == Nil) /* Ketemu di elemen 1*/
		{
			*BB = (TransBB)->next;
			TransBB->next = Nil;
		}
		else /* Ketemu di elemen list yang ditengah/akhir */
		{
			(Prec)->next = (TransBB)->next;
			TransBB->next = Nil;
		}
		free(TransBB);
	}
}

void DelPAntrian(address_A *headAntrian, infochar namaPembeli)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address_A Prec, transA;
	bool found = false;
	/* Algoritma */
	Prec = Nil;
	transA = (*headAntrian);
	while ((transA != Nil) && (!found))
	{
		if (strcmp((transA)->Pembeli->namaPembeli, namaPembeli) == 0)
		{
			found = true;
		}
		else
		{
			Prec = transA;
			transA = (transA)->next;
		}
	}

	if (found)
	{
		if (Prec == Nil && (transA)->next == Nil) /* Hanya 1 elemen */
		{
			(transA)->next = Nil;
		}
		else if (Prec == Nil) /* Ketemu di elemen 1*/
		{
			(*headAntrian) = (transA)->next;
			(transA)->next = Nil;
		}
		else /* Ketemu di elemen list yang ditengah/akhir */
		{
			(Prec)->next = (transA)->next;
			(transA)->next = Nil;
		}
		free(transA);
	}
	else
	{
		printf("Nama pembeli tidak ditemukan didalam antrian");
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
