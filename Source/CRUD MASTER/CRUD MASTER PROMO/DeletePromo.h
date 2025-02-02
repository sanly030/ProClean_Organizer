#ifndef DELETEPROMO_H
#define DELETEPROMO_H

void TextBoxDeletePromo(int id_promo);

void DeletePromo() {
    SetColorBlock(1, 7);
    ReadDeletePromo();
    MenuPromo();
}

void ReadDeletePromo() {
    int i = 1;
    int y = 20;
    int id_promo;

    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

    FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
    if (arsprm == NULL) {
        printf("File PROMO.dat tidak dapat dibuka.\n");
        return;
    }

    BoxBlock(32,17,100,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P R O M O");
    gotoprinttext(67,18,"N A M A  P R O M O");

    promo prm;

    while (fread(&prm, sizeof(prm), 1, arsprm) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 132; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("PRM%03d", prm.id_promo);
        gotoxy(62, y);
        printf("%s", prm.namaPromo);

        i++;
        y++;
    }

    fclose(arsprm);
    TextBoxDeletePromo(id_promo);
    getch();
    MenuPromo();
}

void TextBoxDeletePromo(int id_promo) {
    int found = 0;
    char ulangi;
    promo prm;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Promo : PRM");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(162, 30);
    getnum(&id_promo, 3);

    // Cek jika user ingin membatalkan
    if (id_promo == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPromo();
        return;
    }

    // Buka file promo untuk membaca data
    FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
    if (arsprm == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary untuk menyimpan data selain yang dihapus
    FILE *temp = fopen("../Database/Dat/TEMP_PROMO.dat", "wb");
    if (temp == NULL) {
        fclose(arsprm);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data promo yang akan dihapus
    while (fread(&prm, sizeof(prm), 1, arsprm)) {
        if (prm.id_promo == id_promo) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Promo Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhPromo();
            gotoxy(65, 23);
            printf("PRM%03d", prm.id_promo);
            gotoxy(65, 25);
            printf("%s", prm.namaPromo);
            gotoxy(65, 27);
            printf("%.0f %%", prm.potongan);
            gotoxy(65, 29);
            printf("%02d-%02d-%d", prm.mulai.hari, prm.mulai.bulan, prm.mulai.tahun);
            gotoxy(65, 31);
            printf("%02d-%02d-%d", prm.selesai.hari, prm.selesai.bulan, prm.selesai.tahun);

            SetColorBlock(1, 7);
            gotoxy(50, 35);
            printf("Detail Data yang akan dihapus");
            gotoxy(47, 36);
            printf("Klik apa saja untuk melanjutkan...");
            getch();

            // Konfirmasi penghapusan
            int cancel = MessageBox(NULL, "Anda yakin ingin menghapus?", "DELETE DATA",
                                  MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);

            if (cancel != IDOK) {
                rewind(arsprm);
                while (fread(&prm, sizeof(prm), 1, arsprm)) {
                    fwrite(&prm, sizeof(prm), 1, temp);
                }
                fclose(arsprm);
                fclose(temp);
                remove("../Database/Dat/TEMP_PROMO.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeletePromo();
            }
            continue;
        }
        fwrite(&prm, sizeof(prm), 1, temp);
    }

    // Tutup kedua file
    fclose(arsprm);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP_PROMO.dat");
        MessageBox(NULL, "ID Promo tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/PROMO.dat");
    rename("../Database/Dat/TEMP_PROMO.dat", "../Database/Dat/PROMO.dat");

    MessageBox(NULL, "Data berhasil dihapus!", "SUCCESS!",
              MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        SetColorBlock(7, 9);
        textBox2(131, 28, 37, 2); // Textbox untuk konfirmasi
        gotoprinttext(134, 29, "Hapus data lagi? (y/t): ");
        gotoxy(157, 29);
        getinput(&ulangi, 1, 2);

        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadDeletePromo();
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPromo();
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif // DELETEPROMO_H
