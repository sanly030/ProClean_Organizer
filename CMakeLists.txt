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
)
