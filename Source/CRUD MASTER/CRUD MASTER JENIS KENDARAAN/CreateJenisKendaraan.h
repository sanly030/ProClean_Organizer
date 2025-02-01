#ifndef CREATEJENISKENDARAAN_H
#define CREATEJENISKENDARAAN_H

void CreateJenisKendaraan() {
    do {
        SetColorBlock(1,7);
        textBox2(31,10,139,33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        int lastJenisKendaraan = 0;
        i = 0;

        lastJenisKendaraan = 0;
        FILE *arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb"); // Buka file untuk membaca dan menulis

        while(fread(&kdr,sizeof(kdr),1,arskdr)) {
            if(kdr.id_jeniskendaraan >= lastJenisKendaraan) {
                lastJenisKendaraan = kdr.id_jeniskendaraan;
            }
        }
        lastJenisKendaraan++;
        fclose(arskdr);

        arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "ab+"); // Buka file untuk membaca dan menulis
        kdr.id_jeniskendaraan = lastJenisKendaraan;

        // Buat ID Jenis Kendaraan secara otomatis
        textBox2(61,18,72,12);
        BoxBlock(63,19,70,10);
        SetColorBlock(7,1);
        gotoxy(65, 20);
        printf("I D  J E N I S  K E N D A R A A N   : JNK%03d\n", kdr.id_jeniskendaraan); // Tampilkan ID jenis kendaraan
        gotoprinttext(65,22,"J E N I S  K E N D A R A A N        : ");

        for ( i = 102; i <= 130 ; i++) {
            gotoprintchar(i,21,196);
        }
        for ( i = 102; i <= 130 ; i++) {
            gotoprintchar(i,23,196);
        }

        // Validasi Jenis Kendaraan
        gotoxy(103,22);
        getinput(kdr.jenisKendaraan,25,2);
        if(strcmpi(kdr.jenisKendaraan,"exit")==0) {
            blankScreen();
            MenuJenisKendaraan();
        }

        fwrite(&kdr, sizeof(kdr), 1, arskdr);
        fclose(arskdr);
        gotoxy(75, 35);
        SetColorBlock(1,7);
        printf("Data jenis kendaraan berhasil ditambahkan.\n");
        SetColorBlock(7,1);
        textBox2(69,37,56,2);
        gotoxy(70, 38);
        printf("Apakah ingin menambah data jenis kendaraan lagi y/t : ");
        gotoxy(124,38);
        getinput(&Opsi,1,2);

        blankScreen();
    } while(Opsi == 'y' || Opsi == 'Y');

    MenuJenisKendaraan();
}
#endif //CREATEJENISKENDARAAN_H