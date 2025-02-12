#ifndef DELETEPEMBAYARAN_H
#define DELETEPEMBAYARAN_H

void TextBoxDeletePembayaran(int id_pembayaran);

void DeletePembayaran() {
    SetColorBlock(1, 7);
    ReadDeletePembayaran();
    MenuPembayaran();
}

void ReadDeletePembayaran() {
    int i = 1;
    int y = 20;
    int id_pembayaran;

    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

    FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
    if (arspeb == NULL) {
        printf("File PEMBAYARAN.dat tidak dapat dibuka.\n");
        return;
    }

    BoxBlock(32,17,100,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P E M B A Y A R A N");
    gotoprinttext(67,18,"N A M A  P E M B A Y A R A N");

    pembayaran peb;

    while (fread(&peb, sizeof(peb), 1, arspeb) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 132; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        gotoxy(33, y);
        printf("%d", i);
        gotoxy(44, y);
        printf("JPR%03d", peb.id_pembayaran);
        gotoxy(62, y);
        printf("%s", peb.namaPembayaran);

        i++;
        y++;
    }

    fclose(arspeb);
    TextBoxDeletePembayaran(id_pembayaran);
    getch();
    MenuPembayaran();
}

void TextBoxDeletePembayaran(int id_pembayaran) {
    int found = 0;
    char ulangi;
    pembayaran peb;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Pembayaran : JPR");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(162, 30);
    getnum(&id_pembayaran, 3);

    // Cek jika user ingin membatalkan
    if (id_pembayaran == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPembayaran();
        return;
    }

    // Buka file pembayaran untuk membaca data
    FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
    if (arspeb == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary untuk menyimpan data selain yang dihapus
    FILE *temp = fopen("../Database/Dat/TEMP_PEMBAYARAN.dat", "wb");
    if (temp == NULL) {
        fclose(arspeb);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data pembayaran yang akan dihapus
    while (fread(&peb, sizeof(peb), 1, arspeb)) {
        if (peb.id_pembayaran == id_pembayaran) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Pembayaran Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhPembayaran();
            gotoxy(65, 23);
            printf("JPR%03d", peb.id_pembayaran);
            gotoxy(65, 25);
            printf("%s", peb.namaPembayaran);

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
                rewind(arspeb);
                while (fread(&peb, sizeof(peb), 1, arspeb)) {
                    fwrite(&peb, sizeof(peb), 1, temp);
                }
                fclose(arspeb);
                fclose(temp);
                remove("../Database/Dat/TEMP_PEMBAYARAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeletePembayaran();
            }
            continue;
        }
        fwrite(&peb, sizeof(peb), 1, temp);
    }

    // Tutup kedua file
    fclose(arspeb);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP_PEMBAYARAN.dat");
        MessageBox(NULL, "ID Pembayaran tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/PEMBAYARAN.dat");
    rename("../Database/Dat/TEMP_PEMBAYARAN.dat", "../Database/Dat/PEMBAYARAN.dat");

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
            ReadDeletePembayaran();
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPembayaran();
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif // DELETEPEMBAYARAN_H
