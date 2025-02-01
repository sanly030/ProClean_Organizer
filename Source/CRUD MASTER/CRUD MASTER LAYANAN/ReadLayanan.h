//
// Created by hi on 1/30/2025.
//

#ifndef READLAYANAN_H
#define READLAYANAN_H
#include "UpdateLayanan.h"

void TextBoxUpdateLayanan(int id_layanan);
void TextBoxDeleteLayanan(int id_layanan);

void ReadLayanan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    if (arslyn == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,55,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  L A Y A N A N");
    gotoprinttext(60,18,"J E N I S  L A Y A N A N");

    layanan lyn;

    while (fread(&lyn, sizeof(lyn), 1, arslyn) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 87; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("LYN%03d", lyn.id_layanan);
        gotoxy(62, y);
        printf("%s", lyn.jnslayanan);


        i++;
        y++;
    }

    fclose(arslyn);
    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuLayanan();   // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}


void ReadUpdateLayanan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    if (arslyn == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  L A Y A N A N");
    gotoprinttext(77,18,"J E N I S  L A Y A N A N");

    layanan lyn;

    while (fread(&lyn, sizeof(lyn), 1, arslyn) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("LYN%03d", lyn.id_layanan);
        gotoxy(79, y);
        printf("%s", lyn.jnslayanan);
        // gotoxy(105, y);
        // printf("%s", jgs.deskripsijabatan);

        i++;
        y++;
    }

    fclose(arslyn);
    TextBoxUpdateLayanan(id_layanan);
    getch();
    MenuLayanan();
}

void ReadDeleteLayanan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    if (arslyn == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  L A Y A N A N");
    gotoprinttext(77,18,"J E N I S  L A Y A N A N");

    layanan lyn;

    while (fread(&lyn, sizeof(lyn), 1, arslyn) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(49, y);
        printf("LYN%03d", lyn.id_layanan);
        gotoxy(79, y);
        printf("%s", lyn.jnslayanan);
        // gotoxy(105, y);
        // printf("%s", jgs.deskripsijabatan);

        i++;
        y++;
    }

    fclose(arslyn);
    TextBoxDeleteLayanan(id_layanan);
    getch();
    MenuLayanan();
}


#endif //READLAYANAN_H
