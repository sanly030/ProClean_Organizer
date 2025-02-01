void UpdatePromo() {
    SetColorBlock(1, 7);
    ReadUpdatePromo();
}

void TextBoxUpdatePromo(int id_promo) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "U P D A T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Promo : PRM  ");
    gotoprinttext(138, 40, "Ketik 0 untuk batal update");
    gotoxy(159, 30);
    getnum(&id_promo, 3);
    if (id_promo == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPromo();
        return;
    }

    FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
    FILE *temp = fopen("TEMP PROMO.dat", "wb");
    int found = 0;

    while (fread(&prm, sizeof(prm), 1, arsprm) == 1) {
        if (prm.id_promo == id_promo) {
            found = 1;
            MessageBox(NULL, "ID PROMO Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhPromo();
            gotoxy(65, 25);
            printf("PRM%03d", prm.id_promo);
            gotoxy(65, 27);
            printf("%s", prm.namaPromo);
            gotoxy(65, 29);
            printf("%0.f %%", prm.potongan);
            gotoxy(65, 31);
            printf("%02d-%02d-%d", prm.mulai.hari, prm.mulai.bulan, prm.mulai.tahun);
            gotoxy(65, 33);
            printf("%02d-%02d-%d", prm.selesai.hari, prm.selesai.bulan, prm.selesai.tahun);

            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 23, "[1] Nama Promo");
            gotoprinttext(134, 25, "[2] Potongan");
            gotoprinttext(134, 27, "[3] Tanggal Mulai");
            gotoprinttext(134, 29, "[4] Tanggal Selesai");
            gotoprinttext(134, 31, "MASUKKAN PILIHAN : ");
            gotoxy(153, 31);
            getnum(&pilihan, 1);

            switch (pilihan) {
                case 1:
                    gotoxy(134, 33);
                    printf("Masukkan Nama Promo : ");
                    gotoprinttext(134,34,"-> ");
                    for (i = 136; i <= 160; i++) gotoprintchar(i, 35, 196);
                    gotoxy(137, 34);
                    getinput(prm.namaPromo, 50, 2);
                    break;
                case 2:
                    gotoxy(134, 33);
                    printf("Masukkan Potongan (%%): ");
                    gotoprinttext(134,34,"-> ");
                    for (i = 136; i <= 160; i++) gotoprintchar(i, 35, 196);
                    gotoxy(137, 34);
                    scanf("%f", &prm.potongan);
                    break;
                case 3:
                    gotoxy(134, 33);
                    printf("Masukkan Tanggal Mulai : ");
                    gotoprinttext(134,34,"-> DD/MM/YYYY");
                    for (i = 136; i <= 160; i++) gotoprintchar(i, 35, 196);
                    gotoxy(137, 34);
                    getnum(&prm.mulai.hari, 2);
                    gotoxy(140, 34);
                    getnum(&prm.mulai.bulan, 2);
                    gotoxy(143, 34);
                    getnum(&prm.mulai.tahun, 4);
                    break;
                case 4:
                    gotoxy(134, 33);
                    printf("Masukkan Tanggal Selesai : ");
                    gotoprinttext(134,34,"-> DD/MM/YYYY");
                    for (i = 136; i <= 160; i++) gotoprintchar(i, 35, 196);
                    gotoxy(137, 34);
                    getnum(&prm.selesai.hari, 2);
                    gotoxy(140, 34);
                    getnum(&prm.selesai.bulan, 2);
                    gotoxy(143, 34);
                    getnum(&prm.selesai.tahun, 4);
                    break;
                default:
                    MessageBox(NULL, "Pilihan tidak valid.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
            MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            fwrite(&prm, sizeof(prm), 1, temp);
        } else {
            fwrite(&prm, sizeof(prm), 1, temp);
        }
    }

    fclose(arsprm);
    fclose(temp);
    remove("../Database/Dat/PROMO.dat");
    rename("TEMP PROMO.dat", "../Database/Dat/PROMO.dat");

    do {
        SetColorBlock(7, 9);
        textBox2(131, 39, 37, 2); // Textbox untuk konfirmasi
        gotoprinttext(134, 40, "Ubah data lagi? (y/t): ");
        gotoxy(157, 40);
        getinput(&ulangi, 1, 2);
        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdatePromo(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPromo(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}