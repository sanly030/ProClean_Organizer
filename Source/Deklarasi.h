#ifndef DEKLARASI_H
#define DEKLARASI_H



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
int id;
int input;
FILE *fp;
FILE* fp1;
FILE* temp;
int A,I,N;

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


typedef char string[255];
typedef struct {
    int role;
    int id_petugas;
    string nama[25];
    string alamat[25];
    string no_telp[25];
    string status[25];
    string username[20];
    string password[20];
} petugas;
petugas pgs;

typedef struct {
    int id_jenispetugas;
    char jabatan[25];
    char deskripsijabatan[255];
} jnspetugas;
jnspetugas jgs;
