#ifndef CREATE_JENIS_PETUGAS_H

#define CREATE_JENIS_PETUGAS_H

void CreateJenisPetugas() {
    char pilihan;
    do {
        SetColorBlock(1,7);
        textBox2(31,10,139,33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        int lastpetugas = 0;
        i = 0;

        lastpetugas = 0;
        FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb"); // Buka file untuk membaca dan menulis

        while(fread(&jgs,sizeof(jgs),1,arsjgs)) {
            if(jgs.id_jenispetugas >= lastpetugas) {
                lastpetugas = jgs.id_jenispetugas;
            }
        }
        lastpetugas++;
        fclose(arsjgs);

        arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "ab+"); // Buka file untuk membaca dan menulis
        jgs.id_jenispetugas = lastpetugas;

        // Buat ID Jenis Petugas secara otomatis

        gotoxy(65, 20);
        printf("I D  J E N I S  P E T U G A S              : JPS%03d\n", jgs.id_jenispetugas); // Tampilkan ID petugas
        gotoprinttext(65,22,"N A M A  J E N I S  P E T U G A S          : ");
        gotoxy(110,22);
        getinput(jgs.jabatan,25,2);
        gotoxy(65, 24);
        printf("D E S K R I P S I                          : ");
        gotoxy(110, 24);
        getinput(jgs.deskripsijabatan,225,2);

        fwrite(&jgs, sizeof(jgs), 1, arsjgs);
        fclose(arsjgs);
        gotoxy(65, 26);
        printf("Data jenis petugas berhasil ditambahkan.\n");

        textBox2(69,29,56,2);
        gotoxy(70, 30);
        printf("Apakah ingin menambah data jenis petugas lagi? (y/t): ");
        pilihan = getch(); // Membaca input pilihan pengguna

        blankScreen();
    } while(pilihan == 'y' || pilihan == 'Y');

    MenuJenisPetugas();
}

#endif //CREATE_JENIS_PETUGAS_H
