//
// Created by hi on 1/30/2025.
//

#ifndef CREATELAYANAN_H
#define CREATELAYANAN_H

void CreateLayanan() {
    do {
        SetColorBlock(1,7);
        textBox2(31,10,139,33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        int lastLayanan = 0;
        i = 0;

        lastLayanan = 0;
        FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb"); // Buka file untuk membaca dan menulis

        while(fread(&lyn,sizeof(lyn),1,arslyn)) {
            if(lyn.id_layanan >= lastLayanan) {
                lastLayanan = lyn.id_layanan;
            }
        }
        lastLayanan++;
        fclose(arslyn);

        arslyn = fopen("../Database/Dat/LAYANAN.dat", "ab+"); // Buka file untuk membaca dan menulis
        lyn.id_layanan = lastLayanan;

        // Buat ID Jenis Petugas secara otomatis
        textBox2(61,18,72,7);
        BoxBlock(63,19,70,5);
        SetColorBlock(7,1);
        gotoxy(65, 20);
        printf("I D  J E N I S  P E T U G A S         : LYN%03d\n", lyn.id_layanan); // Tampilkan ID petugas
        for ( i = 105; i <= 130 ; i++) {
            gotoprintchar(i,21,196);
        }
        gotoprinttext(65,22,"N A M A  J E N I S  L A Y A N A N     : ");
        for ( i = 105; i <= 130 ; i++) {
            gotoprintchar(i,23,196);
        }
        gotoxy(105,22);
        getinput(lyn.jnslayanan,25,2);

        fwrite(&lyn, sizeof(lyn), 1, arslyn);
        fclose(arslyn);
        gotoxy(75, 35);
        SetColorBlock(1,7);
        printf("Data jenis petugas berhasil ditambahkan.\n");
        SetColorBlock(7,1);
        textBox2(69,37,56,2);
        gotoxy(70, 38);
        printf("Apakah ingin menambah data jenis petugas lagi (y/t) : ");
        gotoxy(124,38);
        getinput(&Opsi,1,2);

        blankScreen();
    } while(Opsi == 'y' || Opsi == 'Y');

    MenuLayanan();
}
#endif //CREATELAYANAN_H
