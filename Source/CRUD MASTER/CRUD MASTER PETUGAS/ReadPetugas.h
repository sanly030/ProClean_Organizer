#ifndef READPETUGAS_H
#define READPETUGAS_H
#include "DeletePetugas.h"

void MenuPetugas();
void TextBoxUpdatePetugasByRole(char id_petugas[]);

void ReadPetugas() {
    int pilihan;

    // Header menu
    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    // Pilihan menu untuk melihat petugas berdasarkan kategori
    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);

    // gotoprinttext(32, 16, "Pilih kategori petugas untuk ditampilkan:");

    textBox2(80,21,20,2);
    gotoprinttext(81, 22, "     1-> Admin");
    textBox2(80,25,20,2);
    gotoprinttext(81, 26, "     2-> Kasir");
    textBox2(78,29,24,2);
    gotoprinttext(79, 30, " 3-> Petugas Kebersihan");


    // Input pilihan pengguna
    gotoprinttext(80,38,"Ketik 0 untuk kembali");
    gotoxy(82, 34);
    printf("Masukkan pilihan: ");
    getnum(&pilihan, 1);


    // Switch untuk menangani pilihan
    switch (pilihan) {
        case 1:
            ReadPetugasByRole(1); // Menampilkan petugas Admin
            break;
        case 2:
            ReadPetugasByRole(2); // Menampilkan petugas Kasir
            break;
        case 3:
            ReadPetugasByRole(3); // Menampilkan petugas lainnya
            break;
        case 0:
            blankScreen();        // Bersihkan layar
            MenuPetugas();          // Kembali ke menu utama
            return;
        default:
            MessageBox(NULL, "Input tidak valid! Silakan coba lagi.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            ReadPetugas(); // Memanggil ulang fungsi untuk input baru
            return;
    }
}

