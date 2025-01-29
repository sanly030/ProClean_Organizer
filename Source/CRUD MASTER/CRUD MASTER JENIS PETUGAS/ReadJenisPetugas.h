#ifndef READJENISPETUGAS_H
#define READJENISPETUGAS_H
#include "DeleteJenisPetugas.h"

void TextBoxUpdateJenisPetugas(int id_petugas);
void TextBoxDeleteJenisPetugas(int id_petugas);

void ReadJenisPetugas() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  P E T U G A S");
    gotoprinttext(77,18,"J A B A T A N");
    gotoprinttext(105,18,"D E S K R I P S I");
    jnspetugas jgs;

    while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JPS00%d", jgs.id_jenispetugas);
        gotoxy(79, y);
        printf("%s", jgs.jabatan);
        gotoxy(105, y);
        printf("%s", jgs.deskripsijabatan);


        i++;
        y++;
    }

    fclose(arsjgs);
    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuJenisPetugas();   // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}

void ReadUpdateJenisPetugas() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("..//Asset//UbahData.txt",60,11);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,98,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  P E T U G A S");
    gotoprinttext(70,18,"J A B A T A N");
    gotoprinttext(98,18,"D E S K R I P S I");

    while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 130; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JPS00%d", jgs.id_jenispetugas);
        gotoxy(70, y);
        printf("%s", jgs.jabatan);
        gotoxy(98, y);
        printf("%s", jgs.deskripsijabatan);

        i++;
        y++;
    }

    fclose(arsjgs);
    TextBoxUpdateJenisPetugas(id_petugas);
    getch();
    MenuJenisPetugas();
}

void ReadDeleteJenisPetugas() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("..//Asset//HapusData.txt",60,11);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,98,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  P E T U G A S");
    gotoprinttext(70,18,"J A B A T A N");
    gotoprinttext(98,18,"D E S K R I P S I");

    while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 130; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("JPS00%d", jgs.id_jenispetugas);
        gotoxy(70, y);
        printf("%s", jgs.jabatan);
        gotoxy(98, y);
        printf("%s", jgs.deskripsijabatan);

        i++;
        y++;
    }
    fclose(arsjgs);
    TextBoxDeleteJenisPetugas(id_petugas);
    getch();
    MenuJenisPetugas();
}



#endif // READJENISPETUGAS_H
