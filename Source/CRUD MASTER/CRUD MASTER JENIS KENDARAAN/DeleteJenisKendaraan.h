#ifndef DELETEJENISKENDARAAN_H
#define DELETEJENISKENDARAAN_H

void TextBoxDeleteJenisKendaraan(int id_jeniskendaraan);

void DeleteJenisKendaraan() {
    SetColorBlock(1, 7);
    ReadDeleteJenisKendaraan(); // Menampilkan daftar jenis kendaraan dan meminta input ID
    MenuJenisKendaraan(); // Kembali ke menu utama setelah selesai
}

void ReadDeleteJenisKendaraan() {
    int i = 1;
    int y = 20;
    int id_jeniskendaraan;

    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusData.txt", 50, 11);

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
    gotoprinttext(60,18,"N A M A  K E N D A R A A N");
    gotoprinttext(90,18,"J E N I S  K E N D A R A A N");

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
        gotoxy(80, y);
        printf("%s", kdr.jenisKendaraan);

        i++;
        y++;
    }

    fclose(arskdr);

    // Meminta input ID jenis kendaraan yang akan dihapus
    TextBoxDeleteJenisKendaraan(id_jeniskendaraan);
    getch();
}

void TextBoxDeleteJenisKendaraan(int id_jeniskendaraan) {
    int found = 0;
    char ulangi;
    kendaraan kdr;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(132, 30, "Masukkan ID Jenis Kendaraan : JNK");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(165, 30);
    getnum(&id_jeniskendaraan, 3);

    // Cek jika user ingin membatalkan
    if (id_jeniskendaraan == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJenisKendaraan();
        return;
    }

    // Buka file untuk dibaca
    FILE *arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb");
    if (arskdr == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary
    FILE *temp = fopen("../Database/Dat/TEMP_JENIS_KENDARAAN.dat", "wb");
    if (temp == NULL) {
        fclose(arskdr);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data yang akan dihapus
    while (fread(&kdr, sizeof(kdr), 1, arskdr)) {
        if (kdr.id_jeniskendaraan == id_jeniskendaraan) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Jenis Kendaraan Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhKendaraan();
            gotoxy(65, 23);
            printf("JNK%03d", kdr.id_jeniskendaraan);
            gotoxy(65, 25);
            printf("%s", kdr.jenisKendaraan);

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
                rewind(arskdr);
                while (fread(&kdr, sizeof(kdr), 1, arskdr)) {
                    fwrite(&kdr, sizeof(kdr), 1, temp);
                }
                fclose(arskdr);
                fclose(temp);
                remove("../Database/Dat/TEMP_JENIS_KENDARAAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeleteJenisKendaraan();
            }
            // Jika OK, lanjutkan tanpa menulis record ini ke file temp
            continue;
        }
        // Tulis record yang tidak dihapus ke file temp
        fwrite(&kdr, sizeof(kdr), 1, temp);
    }

    // Tutup kedua file
    fclose(arskdr);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP_JENIS_KENDARAAN.dat");
        MessageBox(NULL, "ID Jenis Kendaraan tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/JENIS_KENDARAAN.dat");
    rename("../Database/Dat/TEMP_JENIS_KENDARAAN.dat", "../Database/Dat/JENIS_KENDARAAN.dat");

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
            ReadDeleteJenisKendaraan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuJenisKendaraan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif //DELETEJENISKENDARAAN_H