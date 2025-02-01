#ifndef UPDATEPEMBAYARAN_H
#define UPDATEPEMBAYARAN_H
#include "../../../Interface/lib.h"

void TextBoxUpdatePembayaran(int id_pembayaran);

void UpdatePembayaran() {
    SetColorBlock(1,7);
    ReadUpdatePembayaran();
}

void ReadUpdatePembayaran() {
    int i = 1;
    int y = 20;
    int id_pembayaran;

    SetColorBlock(1, 7);
    PrintFile("../Asset/UbahData.txt", 50, 11);

    FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
    if (arspeb == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Header tabel
    BoxBlock(32,17,100,2);
    SetColorBlock(7, 1);
    gotoprinttext(33,18,"NO.");
    gotoprinttext(38,18,"I D  P E M B A Y A R A N");
    gotoprinttext(67,18,"N A M A  P E M B A Y A R A N");


    pembayaran peb;

    // Baca dan tampilkan data pembayaran
    while (fread(&peb, sizeof(peb), 1, arspeb) == 1) {
        SetColorBlock((i % 2 == 0) ? 7 : 7, (i % 2 == 0) ? 1 : 9);

        // Bersihkan baris sebelum menulis data
        for (int x = y; x <= y; x++) {
            for (int j = 32; j < 130; j++) {
                gotoprintchar(j, x, 32);
            }
        }

        // Tampilkan data
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
    TextBoxUpdatePembayaran(id_pembayaran);
    getch();
    MenuPembayaran();
}

void TextBoxUpdatePembayaran(int id_pembayaran) {
    SetColorBlock(7, 9);
    textBox2(130, 17, 39, 25);
    gotoprinttext(141, 28, "U P D A T E  D A T A");
    gotoprinttext(134, 30, "Masukkan ID Pembayaran : JPR");
    gotoprinttext(138,40,"Ketik 0 untuk batal update");
    gotoxy(162,30);
    getnum(&id_pembayaran,3);
    
    if (id_pembayaran == 0) {
        MessageBox(NULL, "Pengubahan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        blankScreen();
        MenuPembayaran();
        return;
    }

    FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
    FILE *temp = fopen("../Database/Dat/TEMP_PEMBAYARAN.dat", "wb");
    int found = 0;

    while (fread(&peb, sizeof(peb), 1, arspeb) == 1) {
        if (peb.id_pembayaran == id_pembayaran) {
            found = 1;
            MessageBox(NULL, "ID Pembayaran Ditemukan", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            
            // Tampilkan detail data
            clearTengah();
            SetColorBlock(7, 9);
            frameDetailData(36, 17);
            seluruhPembayaran();
            gotoxy(65, 23);
            printf("JPR%03d", peb.id_pembayaran);
            gotoxy(65, 25);
            printf("%s", peb.namaPembayaran);


            // Menu update
            clearArea(131, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 23, "[1] Nama Pembayaran    ");
            gotoprinttext(134, 29, "MASUKKAN PILIHAN : ");
            gotoxy(153, 29);
            getnum(&pilihan, 1);

            switch(pilihan) {
                case 1:
                    gotoxy(134, 31);
                    printf("Masukkan Nama Pembayaran Baru: ");
                    gotoxy(134,32);
                    clearArea(134,32,25,1);
                    for(int i=137; i<=160; i++) gotoprintchar(i,33,196);
                    gotoxy(137,32);
                    getinput(peb.namaPembayaran,25,2);
                    break;
                    
                default:
                    MessageBox(NULL, "Pilihan tidak valid!", "ERROR", MB_OK | MB_ICONERROR);
                    break;
            }
            
            MessageBox(NULL, "Data berhasil diupdate!", "SUCCESS", MB_OK | MB_ICONINFORMATION);
        }
        fwrite(&peb, sizeof(peb), 1, temp);
    }

    fclose(arspeb);
    fclose(temp);
    
    if(!found) {
        remove("../Database/Dat/TEMP_PEMBAYARAN.dat");
        MessageBox(NULL, "ID Pembayaran tidak ditemukan!", "ERROR", MB_OK | MB_ICONERROR);
        return;
    }
    
    // Replace file
    remove("../Database/Dat/PEMBAYARAN.dat");
    rename("../Database/Dat/TEMP_PEMBAYARAN.dat", "../Database/Dat/PEMBAYARAN.dat");

    // Konfirmasi update lagi
    char ulangi;
    do {
        textBox2(131, 39, 37, 2);
        gotoprinttext(134,40, "Update data lagi? (y/t): ");
        gotoxy(157,40);
        getinput(&ulangi,1,2);
        
        if(ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdatePembayaran();
            return;
        } else if(ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPembayaran();
            return;
        } else {
            MessageBox(NULL, "Input tidak valid!", "ERROR", MB_OK | MB_ICONERROR);
        }
    } while(true);
}

#endif // UPDATEPEMBAYARAN_H