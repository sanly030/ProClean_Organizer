#ifndef READPEMBAYARAN_H
#define READPEMBAYARAN_H

void ReadPembayaran() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
    if (arspeb == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Header tabel
    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P E M B A Y A R A N");
    gotoprinttext(65,18,"N A M A  P E M B A Y A R A N");


    pembayaran peb;

    // Baca dan tampilkan data pembayaran
    while (fread(&peb, sizeof(peb), 1, arspeb) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        // Bersihkan baris sebelum menulis data
        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        // Tampilkan data
        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("JPR%03d", peb.id_pembayaran);
        gotoxy(75, y);
        printf("%s", peb.namaPembayaran);


        i++;
        y++;
    }

    fclose(arspeb);

    // Konfirmasi untuk kembali ke menu
    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuPembayaran();     // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}

void readCreatePembayaraninTransaksi(){
    FILE *arspeb;
    SetColorBlock(7,1);
    for(i = 17; i <= 19;i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(131,18,"NO.");
    gotoprinttext(134,18,"ID JNS PEMBAYARAN");
    gotoprinttext(147,18,"JENIS PEMBAYARAN");
    i = 1;
    y = 20;

    arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb+");
    if (arsplg == NULL) {
        printf("File could not be opened\n");
        return;
    }
    while (fread(&peb ,sizeof(peb), 1, arspeb) == 1 ) {
        if (i % 2 == 0) {
            SetColorBlock(7,1);
            for(x = y; x <= y;x++){
                for(j = 130; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            gotoxy(131, y);
            printf("%d", i);
            gotoxy(134, y);
            generateid("JPR",peb.id_pembayaran);
            gotoxy(147, y);
            printf("%s\n", peb.namaPembayaran);
        } else {
            SetColorBlock(7,9);
            for(x = y; x <= y;x++){
                for(j = 130; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            gotoxy(131, y);
            printf("%d", i);
            gotoxy(134, y);
            generateid("JPR",peb.id_pembayaran);
            gotoxy(147, y);
            printf("%s\n", peb.namaPembayaran);
        }
        i++;
        y++;
    }
    fclose(arspeb);
}


#endif //READPEMBAYARAN_H