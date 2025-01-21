#ifndef CREATE_JENIS_PETUGAS_H
#define CREATE_JENIS_PETUGAS_H

void CreateJenisPetugas() {
    SetColorBlock(1,7);
    PrintFile("..//Asset//TambahData.txt",50,11);
    int lastpetugas = 0;
    i = 0;

    lastpetugas = 0;
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb"); // Buka file untuk membaca dan menulis

    while(fread(&jgs,sizeof(jnspetugas),1,arsjgs)) {
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
    printf("ID Jenis Petugas               : JPS%03d\n", jgs.id_jenispetugas); // Tampilkan ID petugas
    gotoprinttext(65,22,"Masukkan Jenis Petugas         : ");
    scanf(" %[^\n]", jgs.jabatan);
    gotoxy(65, 24);
    printf("Masukkan deskripsi             : ");
    scanf(" %[^\n]", jgs.deskripsijabatan);
    gotoxy(65, 26);

    fwrite(&jgs, sizeof(jnspetugas), 1, arsjgs);
    fclose(arsjgs);
    printf("Data jenis petugas berhasil ditambahkan.\n");

    getch();
    MenuJenisPetugas();
}

#endif //CREATE_JENIS_PETUGAS_H
