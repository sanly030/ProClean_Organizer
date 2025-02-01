#ifndef UPDATEJENISKENDARAAN_H
#define UPDATEJENISKENDARAAN_H

void TextBoxUpdateJenisKendaraan(int id_jeniskendaraaan);

void UpdateJenisKendaraan() {
    SetColorBlock(1,7);
    ReadUpdateJenisKendaraan();
}

void ReadUpdateJenisKendaraan() {
    int i = 1;
    int y = 20;
    int id_jeniskendaraaan;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb");
    if (arskdr == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Header tabel
    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  K E N D A R A A N");
    gotoprinttext(60,18,"J E N I S  K E N D A R A A N");

    kendaraan kdr;

    // Baca dan tampilkan data jenis kendaraan
    while (fread(&kdr, sizeof(kdr), 1, arskdr) == 1) {
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
        printf("JNK%03d", kdr.id_jeniskendaraan);
        gotoxy(62, y);
        printf("%s", kdr.jenisKendaraan);

        i++;
        y++;
    }

    fclose(arskdr);
    TextBoxUpdateJenisKendaraan(id_jeniskendaraaan);
    getch();
    MenuJenisKendaraan();
}

void TextBoxUpdateJenisKendaraan(int id_jeniskendaraan) {


    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "U P D A T E  D A T A");
    gotoprinttext(132, 30, "Masukkan ID Jenis Kendaraan : JNK");
    gotoprinttext(138,40,"Ketik 0 untuk batal update");
    gotoxy(165,30);
    getnum(&id_jeniskendaraan,3);
    if (id_jeniskendaraan == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJenisKendaraan();
        return;
    }

    FILE *arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb");
    FILE *temp = fopen("TEMP JENIS_KENDARAAN.dat", "wb");
    int found = 0;

    while (fread(&kdr, sizeof(kdr), 1, arskdr) == 1) {
        if (kdr.id_jeniskendaraan == id_jeniskendaraan) {
            found = 1;
            MessageBox(NULL, "ID Jenis Kendaraan Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhKendaraan();
            gotoxy(65, 23);
            printf("JNK%03d", kdr.id_jeniskendaraan);
            gotoxy(65, 25);
            printf("%s", kdr.jenisKendaraan);

            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 23, "[1] Jenis Kendaraan  ");
            gotoprinttext(134, 26, "MASUKKAN PILIHAN : ");
            gotoxy(153, 26);
            getnum(&pilihan, 1);

            switch (pilihan) {
                case 1:
                    gotoxy(134, 28);
                    printf("Masukkan Jenis Kendaraan : ");
                    gotoprinttext(134,29,"-> ");
                    for (i = 137; i <= 160; i++) {
                        gotoprintchar(i,30,196);
                    }
                    gotoxy(137, 29);
                    getinput(kdr.jenisKendaraan, 25, 2);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                default:
                    MessageBox(NULL, "Pilihan tidak valid!", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
            fwrite(&kdr, sizeof(kdr), 1, temp);
        } else {
            fwrite(&kdr, sizeof(kdr), 1, temp);
        }
    }

    fclose(arskdr);
    fclose(temp);
    remove("../Database/Dat/JENIS_KENDARAAN.dat");
    rename("TEMP JENIS_KENDARAAN.dat", "../Database/Dat/JENIS_KENDARAAN.dat");

    do {
        SetColorBlock(7, 9);
        textBox2(131, 39, 37, 2); // Textbox untuk konfirmasi
        gotoprinttext(134, 40, "Ubah data lagi? (y/t): ");
        gotoxy(157, 40);
        getinput(&ulangi, 1, 2);

        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdateJenisKendaraan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuJenisKendaraan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif //UPDATEJENISKENDARAAN_H