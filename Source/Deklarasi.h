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
int opsi;
char opsiChar[1];
char inputrp[80];
int nilai;
int id_petugas;
int found;
int pilihan;
int cancel;
int batal;
char Opsi;
char ulangi;
int i;
int id_layanan;
int output;
int cekbulan, cektahun;
char namabulan[20];

//Untuk Keuangan
float tunai;
float total;
float kembali;

char Status[5][100]={"Pemesanan Berhasil", "Pemesanan Dibatalkan" , "Pemesanan telah di bayar", "Pemesanan segera dikerjakan!", "Pemesanan selesai!"};

struct id {
    int id_petugasKebersihan;
    int id_admin;
    int id_kasir;
};
typedef struct akun {
    char username[255];
};
struct date {
    int tahun;
    int bulan;
    int hari;
};
float jan,feb,mar,apr,mei,jun,jul,aug,sep,okt,nov,des;



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

    typedef struct {
        int hari;
        int bulan;
        int tahun;
    } tanggal;

    typedef char string[255];
    typedef struct {
        int role;
        int id_petugas;
        string nama;
        string no_telp;
        string status;
        string username;
        string password;
        char id_petugas_str[10];
        tanggal tgl_lahir;
    } petugas;
    petugas pgs;

    typedef struct {
        int id_jenispetugas;
        char jabatan[25];
        char deskripsijabatan[255];
        char kode[4];
    } jnspetugas;
    jnspetugas jgs;

    typedef struct {
        int id_layanan;
        string jnslayanan;
    }layanan;
    layanan lyn;

    typedef struct {
        int id_jnslayanan;
        string namajnslyn;
        string jenispaket;
        float harga;
        int durasi;
        string status;
        int layanan_terpilih[3];
    }jnslayanan;
    jnslayanan jly;
FILE * arsjly;

    typedef struct {
        int id_jnslayanan;
        int id_layanan;
    }tabelDetailJenisPkt;
    tabelDetailJenisPkt tdj;

    // typedef struct {
    //     int id_pktLayanan;
    //     int id_jnslayanan;
    //     string namaPkt;
    // }PktLayanan;
    // PktLayanan pkt;

    typedef struct {
        int id_promo;
        string namaPromo;
        float potongan;
        tanggal mulai;
        tanggal selesai;

    }promo;
    promo prm;
FILE *arsprm;

    typedef struct {
        int id_plg;
        string namaPlg;
        string almt;
        string kelamin;
        string no_telp;
    }pelanggan;
    pelanggan plg;
FILE *arsplg;

    typedef struct {
        int id_pembayaran;
        string namaPembayaran;
    }pembayaran;
    pembayaran peb;
    FILE *arspeb;

    typedef struct {
        int id_jeniskendaraan;
        string jenisKendaraan;
    }kendaraan;
    FILE * arskdr;
    kendaraan kdr;

    typedef struct TRumah{
        int id_TRumah;
        int id_plg;
        char namaPlg[20];
        char jenispaket[20];
        int id_pembayaran;
        int id_jnslayanan;
        int id_promo;
        float totalHarga;
        string namaPromo;
        tanggal pemesanan;
        int durasi;
        string almt;
        string namaPembayaran;
        char Status[100];
    };
    struct TRumah trsTRumah;
struct TRumah temptrsTRumah;
    FILE *fileTransaksiRumah;

    typedef struct DTRumah {
        int id_TRumah;
        int id_plg;
        int id_pembayaran;
        int id_jnslayanan;
        string namaPembayaran;
        string namaPromo;
        float potongan;
        string namaTRumah;
        tanggal pemesanan;
        int durasi;
        float totalHarga;
        string almt;
    };
    struct DTRumah dTRumah;
    FILE *fileDTRumah;

    typedef struct TKendaraan{
        int id_TKendaraan;
        int id_plg;
        char namaPlg[20];
        char jenispaket[20];
        int id_pembayaran;
        int id_jnslayanan;
        int id_jeniskendaraan;
        int id_promo;
        float totalHarga;
        string namaPromo;
        tanggal pemesanan;
        int durasi;
        string jenisKendaraan;
        string almt;
        string namaPembayaran;
        char Status[100];
    };
    struct TKendaraan trsTKendaraan;
struct TKendaraan temptrsTKendaraan;
    FILE *fileTransaksiKendaraan;


    typedef struct DTKendaraan {
        int id_TKendaraan;
        int id_plg;
        int id_pembayaran;
        int id_jnslayanan;
        int id_jeniskendaraan;
        string namaPembayaran;
        string namaPromo;
        string namaTRumah;
        string namaTKendaraan;
        string jenisKendaraan;
        char namaPlg[20];
        tanggal pemesanan;
        int durasi;
        float totalHarga;
        string almt;
    };
    struct DTKendaraan dTKendaraan;
    FILE *fileDTKendaraan;


void convertBulan(int bulan){
    if(bulan == 1){
        strcpy(namabulan,"JANUARI");
    } else if(bulan == 2){
        strcpy(namabulan,"FEBRUARI");
    }else if(bulan == 3){
        strcpy(namabulan,"MARET");
    }else if(bulan == 4){
        strcpy(namabulan,"APRIL");
    }else if(bulan == 5){
        strcpy(namabulan,"MEI");
    }else if(bulan == 6){
        strcpy(namabulan,"JUNI");
    }else if(bulan == 7){
        strcpy(namabulan,"JULI");
    }else if(bulan == 8){
        strcpy(namabulan,"AGUSTUS");
    }else if(bulan == 9){
        strcpy(namabulan,"SEPTEMBER");
    }else if(bulan == 10){
        strcpy(namabulan,"OKTOBER");
    }else if(bulan == 11){
        strcpy(namabulan,"NOVEMBER");
    }else if(bulan == 12){
        strcpy(namabulan,"DESEMBER");
    }
}

typedef struct TPenjadwalan{
    int id_Penjadwalan;
    int id_TRumah;
    string namaTRumah;
    int id_TKendaraan;
    string namaTKendaraan;
    int id_petugas_str;
    string nama;
    tanggal pemesanan;
    tanggal penjadwalan;
    int durasi;
    char Status[100];
};
struct TPenjadwalan trsTPenjadwalan;
struct TPenjadwalan temptrsTPenjadwalan;
FILE *fileTransaksiPenjadwalan;

typedef struct DTPenjadwalan {
    int id_Penjadwalan;
    string nama;
    string alamat;
};
struct DTPenjadwalan dTPenjadwalan;
FILE *fileDTPenjadwalan;