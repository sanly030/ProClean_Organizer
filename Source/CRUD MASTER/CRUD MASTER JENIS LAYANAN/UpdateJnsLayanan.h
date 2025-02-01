//
// Created by hi on 1/30/2025.
//

#ifndef UPDATEJNSLAYANAN_H
#define UPDATEJNSLAYANAN_H

#include "ReadJnsLayanan.h"
#include "../../../Interface/lib.h"

void UpdateJnsLayanan() {
    int pilihan;

    while (1) { // Loop agar user tetap di menu sampai memilih opsi yang benar
        blankScreen();
        SetColorBlock(1, 7);
        frameLayout(60,18,120,40,32);
        SetColorBlock(1,7);
        PrintFile("..//Asset//MenuData.txt",70, 19);
        PrintFile("..//Asset//UbahData.txt",60,11);
        frameLayout(60,18,120,19,220);
        frameLayout(60,18,61,40,220);
        frameLayout(60,40,120,41,223);
        frameLayout(119,18,120,40,220);

        textBox2(73,24,30,2);
        gotoprinttext(74, 25, "   1-> Update Jenis Paket");
        textBox2(73,27,30,2);
        gotoprinttext(74, 28, " 2-> Update Detail Jenis Paket");

        gotoprinttext(80, 33, "Masukkan pilihan : [ ]");
        gotoxy(100, 33);
        getnum(&pilihan, 1);

        switch (pilihan) {
            case 1:
                ReadUpdateJenisLayanan(); // Panggil fungsi untuk update Jenis Layanan
            return;
            case 2:
                ReadUpdateDetailJenisPaket(); // Panggil fungsi untuk update Detail Jenis Paket
            return;
            case 0:
                blankScreen();
            MenuJnsLayanan(); // Kembali ke menu utama
            return;
            default:
                MessageBox(NULL, "Pilihan tidak valid. Silakan coba lagi!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}


void TextBoxUpdateJenisLayanan(int id_jnslayanan) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(132, 20, "U P D A T E  J E N I S  L A Y A N A N");
    gotoprinttext(134, 22, "Masukkan ID Jenis Layanan : JLY  ");
    gotoprinttext(136, 40, "== Ketik 0 untuk batal update ==");

    gotoxy(165, 22);
    getnum(&id_jnslayanan, 3);

    if (id_jnslayanan == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJnsLayanan();
        return;
    }

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    FILE *temp = fopen("TEMP_JENISLAYANAN.dat", "wb");

    if (!arsjly || !temp) {
        MessageBox(NULL, "Gagal membuka file!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    int found = 0;
    jnslayanan jly;

    while (fread(&jly, sizeof(jnslayanan), 1, arsjly) == 1) {
        if (jly.id_jnslayanan == id_jnslayanan) {
            found = 1;
            MessageBox(NULL, "ID Jenis Layanan ditemukan.", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Konversi status
            string Status;
            if (jly.status[0] == 'R' || jly.status[0] == 'r') {
                strcpy(Status, "Rumah");
            } else if (jly.status[0] == 'K' || jly.status[0] == 'k') {
                strcpy(Status, "Kendaraan");
            } else {
                strcpy(Status, "Tidak Valid");
            }

            // Menampilkan data lama
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhJnsLayanan();
            gotoxy(65, 25);
            printf("JLY%03d", jly.id_jnslayanan);
            gotoxy(65, 27);
            printf("%s", jly.jenispaket);
            gotoxy(65, 29);
            printf("Rp %.2f", jly.harga);
            gotoxy(65, 31);
            printf("%d", jly.durasi);
            gotoxy(65,33);
            printf("%s", Status);

            // Input update
            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(134, 20, "PILIH DATA YANG INGIN DIUBAH");
            gotoprinttext(134, 23, "[1] Nama Jenis Paket");
            gotoprinttext(134, 25, "[2] Harga ");
            gotoprinttext(134, 27, "[3] Durasi ");

            gotoprinttext(134, 30, "MASUKKAN PILIHAN : [   ] ");
            gotoxy(155, 30);
            int pilihan;
            getnum(&pilihan, 1);

            switch (pilihan) {
                case 1:
                    gotoprinttext(134, 32, "Masukkan Nama Jenis Layanan Baru: ");
                    gotoprinttext(134,33,"-> ");
                    for (i = 137; i <= 160; i++) {
                    gotoprintchar(i,34,196);
                    }
                    gotoxy(138, 33);
                    getinput(jly.jenispaket, 25, 2);
                    MessageBox(NULL, "Nama Jenis Layanan Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                case 2:
                    gotoprinttext(134, 32, "Masukkan Harga Baru (Rp): ");
                    gotoxy(134, 34);
                    getnum(&jly.harga, 6);
                    MessageBox(NULL, "Harga Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                case 3:
                    gotoprinttext(134, 32, "Masukkan Durasi Baru: ");
                    gotoxy(134, 34);
                    getinput(jly.durasi, 10, 2);
                    MessageBox(NULL, "Durasi Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                default:
                    MessageBox(NULL, "Pilihan tidak valid!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
        }

        fwrite(&jly, sizeof(jly), 1, temp);
    }

    fclose(arsjly);
    fclose(temp);

    remove("../Database/Dat/JENISLAYANAN.dat");
    rename("TEMP_JENISLAYANAN.dat", "../Database/Dat/JENISLAYANAN.dat");

    if (!found) {
        MessageBox(NULL, "ID tidak ditemukan!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    }

    blankScreen();
    MenuJnsLayanan();
}

void UpdateDetailJenisPaket() {
    SetColorBlock(1, 7);
    ReadUpdateDetailJenisPaket();
}

void TextBoxUpdateDetailJenisPaket(int id_jnslayanan, int id_layanan) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(132, 28, "U P D A T E  D E T A I L  J N S  P A K E T");
    gotoprinttext(134, 30, "Masukkan ID Jenis Layanan : JLY  ");
    gotoprinttext(134, 32, "Masukkan ID Layanan       : LYN  ");
    gotoprinttext(138, 40, "Ketik 0 untuk batal update");
    gotoxy(165, 30);
    getnum(&id_jnslayanan, 3);
    gotoxy(165, 32);
    getnum(&id_layanan, 3);

    if (id_jnslayanan == 0 || id_layanan == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJnsLayanan();
        return;
    }

    FILE *arsDetail = fopen("../Database/Dat/DETAILJENISPAKET.dat", "rb");
    FILE *temp = fopen("TEMP_DETAILJENISPAKET.dat", "wb");
    int found = 0;

    tabelDetailJenisPkt tdj;

    while (fread(&tdj, sizeof(tabelDetailJenisPkt), 1, arsDetail) == 1) {
        if (tdj.id_jnslayanan == id_jnslayanan && tdj.id_layanan == id_layanan) {
            found = 1;
            MessageBox(NULL, "Data Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhJnsLayanan();
            gotoxy(65, 25);
            printf("JLY%03d", tdj.id_jnslayanan);
            gotoxy(65, 27);
            printf("LYN%03d", tdj.id_layanan);

            gotoprinttext(134, 29, "Masukkan ID Layanan Baru: LYN ");
            gotoxy(164, 29);
            getnum(&tdj.id_layanan, 3);
            MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
        fwrite(&tdj, sizeof(tabelDetailJenisPkt), 1, temp);
    }

    fclose(arsDetail);
    fclose(temp);
    remove("../Database/Dat/DETAILJENISPAKET.dat");
    rename("TEMP_DETAILJENISPAKET.dat", "../Database/Dat/DETAILJENISPAKET.dat");

    if (!found) {
        MessageBox(NULL, "Data tidak ditemukan!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    }

    blankScreen();
    MenuJnsLayanan();
}



#endif // UPDATEJENISLAYANAN_H



