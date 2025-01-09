#ifndef DEKLARASI_H
#define DEKLARASI_H
#include <stdio.h>
#include <windows.h>


#endif //DEKLARASI_H

#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define TAB 83
int a, i, j, x , y , z;
int input;
FILE *fp;
FILE* fp1;
FILE* temp;

// DEKLARASI MASTER PELANGGAN
// typedef struct {
//     char id[20];
//     char nama[100];
//     char notelp[20];
//     char email[100];
//     char status[10];
// }Pelanggan;Plg , Plgtmp;

//DEKLARASI PAKET LAYANAN
// typedef struct {
//     char id[20];
//     char nama[100];
//     float harga;
//     int kapasitas;
//     int durasi;
//     char status[10];
// }PaketLayanan;
// PaketLayanan PktLyn, PktLyntmp;


typedef struct {
    char nama[25];
    char id_karyawan[20];
    char alamat[40];
    char thnLhr[40];
    char NoTelp[25];
    char jenisKlmn[15];
    char email[30];
    char username[30];
    char password[30];
} Admin ;
Admin adm;