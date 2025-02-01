#ifndef READJNSLAYANAN_H
#define READJNSLAYANAN_H
#include "DeleteJnsLayanan.h"

void TextBoxUpdateJenisLayanan(int id_jnslayanan);
void TextBoxDeleteDetailJenisLayanan(int id_jnslayanan);
void TextBoxDeleteJenisLayanan(int id_jnslayanan);


void ReadJnsLayanan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    if (arsjly == NULL) {
        printf("File could not be opened\n");
        return;
    }

    // Header tabel jenis layanan
    BoxBlock(32, 17, 100, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  J N S  L A Y A N A N");
    gotoprinttext(70, 18, "N A M A  J N S  L A Y A N A N");
    gotoprinttext(110, 18, "D U R A S I");


    jnslayanan jly;

    while (fread(&jly, sizeof(jnslayanan), 1, arsjly) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 132; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("JLY%03d", jly.id_jnslayanan);
        gotoxy(70, y);
        printf("%s", jly.jenispaket);
        gotoxy(110, y);
        printf("%d Menit", jly.durasi);

        i++;
        y++;
    }

    fclose(arsjly);

    // Pause agar user bisa melihat tabel jenis layanan sebelum lanjut
    SetColorBlock(1, 7);
    textBox2(32, y + 1, 50, 2);
    gotoprinttext(34, y + 2, "Tekan ENTER untuk melihat detail layanan...");
    getchar(); // Tunggu user menekan ENTER

    // Menampilkan tabel detail jenis paket layanan
    blankScreen();
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsDetail = fopen("../Database/Dat/DETAILJENISPAKET.dat", "rb");
    if (arsDetail == NULL) {
        printf("File DETAILJENISPAKET.dat tidak dapat dibuka.\n");
        return;
    }

    int j = 1;
    int yDetail = 20;

    SetColorBlock(1,7);
    BoxBlock(32, 17, 80, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(40, 18, "I D  J E N I S  L A Y A N A N");
    gotoprinttext(70, 18, "I D  L A Y A N A N");

    tabelDetailJenisPkt tdj;

    while (fread(&tdj, sizeof(tabelDetailJenisPkt), 1, arsDetail) == 1) {
        SetColorBlock((j % 2 == 0) ? 7 : 7, (j % 2 == 0) ? 1 : 9);

        for (int x = yDetail; x <= yDetail; x++) {
            for (int j = 32; j < 112; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, yDetail);
        printf("%d", j);
        gotoxy(45, yDetail);
        printf("JLY%03d", tdj.id_jnslayanan);
        gotoxy(75, yDetail);
        printf("LYN%03d", tdj.id_layanan);

        j++;
        yDetail++;
    }

    fclose(arsDetail);

    // Pause sebelum kembali ke menu utama
    SetColorBlock(1, 7);
    textBox2(32, yDetail + 1, 28, 2);
    gotoprinttext(34, yDetail + 2, "Tekan 0 untuk kembali: ");
    gotoxy(57, yDetail + 2);

    int pilihan;
    while (1) { // Looping untuk meminta input ulang jika salah
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuJnsLayanan();     // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}


void ReadUpdateJenisLayanan() {
    int i = 1;
    int y = 20;
    int id_jnslayanan;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    if (arsjly == NULL) {
        printf("File could not be opened\n");
        return;
    }

    SetColorBlock(1, 7);
    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  J E N I S  L A Y A N A N");
    gotoprinttext(77, 18, "N A M A  J E N I S  L A Y A N A N");

    jnslayanan jly;

    while (fread(&jly, sizeof(jnslayanan), 1, arsjly) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JLY%03d", jly.id_jnslayanan);
        gotoxy(79, y);
        printf("%s", jly.jenispaket);

        i++;
        y++;
    }

    fclose(arsjly);
    TextBoxUpdateJenisLayanan(id_jnslayanan);
    getch();
    MenuJnsLayanan();
}


void ReadUpdateDetailJenisPaket() {
    int i = 1;
    int y = 20;
    int id_jnslayanan, id_layanan;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arsDetail = fopen("../Database/Dat/DETAILJENISPAKET.dat", "rb");
    if (arsDetail == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  J E N I S  L A Y A N A N");
    gotoprinttext(77, 18, "I D  L A Y A N A N");

    tabelDetailJenisPkt tdj;

    while (fread(&tdj, sizeof(tabelDetailJenisPkt), 1, arsDetail) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JLY%03d", tdj.id_jnslayanan);
        gotoxy(79, y);
        printf("LYN%03d", tdj.id_layanan);

        i++;
        y++;
    }

    fclose(arsDetail);
    TextBoxUpdateDetailJenisPaket(id_jnslayanan, id_layanan);
    getch();
    MenuJnsLayanan();
}

void ReadDeleteJenisLayanan() {
    int i = 1;
    int y = 20;
    int id_jnslayanan;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    if (arsjly == NULL) {
        printf("File could not be opened\n");
        return;
    }

    SetColorBlock(1, 7);
    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  J E N I S  L A Y A N A N");
    gotoprinttext(77, 18, "N A M A  J E N I S  L A Y A N A N");

    jnslayanan jly;

    while (fread(&jly, sizeof(jnslayanan), 1, arsjly) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JLY%03d", jly.id_jnslayanan);
        gotoxy(79, y);
        printf("%s", jly.jenispaket);

        i++;
        y++;
    }

    fclose(arsjly);
    TextBoxDeleteJenisLayanan(id_jnslayanan);
    getch();
    MenuJnsLayanan();
}


void ReadDeleteDetailJenisLayanan() {
    int i = 1;
    int y = 20;
    int id_jnslayanan;

    blankScreen();
    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    if (arsjly == NULL) {
        printf("File could not be opened\n");
        return;
    }

    SetColorBlock(1, 7);
    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  J E N I S  L A Y A N A N");
    gotoprinttext(77, 18, "N A M A  J E N I S  L A Y A N A N");

    jnslayanan jly;

    while (fread(&jly, sizeof(jnslayanan), 1, arsjly) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JLY%03d", jly.id_jnslayanan);
        gotoxy(79, y);
        printf("%s", jly.namajnslyn);

        i++;
        y++;
    }

    fclose(arsjly);
    TextBoxDeleteDetailJenisLayanan(id_jnslayanan);
    getch();
    MenuJnsLayanan();
}






#endif // READJNSLAYANAN_H
