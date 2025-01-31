//
// Created by hi on 1/30/2025.
//

#ifndef CREATEJNSLAYANAN_H
#define CREATEJNSLAYANAN_H


void CreateJnsLayanan() {
    do
    {
        blankScreen();
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt",50,11);

    // Menampilkan daftar jenis petugas
    FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
    if (arslyn == NULL) {
        printf("File LAYANAN.dat tidak dapat dibuka.\n");
        return;
    }

    int i = 1;
    textBox2(130,17,39,18);
    BoxBlock(131,18,38,17);
    SetColorBlock(7, 1);
    gotoprinttext(137,19, "D A F T A R  L A Y A N A N");
    while (fread(&lyn, sizeof(lyn), 1, arslyn)) {
        gotoxy(132, 20 + i);
        printf("[ %d ] %s ", lyn.id_layanan, lyn.jnslayanan);
        i++;
    }
    fclose(arslyn);


    int lastJnsLayanan = 0;
        lastJnsLayanan = 0;
    i = 0;

    FILE *arsjly = fopen("../Database/Dat/JENIS LAYANAN.dat", "rb"); // Buka file untuk membaca dan menulis

    while(fread(&jly,sizeof(jly),1,arsjly)) {
        if(jly.id_jnslayanan >= lastJnsLayanan) {
            lastJnsLayanan = jly.id_jnslayanan;
        }
    }
    lastJnsLayanan++;
    fclose(arsjly);


    int jumlahLayanan = 0;
    layanan lyn[20];
    arslyn = fopen("../Database/Dat/JENIS LAYANAN.dat", "ab+"); // Buka file untuk membaca dan menulis
    jly.id_jnslayanan = lastJnsLayanan;

    // Buat ID Jenis Petugas secara otomatis
    SetColorBlock(1, 7);
    textBox2(41,18,72,20);
    BoxBlock(43,19,70,18);
    SetColorBlock(7,1);

    gotoxy(45, 20);
    printf("I D  J E N I S  L A Y A N A N          : JPP%03d\n", jly.id_jnslayanan); // Tampilkan ID petugas
    for ( i = 85; i <= 110 ; i++) {
        gotoprintchar(i,21,196);
    }

    gotoprinttext(45,22,"N A M A  J E N I S  L A Y A N A N     : ");
    gotoprinttext(45,24,"J E N I S  P A K E T                  : ");
    // gotoprinttext(45,26,"L A Y A N A N  K E - 1                : ");
    // gotoprinttext(45,28,"L A Y A N A N  K E - 2                : ");
    // gotoprinttext(45,30,"L A Y A N A N  K E - 3                : ");
    gotoprinttext(45,26,"H A R G A                             : Rp.");
    gotoprinttext(45,28,"D U R A S I                           :     Menit");


    for ( i = 85; i <= 110 ; i++) {
        gotoprintchar(i,23,196);
    }
    for ( i = 85; i <= 110 ; i++) {
        gotoprintchar(i,25,196);
    }
    for ( i = 85; i <= 110 ; i++) {
        gotoprintchar(i,27,196);
    }
    for ( i = 85; i <= 110 ; i++) {
        gotoprintchar(i,29,196);
    }


    gotoxy(85,22);
    getinput(jly.namajnslyn,25,2);

    gotoxy(85,24);
    getinput(jly.jenispaket,25,2);

    gotoxy(88,26);
    getRp(&jly.harga,4,6,88,26);

    gotoxy(85,28);
    getnum(&jly.durasi,3);

    fwrite(&jly, sizeof(jly), 1, arsjly);
    fclose(arsjly);
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

MenuJnsLayanan();



}
#endif //CREATEJNSLAYANAN_H
