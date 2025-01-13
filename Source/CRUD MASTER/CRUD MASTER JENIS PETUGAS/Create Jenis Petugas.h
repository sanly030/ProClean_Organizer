#ifndef CREATE_JENIS_PETUGAS_H
#define CREATE_JENIS_PETUGAS_H
void CreateJenisPetugas() {
    fflush(stdin);
    int lastpetugas = 0;
    i = 0;

    lastpetugas = 0;
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb"); // Buka file untuk membaca dan menulis
    jnspetugas jgs;
    while(fread(&jgs,sizeof(jnspetugas),1,arsjgs)) {
        if(jgs.id_jenispetugas >= lastpetugas) {
            lastpetugas = jgs.id_jenispetugas;
        }
    }
    lastpetugas++;
    fclose(arsjgs);

    arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "ab"); // Buka file untuk membaca dan menulis
    jgs.id_jenispetugas = lastpetugas;


    // Buat ID Jenis Petugas secara otomatis

    gotoxy(65, 15);
    printf("-----------------------------------");
    gotoprinttext(65,16,"T A M B A H  D A T A  J E N I S  P E T U G A S");
    gotoxy(65, 17);
    printf("-----------------------------------");
    gotoxy(65, 20);
    printf("ID Jenis Petugas                    : PGS%03d\n", jgs.id_jenispetugas); // Tampilkan ID petugas
    gotoprinttext(65,22,"Masukkan Jenis Petugas         : ");
    scanf(" %[^\n]", jgs.namajenispetugas);
    gotoxy(65, 24);
    printf("Masukkan Jabatan            : ");
    scanf(" %[^\n]", jgs.jabatan);
    gotoxy(65, 26);

    fwrite(&jgs, sizeof(jnspetugas), 1, arsjgs);
    fclose(arsjgs);
    printf("Data jenis petugas berhasil ditambahkan.\n");
}

#endif //CREATE_JENIS_PETUGAS_H
