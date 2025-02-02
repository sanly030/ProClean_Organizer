void ReadPelanggan() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
    if (arsplg == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,120,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P E L A N G G A N");
    gotoprinttext(66,18,"N A M A  P L G");
    gotoprinttext(85,18,"A L A M A T");
    gotoprinttext(102,18,"N O  T E L E P O N");
    gotoprinttext(125,18,"J E N I S  K E L A M I N");

    pelanggan plg;

    while (fread(&plg, sizeof(plg), 1, arsplg) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 152; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        // Konversi jenis kelamin
        string jenisKelamin;
        if (plg.kelamin[0] == 'L' || plg.kelamin[0] == 'l') {
            strcpy(jenisKelamin, "Laki-laki");
        } else if (plg.kelamin[0] == 'P' || plg.kelamin[0] == 'p') {
            strcpy(jenisKelamin, "Perempuan");
        } else {
            strcpy(jenisKelamin, "Tidak Valid");
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("PLG%03d", plg.id_plg);
        gotoxy(67, y);
        printf("%s", plg.namaPlg);
        gotoxy(85, y);
        printf("%s", plg.almt);
        gotoxy(105, y);
        printf("%s", plg.no_telp);
        gotoxy(125, y);
        printf("%s", jenisKelamin);

        i++;
        y++;
    }

    fclose(arsplg);
    SetColorBlock(1, 7);
    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();        // Bersihkan layar
            MenuPelanggan();   // Kembali ke menu utama
            break;                // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid silahkan coba lagi!.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}

void readCreatePelangganinTransaksi(){
    FILE *arsplg;
    SetColorBlock(7,1);
    for(i = 17; i <= 19;i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(131,18,"NO.");
    gotoprinttext(134,18,"ID PELANGGAN");
    gotoprinttext(147,18,"NAMA PELANGGAN");
    i = 1;
    y = 20;

    arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb+");
    if (arsplg == NULL) {
        printf("File could not be opened\n");
        return;
    }
    while (fread(&plg ,sizeof(plg), 1, arsplg) == 1 ) {
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
            generateid("PLG",plg.id_plg);
            gotoxy(147, y);
            printf("%s\n", plg.namaPlg);
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
            generateid("PLG",plg.id_plg);
            gotoxy(147, y);
            printf("%s\n", plg.namaPlg);
        }
        i++;
        y++;
    }
    fclose(arsplg);
}