#ifndef DELETEJENISPETUGAS_H
#define DELETEJENISPETUGAS_H

void ReadDeleteJenisPetugas();
void TextBoxDeleteJenisPetugas(int id_petugas);

void DeleteJenisPetugas() {
    SetColorBlock(1, 7);
    ReadDeleteJenisPetugas(); // Menampilkan daftar jenis petugas
    MenuJenisPetugas(); // Kembali ke menu utama setelah selesai
}

void ReadDeleteJenisPetugas() {
    int i = 1;
    int y = 20;

    SetColorBlock(1, 7);
    PrintFile("../Asset/HapusDataJenisPetugas.txt", 50, 11);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Header tabel
    BoxBlock(32,17,110,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  J E N I S  P E T U G A S");
    gotoprinttext(60,18,"J A B A T A N");
    gotoprinttext(90,18,"D E S K R I P S I");

    jnspetugas jgs;

    // Baca dan tampilkan data jenis petugas
    while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
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
        printf("JPS%03d", jgs.id_jenispetugas);
        gotoxy(62, y);
        printf("%s", jgs.jabatan);
        gotoxy(90, y);
        printf("%s", jgs.deskripsijabatan);

        i++;
        y++;
    }

    fclose(arsjgs);

    // Meminta input ID jenis petugas yang akan dihapus
    TextBoxDeleteJenisPetugas(id_petugas);
    getch();
}

void TextBoxDeleteJenisPetugas(int id_petugas) {
    int found = 0;
    char ulangi;
    jnspetugas jgs;

    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Jenis Petugas : JPS");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(159, 30);
    getnum(&id_petugas, 3);

    if (id_petugas == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                  MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJenisPetugas();
        return;
    }

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        perror("Error opening file");
        printf("File not found! Creating a new one...\n");
        arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "wb");
        if (arsjgs == NULL) {
            perror("Error creating file");
        }
    }



    FILE *temp = fopen("../Database/Dat/TEMP_JENIS_PETUGAS.dat", "wb");
    if (temp == NULL) {
        fclose(arsjgs);
        perror("Error creating temporary file");
        return;
    }


    while (fread(&jgs, sizeof(jgs), 1, arsjgs)) {
        if (jgs.id_jenispetugas == id_petugas) {
            found = 1;
            clearArea(131, 18, 38, 24);
            MessageBox(NULL, "ID Jenis Petugas Ditemukan", "NOTIFICATION!",
                      MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            gotoxy(65, 25);
            printf("JPS%03d", jgs.id_jenispetugas);
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

            int cancel = MessageBox(NULL, "Anda yakin ingin menghapus?", "DELETE DATA",
                                  MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);

            if (cancel == IDOK) {
                continue; // Skip writing this record
            }
        }
        fwrite(&jgs, sizeof(jgs), 1, temp);
    }

    fclose(arsjgs);
    fclose(temp);

    if (!found) {
        remove("../CRUD MASTER/..Database/Dat/TEMP_JENIS_PETUGAS.dat");
        MessageBox(NULL, "ID Jenis Petugas tidak ditemukan!", "ERROR!",
                  MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    remove("../Database/Dat/JENIS PETUGAS.dat");
    rename("../Database/Dat/TEMP_JENIS_PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");

    MessageBox(NULL, "Data berhasil dihapus!", "SUCCESS!",
              MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        SetColorBlock(7, 9);
        textBox2(131, 28, 37, 2);
        gotoprinttext(134, 29, "Hapus data lagi? (y/t): ");
        gotoxy(157, 29);
        getinput(&ulangi, 1, 2);

        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadDeleteJenisPetugas();
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuJenisPetugas();
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                      MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}


#endif //DELETEJENISPETUGAS_H