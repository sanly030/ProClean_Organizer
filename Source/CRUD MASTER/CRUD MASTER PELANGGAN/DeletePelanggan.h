#ifndef DELETEPELANGGAN_H
#define DELETEPELANGGAN_H

void TextBoxDeletePelanggan(int id_plg);

void DeletePelanggan() {
    SetColorBlock(1, 7);
    ReadDeletePelanggan(); // Cukup panggil sekali karena pengulangan ditangani di dalam
    MenuPelanggan();
}

void ReadDeletePelanggan() {
    int i = 1;
    int y = 20;
    int id_plg;

    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

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
    gotoprinttext(84,18,"J E N I S  K E L A M I N");

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
    TextBoxDeletePelanggan(id_plg);
    getch();
    MenuPelanggan();
}

void TextBoxDeletePelanggan(int id_plg) {
    int found = 0;
    char ulangi;
    pelanggan plg;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Pelanggan : PLG");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(162, 30);
    getnum(&id_plg, 3);

    // Cek jika user ingin membatalkan
    if (id_plg == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPelanggan();
        return;
    }

    // Buka file untuk dibaca
    FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
    if (arsplg == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary
    FILE *temp = fopen("../Database/Dat/TEMP PELANGGAN.dat", "wb");
    if (temp == NULL) {
        fclose(arsplg);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data yang akan dihapus
    while (fread(&plg, sizeof(plg), 1, arsplg)) {
        if (plg.id_plg == id_plg) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Pelanggan Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
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
                // Jika batal, salin semua data ke temp termasuk yang akan dihapus
                rewind(arsplg);
                while (fread(&plg, sizeof(plg), 1, arsplg)) {
                    fwrite(&plg, sizeof(plg), 1, temp);
                }
                fclose(arsplg);
                fclose(temp);
                remove("../Database/Dat/TEMP PELANGGAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeletePelanggan();
            }
            // Jika OK, lanjutkan tanpa menulis record ini ke file temp
            continue;
        }
        // Tulis record yang tidak dihapus ke file temp
        fwrite(&plg, sizeof(plg), 1, temp);
    }

    // Tutup kedua file
    fclose(arsplg);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP PELANGGAN.dat");
        MessageBox(NULL, "ID Pelanggan tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/PELANGGAN.dat");
    rename("../Database/Dat/TEMP PELANGGAN.dat", "../Database/Dat/PELANGGAN.dat");

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
            ReadDeletePelanggan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPelanggan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif //DELETEPELANGGAN_H