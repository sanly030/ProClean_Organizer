//
// Created by hi on 1/30/2025.
//

#ifndef READJNSLAYANAN_H
#define READJNSLAYANAN_H

void ReadJnsLayanan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsjly = fopen("../Database/Dat/JENIS LAYANAN.dat", "rb");
    if (arsjly == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,100,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J N S  L A Y A N A N");
    gotoprinttext(70,18,"N A M A  J N S  L A Y A N A N");
    gotoprinttext(110,18,"D U R A S I");


    jnslayanan jly;

    while (fread(&jly, sizeof(jly), 1, arsjly) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 132; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("JPP%03d", jly.id_jnslayanan);
        gotoxy(70, y);
        printf("%s", jly.namajnslyn);
        gotoxy(110, y);
        printf("%d Menit", jly.durasi);
        // gotoxy(105, y);
        // printf("%s", jgs.deskripsijabatan);


        i++;
        y++;
    }

    fclose(arsjly);
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


#endif //READJNSLAYANAN_H
