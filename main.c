#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <mmsystem.h>


#include "Source/Deklarasi.h"
#include "Interface/Design.h"
#include "Interface/lib.h"
#include "Source/Tampilan.h"


// #include "Source/MASTER PETUGAS.h"

#include "Source/Login.h"
#include "Source/DashboardMenuAdmin.h"
#include "Source/DashboardKasir.h"
#include "Source/DashboardOwner.h"
#include "Source/Dashboard.h"


#include "Source/CRUD MASTER/CRUD MASTER PETUGAS/CreatePetugas.h"
#include "Source/CRUD MASTER/CRUD MASTER PETUGAS/ReadPetugas.h"
#include "Source/CRUD MASTER/CRUD MASTER PETUGAS/UpdatePetugas.h"
#include "Source/CRUD MASTER/CRUD MASTER PETUGAS/DeletePetugas.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/Create Jenis Petugas.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/ReadJenisPetugas.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/UpdateJenisPetugas.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/DeleteJenisPetugas.h"

#include "Source/CRUD MASTER/CRUD MASTER LAYANAN/CreateLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER LAYANAN/ReadLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER LAYANAN/UpdateLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER LAYANAN/DeleteLayanan.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/CreateJnsLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/ReadJnsLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/UpdateJnsLayanan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/DeleteJnsLayanan.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS KENDARAAN/CreateJenisKendaraan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS KENDARAAN/ReadJenisKendaraan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS KENDARAAN/UpdateJenisKendaraan.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS KENDARAAN/DeleteJenisKendaraan.h"

#include "Source/CRUD MASTER/CRUD MASTER PROMO/CreatePromo.h"
#include "Source/CRUD MASTER/CRUD MASTER PROMO/ReadPromo.h"
#include "Source/CRUD MASTER/CRUD MASTER PROMO/UpdatePromo.h"
#include "Source/CRUD MASTER/CRUD MASTER PROMO/DeletePromo.h"


#include "Source/CRUD MASTER/CRUD MASTER PELANGGAN/CreatePelanggan.h"
#include "Source/CRUD MASTER/CRUD MASTER PELANGGAN/ReadPelanggan.h"
#include "Source/CRUD MASTER/CRUD MASTER PELANGGAN/UpdatePelanggan.h"
#include "Source/CRUD MASTER/CRUD MASTER PELANGGAN/DeletePelanggan.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS PEMBAYARAN/CreatePembayaran.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PEMBAYARAN/ReadPembayaran.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PEMBAYARAN/UpdatePembayaran.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS PEMBAYARAN/DeletePembayaran.h"

#include "Source/TRANSAKSI/TRANSAKSI PEMBERSIHAN RUMAH/CreateTransaksiPembersihanRumah.h"
#include "Source/TRANSAKSI/TRANSAKSI PEMBERSIHAN RUMAH/ReadTransaksiPembersihanRumah.h"
#include "Source/LAPORAN/laporanTransaksiPembersihanRumah.h"

#include "Source/TRANSAKSI/TRANSAKSI PEMBERSIHAN KENDARAAN/CreateTransaksiPembersihanKendaraan.h"

#include "Source/TRANSAKSI/TRANSAKSI PENJADWALAN PETUGAS/CreateTransaksiPenjadwalanPetugas.h"














int main() {
    tampilanawal();

    getch();
}