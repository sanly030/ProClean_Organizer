//
// Created by hi on 1/30/2025.
//

#ifndef DELETEJNSLAYANAN_H
#define DELETEJNSLAYANAN_H


void DeleteJnsLayanan() {
    int pilihan;

    do {
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

        textBox2(75,24,28,2);
        gotoprinttext(77, 25, "1-> Delete Jenis Layanan");
        textBox2(72,27,33,2);
        gotoprinttext(74, 28, "2. Delete Detail Jenis Layanan");
        gotoprinttext(78, 38, "==Ketik 0 untuk kembali==");
        gotoprinttext(80, 33, "Masukkan Pilihan : [ ]");
        gotoxy(100, 33);
        getnum(&pilihan, 1);

        switch (pilihan) {
            case 1:
                blankScreen();
            ReadDeleteJenisLayanan();
            break;
            case 2:
                blankScreen();
            ReadDeleteDetailJenisLayanan();
            break;
            case 0:
                blankScreen();
            MenuJnsLayanan();
            return;
            default:
                MessageBox(NULL, "Pilihan tidak valid!", "ERROR!",
                           MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            break;
        }
    } while (pilihan != 0);
}


void TextBoxDeleteJenisLayanan(int id_jnslayanan) {
    int found = 0;
    char ulangi;
    jnslayanan jly;

    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Jenis Layanan: JLY");
    gotoprinttext(138, 40, "Ketik 0 untuk batal delete");
    gotoxy(164, 30);
    getnum(&id_jnslayanan, 3);

    if (id_jnslayanan == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL",
                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuJnsLayanan();
        return;
    }

    FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
    FILE *temp = fopen("../Database/Dat/TEMP JENIS LAYANAN.dat", "wb");

    if (arsjly == NULL || temp == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                   MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }



    while (fread(&jly, sizeof(jly), 1, arsjly)) {
        if (jly.id_jnslayanan == id_jnslayanan) {
            found = 1;

            // Konversi jenis kelamin
            string Status;
            if (jly.status[0] == 'R' || jly.status[0] == 'r') {
                strcpy(Status, "Rumah");
            } else if (jly.status[0] == 'K' || jly.status[0] == 'k') {
                strcpy(Status, "Kendaraan");
            } else {
                strcpy(Status, "Tidak Valid");
            }

            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhJnsLayanan();
            gotoxy(65, 25);
            printf("JPP%03d", jly.id_jnslayanan);
            gotoxy(65, 27);
            printf("%s", jly.jenispaket);
            gotoxy(65, 29);
            printf("Rp %.2f", jly.harga);
            gotoxy(65, 31);
            printf("%d Menit", jly.durasi);
            gotoxy(65,33);
            printf("%s", Status);

            MessageBox(NULL, "ID Jenis Layanan Ditemukan", "NOTIFICATION!",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            SetColorBlock(1, 7);
            gotoxy(50, 35);
            printf("Detail Data yang akan dihapus");
            gotoxy(47, 36);
            printf("Klik apa saja untuk melanjutkan...");
            getch();

            int cancel = MessageBox(NULL, "Anda yakin ingin menghapus?", "DELETE DATA",
                                    MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);

            if (cancel != IDOK) {
                fwrite(&jly, sizeof(jly), 1, temp);
                fclose(arsjly);
                fclose(temp);
                remove("../Database/Dat/TEMP JENIS LAYANAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan.", "CANCEL",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeleteJenisLayanan();
                return;
            }
            continue;
        }
        fwrite(&jly, sizeof(jly), 1, temp);
    }

    fclose(arsjly);
    fclose(temp);

    if (!found) {
        remove("../Database/Dat/TEMP JENIS LAYANAN.dat");
        MessageBox(NULL, "ID tidak ditemukan!", "ERROR!",
                   MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    remove("../Database/Dat/JENIS LAYANAN.dat");
    rename("../Database/Dat/TEMP JENIS LAYANAN.dat", "../Database/Dat/JENISLAYANAN.dat");

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
            ReadDeleteJenisLayanan();
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuJnsLayanan();
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!",
                       MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}


void TextBoxDeleteDetailJenisLayanan(int id_jnslayanan) {
    int found = 0;
    char ulangi;
     tabelDetailJenisPkt djly;

    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "D E L E T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Jenis Layanan: JPP");
    gotoxy(162, 30);
    getnum(&id_jnslayanan, 3);

    FILE *arsdjly = fopen("../Database/Dat/DETAIL JENIS LAYANAN.dat", "rb");
    FILE *temp = fopen("../Database/Dat/TEMP DETAIL JENIS LAYANAN.dat", "wb");

    if (arsdjly == NULL || temp == NULL) {
        MessageBox(NULL, "File tidak dapat dibuka!", "ERROR!",
                   MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    while (fread(&djly, sizeof(djly), 1, arsdjly)) {
        if (djly.id_jnslayanan == id_jnslayanan) {
            found = 1;

            MessageBox(NULL, "Data ditemukan!", "NOTIFICATION!",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            int cancel = MessageBox(NULL, "Yakin ingin menghapus?", "DELETE DATA",
                                    MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);

            if (cancel != IDOK) {
                fwrite(&djly, sizeof(djly), 1, temp);
                fclose(arsdjly);
                fclose(temp);
                remove("../Database/Dat/TEMP DETAIL JENIS LAYANAN.dat");
                MessageBox(NULL, "Penghapusan dibatalkan.", "CANCEL",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                blankScreen();
                ReadDeleteDetailJenisLayanan();
                return;
            }
            continue;
        }
        fwrite(&djly, sizeof(djly), 1, temp);
    }

    fclose(arsdjly);
    fclose(temp);

    remove("../Database/Dat/DETAIL JENIS LAYANAN.dat");
    rename("../Database/Dat/TEMP DETAIL JENIS LAYANAN.dat", "../Database/Dat/DETAIL JENIS LAYANAN.dat");

    MessageBox(NULL, "Data berhasil dihapus!", "SUCCESS!",
               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
}



#endif //DELETEJNSLAYANAN_H
