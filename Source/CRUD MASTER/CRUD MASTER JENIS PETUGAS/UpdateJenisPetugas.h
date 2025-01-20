//
// Created by hi on 1/12/2025.
//

#ifndef UPDATEJENISPETUGAS_H
#define UPDATEJENISPETUGAS_H

void LihatJenisPetugas();       // Fungsi Detail Jenis Petugas
void TextBoxUbah(int id_petugas);

//Fungsi Ubah Data Jenis Petugas
void UpdateJenisPetugas() {
    int id_petugas;
    int found = 0;

    LihatJenisPetugas();
    gotoxy(72,27);
    printf("----------------------------------------------");
    gotoxy(72,28);
    printf("  U B A H  D A T A  J E N I S  P E T U G A S");
    gotoxy(72,29);
    printf("----------------------------------------------");
    gotoprinttext(72,30,"Masukkan ID Petugas yang ingin diubah: JPS00 ");
    gotoxy(116,30);
    scanf("%d", &id_petugas);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP JENIS PETUGAS.dat", "wb");

    clearArea(48,10,123,33);
    while (fread(&jgs, sizeof(jnspetugas), 1, arsjgs)) {
        if (jgs.id_jenispetugas == id_petugas) {
            found = 1;
            TextBoxUbah(id_petugas);


        }
        fwrite(&jgs, sizeof(jnspetugas), 1, temp);
    }

    fclose(arsjgs);
    fclose(temp);

    remove("../Database/Dat/JENIS PETUGAS.dat");
    rename("TEMP JENIS PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");

    // if (found) {
    //     gotoprinttext(65,30,"Data petugas berhasil diubah.\n");
    // } else {
    //     gotoxy(65,30);
    //
    //     printf("Data dengan ID Petugas JGS00%d tidak ditemukan.\n", id_petugas);
    // }
    getch();
    MenuJenisPetugas();
}

void LihatJenisPetugas() {
    A=18; I=55; N=0;
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File could not be opened\n");
    }
    gotoxy(70,12);
    printf("-----------------------------------");
    gotoxy(70 ,13);
    printf("D A T A  J E N I S  P E T U G A S");
    gotoxy(70, 14);
    printf("-----------------------------------\n");
    for(x=I;x < 127;x++) {
        gotoxy(x,16);printf("%c",205);
        gotoxy(x,18);printf("%c",205);
    }
    gotoxy(58, 17);printf("ID Jenis Petugas");
    gotoxy(78, 17);printf("Jabatan");
    gotoxy(98, 17);printf("Deskripsi");

    while(fread(&jgs, sizeof(jnspetugas), 1, arsjgs)) {
        A++, N++;
        if(A%2 == 0) {
            gotoxy(I,A);
        }else {
            gotoxy(I,A);
        }
        for(j=1;j<=80;j++)
        {
            printf(" ");
        }
        gotoxy(58,A);printf("JPS00%d",jgs.id_jenispetugas);
        gotoxy(78,A);printf("%s",jgs.jabatan);
        gotoxy(98,A);printf("%s",jgs.deskripsijabatan);
        fflush(stdin);
    }
    fclose(arsjgs);
}

void TextBoxUbah(int id_petugas) {
    int pil;
    char ulang;

    do {
        FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
        if (arsjgs == NULL) {
            printf("File could not be opened\n");
            return;
        }

        textBox2(68,20,60,10);
        gotoxy(82 ,23);
        printf("D A T A  J E N I S  P E T U G A S");
        gotoxy(82,25);
        printf("ID Jenis Petugas   : JPS%03d", jgs.id_jenispetugas);
        gotoxy(82, 26);
        printf("Jenis Petugas      : %s", jgs.jabatan);
        gotoxy(82, 27);
        printf("Deskripsi          : %s", jgs.deskripsijabatan);

        gotoprinttext(142,22,"Ubah Data");
        gotoprinttext(138,24,"1.Jabatan");
        gotoprinttext(138,25,"2.Deskripsi Jabatan");
        gotoprinttext(138,26,"3.Kembali");
        gotoxy(139,29);
        printf("Pilihan : ");
        scanf("%d", &pil);
        gotoxy(150,29);

        if (pil == 1) {
            clearArea(48,10,123,33);
            textBox2(68,20,50,4);
            gotoxy(75, 21);
            printf("Masukkan Jabatan Baru : ");
            gotoxy(99, 21);
            scanf(" %[^\n]", jgs.jabatan);
            gotoprinttext(78,23,"Jabatan berhasil diperbarui.");
        } else if (pil == 2) {
            clearArea(48,10,123,33);
            textBox2(68,20,50,4);
            gotoxy(75, 21);
            printf("Masukkan Deskripsi Baru : ");
            gotoxy(101, 21);
            scanf(" %[^\n]", jgs.deskripsijabatan);
            gotoprinttext(78,23,"Deskripsi berhasil diperbarui.");
        } else if (pil == 3) {
            fclose(arsjgs);
            return; // Keluar dari fungsi jika memilih kembali
        } else {
            gotoprinttext(78,23,"Pilihan tidak valid. Coba lagi.");
        }

        fflush(stdin);
        fclose(arsjgs);

        // Tanyakan apakah ingin mengubah data lagi
        gotoxy(75, 25);
        printf("Apakah ingin mengubah data lagi? (y/t): ");
        scanf(" %c", &ulang);

        if (ulang == 'y' || ulang == 'Y') {
            clearArea(48,10,123,33); // Bersihkan area tampilan sebelum mengulang
        }

    } while (ulang == 'y' || ulang == 'Y'); // Ulang jika pengguna memilih "y"

    gotoprinttext(78,28,"Kembali ke menu utama.");
}



#endif //UPDATEJENISPETUGAS_H
