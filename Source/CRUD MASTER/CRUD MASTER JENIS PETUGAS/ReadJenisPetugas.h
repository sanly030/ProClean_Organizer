// //
// // Created by hi on 1/12/2025.
// //
//
// #ifndef READJENISPETUGAS_H
// #define READJENISPETUGAS_H
//
//
// void ReadJenisPetugas() {
//     i = 1;
//     y = 15;
//
//     SetColorBlock(1,7);
//     PrintFile("..//Asset//LihatData.txt",50,11);
//
//     FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
//     if (arsjgs == NULL) {
//         printf("File could not be opened\n");
//     }
//
//     while(fread(&jgs,sizeof(jgs),1,arsjgs) == 1) {
//         if (1 % 2 == 0 ) {
//             SetColorBlock(7,1);
//             for(x = y; x <= y;x++) {
//                 for(j = 37; j < 167; j++) {
//                     gotoprintchar(j,x,32);
//                 }
//             }
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 printf("JPS00%d",jgs.id_jenispetugas);
//                 gotoxy(75, y);
//                 printf("%s",jgs.jabatan);
//                 gotoxy(110, y);
//                 printf("%s",jgs.deskripsijabatan);
//
//             } else {
//                 SetColorBlock(7, 9);
//                 for (x = y; x <= y; x++) {
//                     for (j = 37; j < 167; j++) {
//                         gotoprintchar(j, x, 32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 printf("JPS00%d",jgs.id_jenispetugas);
//                 gotoxy(75, y);
//                 printf("%s",jgs.jabatan);
//                 gotoxy(110, y);
//                 printf("%s",jgs.deskripsijabatan);
//
//                 i++;
//                 y++;
//             }
//         }
//     }
//
//     fclose(arsjgs);
//     getch();
//     blankScreen();
//     MenuJenisPetugas();
// }
// #endif //READJENISPETUGAS_H

// Created by hi on 1/12/2025

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
    getch();
    blankScreen();
    MenuJenisPetugas();
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