void ReadPetugasByRole(int role) {
    int i = 1;
    int y = 20;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb");
    if (arspgs == NULL) {
        MessageBox(NULL, "File PETUGAS.dat tidak dapat dibuka.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    BoxBlock(32, 17, 111, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  P E T U G A S");
    gotoprinttext(61, 18, "N A M A");
    gotoprinttext(73, 18, "T G L  L A H I R");
    gotoprinttext(94, 18, "N O  T E L P");
    gotoprinttext(111, 18, "S T A T U S");
    gotoprinttext(127, 18, "U S E R N A M E");
    petugas pgs;

    while (fread(&pgs, sizeof(pgs), 1, arspgs) == 1) {
        // Filter berdasarkan role
        if (pgs.role == role) {
            SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

            for (int x = y; x <= y; x++) {
                for (int j = 32; j < 143; j++) {
                    gotoprintchar(j, x, 32);
                }
            }

            gotoxy(33, y);
            printf("%d", i);
            gotoxy(39, y);
            printf("%s", pgs.id_petugas_str);
            gotoxy(61, y);
            printf("%s", pgs.nama);
            gotoxy(76, y);
            printf("%02d/%02d/%d", pgs.tgl_lahir.hari, pgs.tgl_lahir.bulan, pgs.tgl_lahir.tahun);
            gotoxy(94, y);
            printf("%s", pgs.no_telp);
            gotoxy(111, y);
            printf("%s", pgs.status);
            gotoxy(127, y);
            printf("%s", pgs.username);

            i++;
            y++;
        }
    }

    fclose(arspgs);

    if (i == 1) { // Jika tidak ada data yang ditampilkan
        MessageBox(NULL, "Tidak ada data yang ditemukan untuk kategori ini.", "NOT FOUND", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }

    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            ReadPetugas();        // Kembali ke menu kategori
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid! Silakan coba lagi.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}

void ReadUpdatePetugasByRole(int role) {
    int i = 1;
    int y = 20;
    char id_petugas[10]; // Ubah ke char array karena ID mengandung huruf dan angka
    int found = 0;
    int angka_id;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb");
    if (arspgs == NULL) {
        MessageBox(NULL, "File PETUGAS.dat tidak dapat dibuka.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    BoxBlock(32, 17, 98, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  P E T U G A S");
    gotoprinttext(61, 18, "N A M A");
    gotoprinttext(73, 18, "T G L  L A H I R");
    gotoprinttext(94, 18, "N O  T E L P");
    gotoprinttext(111, 18, "S T A T U S");
    // gotoprinttext(127, 18, "U S E R N A M E");

    petugas pgs;

    while (fread(&pgs, sizeof(pgs), 1, arspgs) == 1) {
        if (pgs.role == role) {
            found = 1;

            SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);
            for (int x = y; x <= y; x++) {
                for (int j = 32; j < 130; j++) {
                    gotoprintchar(j, x, 32);
                }
            }

            gotoxy(33, y);
            printf("%d", i);
            gotoxy(39, y);
            printf("%s", pgs.id_petugas_str);
            gotoxy(61, y);
            printf("%s", pgs.nama);
            gotoxy(76, y);
            printf("%02d/%02d/%d", pgs.tgl_lahir.hari, pgs.tgl_lahir.bulan, pgs.tgl_lahir.tahun);
            gotoxy(94, y);
            printf("%s", pgs.no_telp);
            gotoxy(111, y);
            printf("%s", pgs.status);
            // gotoxy(127, y);
            // printf("%s", pgs.username);

            i++;
            y++;
        }
    }

    fclose(arspgs);

    // Jika tidak ada data ditemukan
    if (!found) {
        MessageBox(NULL, "Tidak ada petugas dengan role yang dipilih.", "NOT FOUND", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }


    // Menampilkan format ID berdasarkan role tanpa input ganda
    textBox2(131, 17, 39, 25);
    if (role == 1) {
        gotoprinttext(134, 30, "Masukkan ID Petugas : ADM00");
    } else if (role == 2) {
        gotoprinttext(34, y + 2, "Masukkan ID Petugas : KSR00");
    }else if(role == 3 ){
        gotoprinttext(34, y + 2, "Masukkan ID Petugas : PTS00");
    } else {
        gotoprinttext(34, y + 2, "Masukkan ID Petugas yang ingin diubah : UNK00");
    }

    // **Letakkan kursor setelah teks yang ditampilkan**
    gotoxy(161, 30);
    scanf("%d", &angka_id); // Hanya membaca angka yang diketik

    // **Gabungkan input angka dengan format ID**
    if (role == 1) {
        sprintf(id_petugas, "ADM00%d", angka_id);
    } else if (role == 2) {
        sprintf(id_petugas, "KSR00%d", angka_id);
    }else if (role == 3 ) {
        sprintf(id_petugas, "PTS00%d", angka_id);
    }else {
        sprintf(id_petugas, "UNK00%d", angka_id);
    }

    // **Lanjutkan ke proses update**
    TextBoxUpdatePetugasByRole(id_petugas);
}

void ReadDeletePetugasByRole(int role) {
    int i = 1;
    int y = 20;
    char id_petugas[10]; // Ubah ke char array karena ID mengandung huruf dan angka
    int found = 0;
    int angka_id;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 60, 11);

    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb");
    if (arspgs == NULL) {
        MessageBox(NULL, "File PETUGAS.dat tidak dapat dibuka.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    BoxBlock(32, 17, 98, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  P E T U G A S");
    gotoprinttext(61, 18, "N A M A");
    gotoprinttext(73, 18, "T G L  L A H I R");
    gotoprinttext(94, 18, "N O  T E L P");
    gotoprinttext(111, 18, "S T A T U S");
    // gotoprinttext(127, 18, "U S E R N A M E");

    petugas pgs;

    while (fread(&pgs, sizeof(pgs), 1, arspgs) == 1) {
        if (pgs.role == role) {
            found = 1;

            SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);
            for (int x = y; x <= y; x++) {
                for (int j = 32; j < 130; j++) {
                    gotoprintchar(j, x, 32);
                }
            }

            gotoxy(33, y);
            printf("%d", i);
            gotoxy(39, y);
            printf("%s", pgs.id_petugas_str);
            gotoxy(61, y);
            printf("%s", pgs.nama);
            gotoxy(76, y);
            printf("%02d/%02d/%d", pgs.tgl_lahir.hari, pgs.tgl_lahir.bulan, pgs.tgl_lahir.tahun);
            gotoxy(94, y);
            printf("%s", pgs.no_telp);
            gotoxy(111, y);
            printf("%s", pgs.status);
            // gotoxy(127, y);
            // printf("%s", pgs.username);

            i++;
            y++;
        }
    }

    fclose(arspgs);

    // Jika tidak ada data ditemukan
    if (!found) {
        MessageBox(NULL, "Tidak ada petugas dengan role yang dipilih.", "NOT FOUND", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }


    // Menampilkan format ID berdasarkan role tanpa input ganda
    textBox2(131, 17, 39, 25);
    if (role == 1) {
        gotoprinttext(134, 30, "Masukkan ID Petugas : ADM00");
    } else if (role == 2) {
        gotoprinttext(34, y + 2, "Masukkan ID Petugas : KSR00");
    }else if(role == 3 ){
        gotoprinttext(34, y + 2, "Masukkan ID Petugas : PTS00");
    } else {
        gotoprinttext(34, y + 2, "Masukkan ID Petugas yang ingin diubah : UNK00");
    }

    // **Letakkan kursor setelah teks yang ditampilkan**
    gotoxy(161, 30);
    scanf("%d", &angka_id); // Hanya membaca angka yang diketik

    // **Gabungkan input angka dengan format ID**
    if (role == 1) {
        sprintf(id_petugas, "ADM00%d", angka_id);
    } else if (role == 2) {
        sprintf(id_petugas, "KSR00%d", angka_id);
    }else if(role == 3 ){
        sprintf(id_petugas, "PTS00%d", angka_id);
    } else {
        sprintf(id_petugas, "UNK00%d", angka_id);
    }

    // **Lanjutkan ke proses update**
    TextBoxDeletePetugasByRole(id_petugas);
}


#endif // READPETUGAS_H
