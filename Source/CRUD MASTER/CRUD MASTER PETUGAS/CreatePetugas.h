#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[255];
void inisialisasiJenisPetugas() {
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "wb");
    if (arsjgs == NULL) {
        printf("Error: Tidak dapat membuka file JENIS PETUGAS.dat\n");
        return;
    }

    // Data Admin
    jnspetugas admin = {
        .id_jenispetugas = 1,
        .kode = "ADM"
    };
    strcpy(admin.jabatan, "Admin");
    strcpy(admin.deskripsijabatan, "Mengelola sistem dan database");
    fwrite(&admin, sizeof(jnspetugas), 1, arsjgs);

    // Data Kasir
    jnspetugas kasir = {
        .id_jenispetugas = 2,
        .kode = "KSR"
    };
    strcpy(kasir.jabatan, "Kasir");
    strcpy(kasir.deskripsijabatan, "Mengelola transaksi pembayaran");
    fwrite(&kasir, sizeof(jnspetugas), 1, arsjgs);

    // Data Petugas Kebersihan
    jnspetugas kebersihan = {
        .id_jenispetugas = 3,
        .kode = "PTS"
    };
    strcpy(kebersihan.jabatan, "Petugas Kebersihan");
    strcpy(kebersihan.deskripsijabatan, "Menjaga kebersihan area");
    fwrite(&kebersihan, sizeof(jnspetugas), 1, arsjgs);

    fclose(arsjgs);
    printf("Inisialisasi data jenis petugas berhasil!\n");
}
char* getNextPetugasId(int id_jenispetugas) {
    static char newId[10];
    char kodePrefix[4] = "PTG"; // default prefix
    int lastNumber = 0;

    // Dapatkan kode prefix berdasarkan jenis petugas
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs != NULL) {
        jnspetugas jgs;
        while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
            if (jgs.id_jenispetugas == id_jenispetugas) {
                strcpy(kodePrefix, jgs.kode);
                break;
            }
        }
        fclose(arsjgs);
    }

    // Cari nomor terakhir untuk prefix ini
    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb");
    if (arspgs != NULL) {
        petugas pgs;
        while (fread(&pgs, sizeof(pgs), 1, arspgs)) {
            if (strncmp(pgs.id_petugas_str, kodePrefix, 3) == 0) {
                int currentNum;
                sscanf(pgs.id_petugas_str + 3, "%d", &currentNum);
                if (currentNum > lastNumber) {
                    lastNumber = currentNum;
                }
            }
        }
        fclose(arspgs);
    }

    sprintf(newId, "%s%03d", kodePrefix, lastNumber + 1);
    return newId;
}

void CreatePetugas() {
    char pilihan;
    do {
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        // Menampilkan daftar jenis petugas
        FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
        if (arsjgs == NULL) {
            printf("File JENIS PETUGAS.dat tidak dapat dibuka.\n");
            return;
        }

        jnspetugas jgs;
        int i = 1;
        textBox2(120,17,49,7);
        gotoprinttext(130,18, "Daftar Jenis Petugas:");
        while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
            gotoxy(122, 19 + i);
            printf("[%d] %s - %s", jgs.id_jenispetugas, jgs.jabatan, jgs.deskripsijabatan);
            i++;
        }
        fclose(arsjgs);

        // Input dan validasi ID jenis petugas
        int id_jenispetugas;
        gotoprinttext(45, 13 + i + 1, "Masukkan ID Jenis Petugas yang dipilih : ");
        gotoxy(86, 13 + i + 1);
        // scanf("%d", &id_jenispetugas);
        getnum(&id_jenispetugas,1);

        // Validasi ID
        arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
        int valid = 0;
        while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
            if (jgs.id_jenispetugas == id_jenispetugas) {
                valid = 1;
                break;
            }
        }
        fclose(arsjgs);

        if (!valid) {
            printf("ID Jenis Petugas tidak valid.\n");
            continue;
        }

        // Buka file petugas untuk penambahan data
        FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "ab+");
        if (arspgs == NULL) {
            printf("File PETUGAS.dat tidak dapat dibuka.\n");
            return;
        }

        petugas pgs;
        pgs.role = id_jenispetugas;

        // Generate ID baru dengan format sesuai jenis petugas
        char* newId = getNextPetugasId(id_jenispetugas);
        strcpy(pgs.id_petugas_str, newId);

        // Tampilkan dan input data petugas
        gotoxy(45, 20);
        printf("I D  P E T U G A S                     : %s\n", pgs.id_petugas_str);
        gotoprinttext(45, 22, "N A M A  P E T U G A S                 : ");
        gotoxy(86, 22);
        getinput(pgs.nama, 25, 2);
        gotoprinttext(45, 24, "N O  T E L E P O N                     : ");
        gotoxy(86, 24);
        getinput(pgs.no_telp, 16, 3);
        gotoprinttext(45, 26, "S T A T U S                            : ");
        gotoxy(86, 26);
        getinput(pgs.status, 25, 2);
        gotoprinttext(45, 28, "U S E R N A M E                        : ");
        gotoxy(86, 28);
        getinput(pgs.username, 20, 2);
        gotoprinttext(45, 30, "P A S S W O R D                        : ");
        gotoxy(86, 30);
        getinput(pgs.password, 20, 2);

        // Simpan ke file
        fwrite(&pgs, sizeof(pgs), 1, arspgs);
        fclose(arspgs);

        gotoxy(65, 32);
        printf("Data petugas berhasil ditambahkan.\n");

        textBox2(69, 35, 56, 2);
        gotoxy(70, 36);
        printf("Apakah ingin menambah data petugas lagi? (y/t): ");
        gotoxy(118,36);
        getinput(&pilihan,1,2);

        blankScreen();
    } while (pilihan == 'y' || pilihan == 'Y');

    MenuPetugas();
}