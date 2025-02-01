#ifndef UPDATEPELANGGAN_H
#define UPDATEPELANGGAN_H

void TextBoxUpdatePelanggan(int id_plg);

void UpdatePelanggan() {
    SetColorBlock(1,7);
    ReadUpdatePelanggan();
}

void ReadUpdatePelanggan() {
    int i = 1;
    int y = 20;
    int id_plg;
    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
    if (arsplg == NULL) {
        printf("File could not be opened\n");
        return;
    }

    BoxBlock(32,17,100,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P E L A N G G A N");
    gotoprinttext(65,18,"N A M A  P L G");
    gotoprinttext(84,18,"J N S  K E L A M I N");

    pelanggan plg;

    while (fread(&plg, sizeof(plg), 1, arsplg) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 132; j++) {
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
        gotoxy(65, y);
        printf("%s", plg.namaPlg);
        gotoxy(85, y);
        printf("%s", jenisKelamin);

        i++;
        y++;
    }

    fclose(arsplg);
    TextBoxUpdatePelanggan(id_plg);
    getch();
    MenuPelanggan();
}

void TextBoxUpdatePelanggan(int id_plg) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "U P D A T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Pelanggan : PLG  ");
    gotoprinttext(138,40,"Ketik 0 untuk batal update");
    gotoxy(162,30);
    getnum(&id_plg,3);
    if (id_plg == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPelanggan();
        return;
    }

    FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
    FILE *temp = fopen("TEMP PELANGGAN.dat", "wb");
    int found = 0;

    while (fread(&plg, sizeof(plg), 1, arsplg) == 1) {
        if (plg.id_plg == id_plg) {
            found = 1;
            MessageBox(NULL, "ID PELANGGAN Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhPelanggan();
            gotoxy(65, 23);
            printf("PLG%03d", plg.id_plg);
            gotoxy(65, 25);
            printf("%s", plg.namaPlg);
            gotoxy(65, 27);
            printf("%s", plg.almt);
            gotoxy(65, 29);
            printf("%s", plg.no_telp);
            gotoxy(65, 31);
            printf("%s", (plg.kelamin[0] == 'L' || plg.kelamin[0] == 'l') ? "Laki-laki" : "Perempuan");

            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 23, "[1] Nama Pelanggan  ");
            gotoprinttext(134, 25, "[2] Alamat          ");
            gotoprinttext(134, 27, "[3] No Telepon      ");
            gotoprinttext(134, 29, "[4] Jenis Kelamin   ");
            gotoprinttext(134, 31, "MASUKKAN PILIHAN : ");
            gotoxy(153, 31);
            getnum(&pilihan, 1);

            switch (pilihan) {
                case 1:
                    gotoxy(134, 33);
                    printf("Masukkan Nama Pelanggan : ");
                    gotoprinttext(134,34,"-> ");
                    for (i = 137; i <= 160; i++) {
                        gotoprintchar(i,35,196);
                    }
                    gotoxy(137, 34);
                    getinput(plg.namaPlg, 25, 2);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                case 2:
                    gotoxy(134, 33);
                    printf("Masukkan Alamat : ");
                    gotoprinttext(134,34,"-> ");
                    for (i = 137; i <= 160; i++) {
                        gotoprintchar(i,35,196);
                    }
                    gotoxy(137, 34);
                    getinput(plg.almt, 25, 1);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                case 3:
                    // Validasi No Telepon
                    bool validNoTelp = false;
                    do {
                        gotoxy(134, 33);
                        clearArea(134,33,25,1);
                        printf("Masukkan No Telepon : ");
                        gotoprinttext(134,34,"-> ");
                        for (i = 137; i <= 160; i++) {
                            gotoprintchar(i,35,196);
                        }
                        gotoxy(137, 34);
                        getinput(plg.no_telp, 13, 2);

                        // Cek apakah nomor telepon dimulai dengan "08" dan memiliki panjang minimal 10 karakter
                        if (strlen(plg.no_telp) >= 10 && strncmp(plg.no_telp, "08", 2) == 0) {
                            validNoTelp = true;
                        } else {
                            gotoxy(134, 36);
                            SetColorBlock(4,7);
                            printf("No Telepon harus dimulai dengan '08' dan minimal 10 digit!");
                            SetColorBlock(7,1);
                            Sleep(2000); // Tunda 2 detik
                            gotoxy(134, 36);
                            clearArea(134,36,50,1); // Bersihkan pesan error
                        }
                    } while (!validNoTelp);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                case 4:
                    // Validasi Jenis Kelamin
                    bool validKelamin = false;
                    do {
                        gotoxy(134, 33);
                        clearArea(134,33,25,1);
                        printf("Masukkan Jenis Kelamin (L/P): ");
                        gotoprinttext(134,34,"-> ");
                        for (i = 137; i <= 160; i++) {
                            gotoprintchar(i,35,196);
                        }
                        gotoxy(137, 34);
                        getinput(plg.kelamin, 2, 2);

                        // Cek apakah input adalah 'L' atau 'P' (tidak case-sensitive)
                        if (strcmp(plg.kelamin, "L") == 0 || strcmp(plg.kelamin, "P") == 0 ||
                            strcmp(plg.kelamin, "l") == 0 || strcmp(plg.kelamin, "p") == 0) {
                            validKelamin = true;
                        } else {
                            gotoxy(134, 36);
                            SetColorBlock(4,7);
                            printf("Jenis Kelamin harus 'L' atau 'P'!");
                            SetColorBlock(7,1);
                            Sleep(2000); // Tunda 2 detik
                            gotoxy(134, 36);
                            clearArea(134,36,50,1); // Bersihkan pesan error
                        }
                    } while (!validKelamin);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                default:
                    MessageBox(NULL, "Pilihan tidak valid!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
            fwrite(&plg, sizeof(plg), 1, temp);
        } else {
            fwrite(&plg, sizeof(plg), 1, temp);
        }
    }

    fclose(arsplg);
    fclose(temp);
    remove("../Database/Dat/PELANGGAN.dat");
    rename("TEMP PELANGGAN.dat", "../Database/Dat/PELANGGAN.dat");

    do {
        SetColorBlock(7, 9);
        textBox2(131, 39, 37, 2); // Textbox untuk konfirmasi
        gotoprinttext(134, 40, "Ubah data lagi? (y/t): ");
        gotoxy(157, 40);
        getinput(&ulangi, 1, 2);
       // Ambil input karakter
        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdatePelanggan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPelanggan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}
#endif //UPDATEPELANGGAN_H