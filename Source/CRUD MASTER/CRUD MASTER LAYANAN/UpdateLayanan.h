//
// Created by hi on 1/30/2025.
//

#ifndef UPDATELAYANAN_H
#define UPDATELAYANAN_H

void UpdateLayanan() {
    SetColorBlock(1,7);
    ReadUpdateLayanan();
}

void TextBoxUpdateLayanan(int id_layanan) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "U P D A T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Layanan : LYN  ");
    gotoprinttext(138,40,"Ketik 0 untuk batal delete");
    gotoxy(159,30);
    getnum(&id_layanan,3);
    if (id_layanan == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        // clearTengah();
        blankScreen();
        MenuLayanan();
        return;
    }

    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    FILE *temp = fopen("TEMP LAYANAN.dat", "wb");
    int found = 0;

    while (fread(&lyn, sizeof(lyn), 1, arslyn) == 1) {
        if (lyn.id_layanan == id_layanan) {
            found = 1;
            MessageBox(NULL, "ID LAYANAN Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhLayanan();
            gotoxy(65, 25);
            printf("LYN%03d", lyn.id_layanan);
            gotoxy(65, 27);
            printf("%s", lyn.jnslayanan);


            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 23, "[1] Jenis Layanan  ");
            gotoprinttext(134, 26, "MASUKKAN PILIHAN : ");
            gotoxy(153, 26);
            getnum(&pilihan, 1);

            switch (pilihan) {
                case 1:
                    // clearArea(131, 21, 38, 21);
                    gotoxy(134, 28);
                    printf("Masukkan Jenis Layanan : ");
                    gotoprinttext(134,29,"-> ");
                    for (i = 137; i <= 160; i++) {
                        gotoprintchar(i,30,196);
                    }
                    gotoxy(137, 29);
                    getinput(lyn.jnslayanan, 25, 2);
                    MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
            }
            fwrite(&lyn, sizeof(lyn), 1, temp);
        } else {
            fwrite(&lyn, sizeof(lyn), 1, temp);
        }
    }

    fclose(arslyn);
    fclose(temp);
    remove("../Database/Dat/LAYANAN.dat");
    rename("TEMP LAYANAN.dat", "../Database/Dat/LAYANAN.dat");

    do {
        SetColorBlock(7, 9);
        textBox2(131, 39, 37, 2); // Textbox untuk konfirmasi
        gotoprinttext(134, 40, "Ubah data lagi? (y/t): ");
        gotoxy(157, 40);
        getinput(&ulangi, 1, 2);
       // Ambil input karakter
        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdateLayanan(); // Panggil ulang fungsi untuk input baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuLayanan(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y/t.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');
}
#endif //UPDATELAYANAN_H
