//
// Created by hi on 1/12/2025.
//

#ifndef UPDATEJENISPETUGAS_H
#define UPDATEJENISPETUGAS_H


void TextBoxUpdateJenisPetugas(id_petugas);
//Fungsi Ubah Data Jenis Petugas
void UpdateJenisPetugas() {
    SetColorBlock(1,7);
    ReadUpdateJenisPetugas();
    // MenuJenisPetugas();
}

    void TextBoxUpdateJenisPetugas(id_petugas) {
        SetColorBlock(7,9);
        textBox2(130,17,39,25);
        gotoprinttext(141,28,"U P D A T E  D A T A");
        gotoprinttext(134,30,"Masukkan ID Jenis : JPS00 ");
        gotoxy(159,30);
        getnum(&id_petugas,3);
        FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
        temp = fopen("TEMP JENIS PETUGAS.dat", "wb");
        found = 0;


        while (fread(&jgs, sizeof(jgs), 1, arsjgs) == 1) {
            if (jgs.id_jenispetugas == id_petugas) {
                found = 1;
                MessageBox(NULL,"ID JENIS PETUGAS Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                clearTengah();
                SetColorBlock(7,9
                    );
                frameDetailData(36,17);
                seluruhjenispetugas();
                gotoxy(65,25);
                printf("JGS00%d",jgs.id_jenispetugas);
                gotoxy(65,27);
                printf("%s", jgs.jabatan);
                gotoxy(65,29);
                printf("%s",jgs.deskripsijabatan);
                clearArea(131,18,38,24);
                SetColorBlock(7,9);
                gotoprinttext(141,20,"U P D A T E  D A T A");
                gotoprinttext(134,24,"[1] Nama Jabatan  ");
                gotoprinttext(134,26,"[2] Deskripsi  ");
                gotoprinttext(134,28,"MASUKKAN PILIHAN : ");
                gotoxy(153,28);
                getnum(&pilihan,1);
                switch (pilihan) {
                    case 1:
                        clearArea(131,21,38,21);
                        gotoxy(133,25);
                        printf("Masukkan Jabatan : ");
                        gotoxy(151,25);
                        getinput(jgs.jabatan,25,2);
                        MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    break;
                    case 2:
                        clearArea(131,21,38,21);
                        gotoxy(133,25);
                        printf("Masukkan Deskripsi : ");
                        gotoxy(151,25);
                        getinput(jgs.deskripsijabatan,225,2);
                        MessageBox(NULL, "Data Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        break;
                }
                fwrite(&jgs,sizeof(jgs),1,temp);
            }else {
                fwrite(&jgs, sizeof(jgs), 1, temp);
            }
        }
        fclose(arsjgs);
        fclose(temp);
        remove("../Database/Dat/JENIS PETUGAS.dat");
        rename("TEMP JENIS PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");
    blankScreen();
    MenuJenisPetugas();
    }

    #endif //UPDATEJENISPETUGAS_H
