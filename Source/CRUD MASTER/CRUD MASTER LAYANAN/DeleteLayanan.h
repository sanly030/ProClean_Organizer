
#ifndef DELETELAYANAN_H
#define DELETELAYANAN_H

void DeleteLayanan() {
    SetColorBlock(1, 7);
    ReadDeleteLayanan();; // Cukup panggil sekali karena pengulangan ditangani di dalam
    MenuLayanan();
}
void TextBoxDeleteLayanan(int id_layanan) {
    int found = 0;
    char ulangi;
    layanan lyn;

    // Tampilkan input box
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Layanan : LYN");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(159, 30);
    getnum(&id_layanan, 3);

    // Cek jika user ingin membatalkan
    if (id_layanan == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuLayanan();
        return;
    }

    // Buka file untuk dibaca
    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    if (arslyn == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Buka file temporary
    FILE *temp = fopen("../Database/Dat/TEMP LAYANAN.dat", "wb");
    if (temp == NULL) {
        fclose(arslyn);
        MessageBox(NULL, "Tidak dapat membuat file temporary!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Cari data yang akan dihapus
    while (fread(&lyn, sizeof(lyn), 1, arslyn)) {
        if (lyn.id_layanan == id_layanan) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Layanan Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Tampilkan detail data yang akan dihapus
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhJnsLayanan();
            gotoxy(65, 25);
            printf("LYN00%d", lyn.id_layanan);
            gotoxy(65, 27);
            printf("%s", lyn.jnslayanan);


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
                rewind(arslyn);
                while (fread(&lyn, sizeof(lyn), 1, arslyn)) {
                    fwrite(&lyn, sizeof(lyn), 1, temp);
                }
                fclose(arslyn);
                fclose(temp);
                remove("../Database/Dat/TEMP LAYANAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeleteLayanan();;
            }
            // Jika OK, lanjutkan tanpa menulis record ini ke file temp
            continue;
        }
        // Tulis record yang tidak dihapus ke file temp
        fwrite(&lyn, sizeof(lyn), 1, temp);
    }

    // Tutup kedua file
    fclose(arslyn);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP LAYANAN.dat");
        MessageBox(NULL, "ID Layanan tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/LAYANAN.dat");
    rename("../Database/Dat/TEMP LAYANAN.dat", "../Database/Dat/LAYANAN.dat");

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
            ReadDeleteLayanan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuLayanan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}

#endif //DELETELAYANAN_H
