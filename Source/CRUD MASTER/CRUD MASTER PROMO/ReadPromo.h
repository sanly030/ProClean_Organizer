#ifndef READPROMO_H
#define READPROMO_H

void TextBoxUpdatePromo(int id_promo);

void ReadPromo() {
    int i = 1;
    int y = 20;
    int pilihan;

    SetColorBlock(1, 7);
    PrintFile("../Asset/LihatData.txt", 50, 11);

    FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
    if (arsprm == NULL) {
        printf("File could not be opened\n");
        return;
    }

    // Header tabel
    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  P R O M O");
    gotoprinttext(57, 18, "N A M A  P R O M O");
    gotoprinttext(80, 18, "P O T O N G A N");
    gotoprinttext(100, 18, "T G L  M U L A I");
    gotoprinttext(121, 18, "T G L S  E L E S A I");

    promo prm;

    while (fread(&prm, sizeof(promo), 1, arsprm) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) { // Menyesuaikan lebar tabel
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(42, y);
        printf("PRM%03d", prm.id_promo);
        gotoxy(60, y);
        printf("%s", prm.namaPromo);
        gotoxy(85, y);
        printf("%.0f %%", prm.potongan);
        gotoxy(102, y);
        printf("%02d-%02d-%d", prm.mulai.hari, prm.mulai.bulan, prm.mulai.tahun);
        gotoxy(125, y);
        printf("%02d-%02d-%d", prm.selesai.hari, prm.selesai.bulan, prm.selesai.tahun);

        i++;
        y++;
    }

    fclose(arsprm);
    SetColorBlock(1, 7);

    while (1) { // Looping untuk meminta input ulang jika salah
        textBox2(32, y + 1, 28, 2);
        gotoprinttext(34, y + 2, "Tekan 0 untuk kembali: ");
        gotoxy(57, y + 2);
        getnum(&pilihan, 1); // Meminta input angka

        if (pilihan == 0) {
            blankScreen();   // Bersihkan layar
            MenuPromo();     // Kembali ke menu promo
            break;           // Keluar dari loop
        } else {
            // Jika input salah, tampilkan pesan kesalahan
            MessageBox(NULL, "Input tidak valid, silakan coba lagi!", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
}


void ReadUpdatePromo() {
    int i = 1;
    int y = 20;
    int id_promo;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
    if (arsprm == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32, 17, 110, 2);
    SetColorBlock(7, 1);
    gotoprinttext(33, 18, "NO.");
    gotoprinttext(38, 18, "I D  P R O M O");
    gotoprinttext(60, 18, "N A M A  P R O M O");
    gotoprinttext(90, 18, "P O T O N G A N");

    promo prm;

    while (fread(&prm, sizeof(prm), 1, arsprm) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 142; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("PRM%03d", prm.id_promo);
        gotoxy(62, y);
        printf("%s", prm.namaPromo);
        gotoxy(92, y);
        printf("%.2f%%", prm.potongan);


        i++;
        y++;
    }

    fclose(arsprm);
    TextBoxUpdatePromo(id_promo);
    getch();
    MenuPromo();
}


void readCreatePromoinTransaksi(){
    FILE *arsprm;
    SetColorBlock(7,1);
    for(i = 17; i <= 19;i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(131,18,"NO.");
    gotoprinttext(134,18,"ID PROMO");
    gotoprinttext(147,18,"NAMA PROMO");
    i = 1;
    y = 20;

    arsprm = fopen("../Database/Dat/PROMO.dat", "rb+");
    if (arsprm == NULL) {
        printf("File could not be opened\n");
        return;
    }
    while (fread(&prm ,sizeof(prm), 1, arsprm) == 1 ) {
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
            generateid("PRM",prm.id_promo);
            gotoxy(147, y);
            printf("%s\n", prm.namaPromo);
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
            generateid("PRM",prm.id_promo);
            gotoxy(147, y);
            printf("%s\n", prm.namaPromo);
        }
        i++;
        y++;
    }
    fclose(arsprm);
}
#endif // READPROMO_H
