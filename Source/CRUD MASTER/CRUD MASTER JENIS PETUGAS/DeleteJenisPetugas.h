#ifndef DELETEJENISPETUGAS_H
#define DELETEJENISPETUGAS_H


void TextBoxDeleteJenisPetugas(id_petugas);

void DeleteJenisPetugas() {
    char Opsi;
    do {
        SetColorBlock(1,7);
        ReadDeleteJenisPetugas();
        clearArea(131,18,38,24);
        gotoprinttext(133,28,"Apakah ingin menghapusn data lagi(y/t) ? ");
        gotoxy(149,29);printf("[ ]");
        getinput(Opsi,1,2);
    }while (Opsi == 'y' || Opsi == 'Y');
    MenuJenisPetugas();
}

void TextBoxDeleteJenisPetugas(id_petugas) {
    SetColorBlock(7,9);
    textBox2(130,17,39,25);
    gotoprinttext(141,28,"D E L E T E  D A T A");
    gotoprinttext(134,30,"Masukkan ID Jenis : JPS00 ");
    gotoprinttext(138,40,"Ketik 0 untuk membatalkan");
    gotoxy(159,30);
    getnum(&id_petugas,3);
    if (id_petugas == 0) {
        MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        // clearTengah();
        // blankScreen();
        // MenuJenisPetugas();
        return;
    }

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    temp = fopen("TEMP JENIS PETUGAS.dat", "wb");
    found = 0;


        while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
            if (jgs.id_jenispetugas == id_petugas) {
                found = 1;
                clearArea(131,18,38,24);
                // gotoprinttext(138,30,"Ketik 0 untuk membatalkan");
                // gotoxy(149,31);printf("[ ]");
                // gotoxy(150,31);getnum(&batal,1);

                // if (batal == 0) {
                //     fclose(arsjgs);
                //     fclose(temp);
                //     remove("TEMP JENIS PETUGAS.dat");
                //     MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                //     clearTengah();
                //     // blankScreen();
                //     // MenuJenisPetugas();
                //     return;
                // }

                MessageBox(NULL,"ID JENIS PETUGAS Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                clearTengah();
                SetColorBlock(7,9);
                frameDetailData(36,17);
                seluruhjenispetugas();
                gotoxy(65,25);
                printf("JGS00%d",jgs.id_jenispetugas);
                gotoxy(65,27);
                printf("%s", jgs.jabatan);
                gotoxy(65,29);
                printf("%s",jgs.deskripsijabatan);
                SetColorBlock(1,7);
                gotoxy(50,35);printf("Detail Data yang anda hapus");
                gotoxy(47,36);printf("Klik apa saja untuk melanjutkan...");
                getch();

                //Konfiramasi Penghapusan
                cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
                if(cancel == IDOK) {
                    continue;
                }else {
                    fclose(arsjgs);
                    fclose(temp);
                    remove("TEMP JENIS PETUGAS.dat");
                    MessageBox(NULL, "Penghapusan dibatalkan oleh pengguna.", "CANCEL", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    return;
                }
                }
            }
            fwrite(&jgs,sizeof(jgs),1,temp);
        }
        fclose(arsjgs);
        fclose(temp);

//         if(found){
//             remove("../Database/Dat/JENIS PETUGAS.dat");
//             rename("TEMP JENIS PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");
//             MessageBox(NULL,"DATA BERHASIL DI HAPUS!","SUKSES!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//         }else {
//             remove("..TEMP JENIS PETUGAS.dat");
//             MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//             }
//         clearTengah();
//         // DeleteJenisPetugas();
// }
// #endif //DELETEJENISPETUGAS_H
