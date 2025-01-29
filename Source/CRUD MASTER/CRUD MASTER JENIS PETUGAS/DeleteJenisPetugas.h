#ifndef DELETEJENISPETUGAS_H
#define DELETEJENISPETUGAS_H
void ReadDeleteJenisPetugas();

void TextBoxDeleteJenisPetugas(int id_petugas);

void DeleteJenisPetugas() {
    SetColorBlock(1, 7);
    ReadDeleteJenisPetugas();; // Cukup panggil sekali karena pengulangan ditangani di dalam
    MenuJenisPetugas();
}

void TextBoxDeleteJenisPetugas(int id_petugas) {
    int found = 0;
    char ulangi;
    jnspetugas jgs;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Jenis : JPS00");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(159, 30);
    getnum(&id_petugas, 1);

    // Cek jika user ingin membatalkan
    if (id_petugas == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJenisPetugas();
        return;
    }

    // Buka file untuk dibaca
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary
    FILE *temp = fopen("../Database/Dat/TEMP JENIS PETUGAS.dat", "wb");
    if (temp == NULL) {
        fclose(arsjgs);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data yang akan dihapus
    while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
        if (jgs.id_jenispetugas == id_petugas) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID JENIS PETUGAS Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhjenispetugas();
            gotoxy(65, 25);
            printf("JGS00%d", jgs.id_jenispetugas);
            gotoxy(65, 27);
            printf("%s", jgs.jabatan);
            gotoxy(65, 29);
            printf("%s", jgs.deskripsijabatan);

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
                rewind(arsjgs);
                while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
                    fwrite(&jgs, sizeof(jgs), 1, temp);
                }
                fclose(arsjgs);
                fclose(temp);
                remove("../Database/Dat/TEMP JENIS PETUGAS.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                return;
            }
            // Jika OK, lanjutkan tanpa menulis record ini ke file temp
            continue;
        }
        // Tulis record yang tidak dihapus ke file temp
        fwrite(&jgs, sizeof(jgs), 1, temp);
    }

    // Tutup kedua file
    fclose(arsjgs);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP JENIS PETUGAS.dat");
        MessageBox(NULL, "ID Jenis Petugas tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/JENIS PETUGAS.dat");
    rename("../Database/Dat/TEMP JENIS PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");

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
            ReadDeleteJenisPetugas(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuJenisPetugas(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}


#endif //DELETEJENISPETUGAS_H