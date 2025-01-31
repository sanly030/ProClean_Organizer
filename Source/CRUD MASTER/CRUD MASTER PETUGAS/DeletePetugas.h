#ifndef DELETEPETUGAS_H
#define DELETEPETUGAS_H

void TextBoxDeletePetugasByRole(char id_petugas[]);
// Fungsi Hapus Data
void DeletePetugas() {
    int role; // Variabel untuk menyimpan pilihan role

    blankScreen();
    SetColorBlock(1, 7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    PrintFile("..//Asset//MenuData.txt",70, 19);
    PrintFile("..//Asset//HapusData.txt",60,11);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);

    textBox2(80,24,20,2);
    gotoprinttext(81, 25, "     1-> Admin");
    textBox2(80,27,20,2);
    gotoprinttext(81, 28, "     2-> Kasir");
    textBox2(78,30,24,2);
    gotoprinttext(79, 31, " 3-> Petugas Kebersihan");

    // gotoprinttext(40, 16, "Masukkan pilihan role: ");
    // getnum(&role, 1); // Meminta input angka dari user gotoprinttext(80,38,"Ketik 0 untuk kembali");
    gotoprinttext(80,38,"Ketik 0 untuk kembali");
    gotoxy(80, 36);
    printf("Masukkan pilihan : ");
    getnum(&role, 1);


    // Validasi input
    if (role < 1 || role > 3) {
        blankScreen();        // Bersihkan layar
        MenuPetugas();          // Kembali ke menu utama
        return;
    }
    // Panggil fungsi untuk menampilkan data berdasarkan role
    ReadDeletePetugasByRole(role);
}


void TextBoxDeletePetugasByRole(char id_petugas[]) {
    petugas pgs;
    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb+"); // Dibuka dengan mode "rb+" untuk read & write
    if (arspgs == NULL) {
        MessageBox(NULL, "File PETUGAS.dat tidak dapat dibuka.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    int found = 0;
    while (fread(&pgs, sizeof(pgs), 1, arspgs) == 1) {
        if (strcmp(pgs.id_petugas_str, id_petugas) == 0) {
            found = 1;
            MessageBox(NULL, "ID PETUGAS Ditemukan!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(132, 18, 38, 24);
            // Menampilkan data lama
            clearTengah();
            SetColorBlock(1, 7);
            frameDetailData(36, 17);
            seluruhpetugas();
            gotoxy(65, 22);
            printf("%s", pgs.id_petugas_str);
            gotoxy(65, 24);
            printf("%s", pgs.nama);
            gotoxy(65, 26);
            printf("%02d/%02d/%d", pgs.tgl_lahir.hari, pgs.tgl_lahir.bulan, pgs.tgl_lahir.tahun);
            gotoxy(65, 28);
            printf("%s", pgs.no_telp);
            gotoxy(65, 30);
            printf("%s", pgs.status);
            gotoxy(65, 32);
            printf("%s", pgs.username);
            gotoxy(65, 34);
            printf("%s", pgs.password);

            SetColorBlock(1, 7);
            gotoxy(50, 40);
            printf("Detail Data yang akan dihapus");
            gotoxy(47, 41);
            printf("Klik apa saja untuk melanjutkan...");
            getch();

            // Konfirmasi penghapusan
            int cancel = MessageBox(NULL, "Anda yakin ingin menghapus?", "DELETE DATA",
                                  MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);

            if (cancel != IDOK) {
                // Jika batal, salin semua data ke temp termasuk yang akan dihapus
                rewind(arspgs);
                while (fread(&pgs, sizeof(pgs), 1, arspgs)) {
                    fwrite(&pgs, sizeof(pgs), 1, temp);
                }
                fclose(arspgs);
                fclose(temp);
                remove("../Database/Dat/TEMP_PETUGAS.dat");
                MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                          MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                return;
            }
            // Jika OK, lanjutkan tanpa menulis record ini ke file temp
            continue;
        }
        // Tulis record yang tidak dihapus ke file temp
        fwrite(&pgs, sizeof(pgs), 1, temp);
    }

    // Tutup kedua file
    fclose(arspgs);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP_PETUGAS.dat");
        MessageBox(NULL, "ID Petugas tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    // Hapus file asli dan rename file temp
    remove("../Database/Dat/PETUGAS.dat");
    rename("../Database/Dat/TEMP_PETUGAS.dat", "../Database/Dat/PETUGAS.dat");

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
            ReadDeletePetugasByRole(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPetugas(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}


#endif //DELETEPETUGAS_H
