cmake_minimum_required(VERSION 3.29)
project(ProClean_Organizer C)

set(CMAKE_C_STANDARD 23)

add_executable(ProClean_Organizer main.c
        Interface/Design.h
        Interface/lib.h
        "Source/CRUD MASTER/CRUD MASTER PETUGAS/CreatePetugas.h"
        "Source/CRUD MASTER/CRUD MASTER PETUGAS/ReadPetugas.h"
        "Source/CRUD MASTER/CRUD MASTER PETUGAS/UpdatePetugas.h"
        "Source/CRUD MASTER/CRUD MASTER PETUGAS/DeletePetugas.h"
        Source/Dashboard.h
        Source/Login.h
        Source/Deklarasi.h
        Source/Tampilan.h
        "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/Create Jenis Petugas.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/ReadJenisPetugas.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/UpdateJenisPetugas.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS PETUGAS/DeleteJenisPetugas.h"
        Source/DashboardMenuAdmin.h
        Source/DashboardOwner.h
        "Source/CRUD MASTER/CRUD MASTER LAYANAN/CreateLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER LAYANAN/ReadLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER LAYANAN/UpdateLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER LAYANAN/DeleteLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER PAKET LAYANAN/CreatePktLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER PAKET LAYANAN/ReadPktLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER PAKET LAYANAN/UpdatePktLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER PAKET LAYANAN/DeletePktLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/CreateJnsLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/ReadJnsLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/UpdateJnsLayanan.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS LAYANAN/DeleteJnsLayanan.h"
)
