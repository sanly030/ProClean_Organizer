#ifndef READJENISKENDARAAN_H
#define READJENISKENDARAAN_H

void ReadJenisKendaraan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb");
    if (arskdr == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Header tabel
    BoxBlock(32,17,90,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  K E N D A R A A N");
    gotoprinttext(80,18,"J E N I S  K E N D A R A A N");

    kendaraan kdr;

    // Baca dan tampilkan data jenis kendaraan
    while (fread(&kdr, sizeof(kdr), 1, arskdr) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        // Bersihkan baris sebelum menulis data
        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 122; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        // Tampilkan data
        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("JNK%03d", kdr.id_jeniskendaraan);
        gotoxy(80, y);
        printf("%s", kdr.jenisKendaraan);

        i++;
        y++;
    }

    fclose(arskdr);

    // Konfirmasi untuk kembali ke menu
    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuJenisKendaraan(); // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}

#endif //READJENISKENDARAAN_H