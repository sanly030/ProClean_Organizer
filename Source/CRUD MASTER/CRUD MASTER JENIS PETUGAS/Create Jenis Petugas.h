#ifndef CREATE_JENIS_PETUGAS_H
#define CREATE_JENIS_PETUGAS_H

void CreateJenisPetugas() {
    FILE *JGS = fopen("../Database/Dat/JENIS PETUGAS.dat", "ab+");
    if (JGS == NULL) {
        printf("File could not be opened\n");
        return;
    }

    int count = 0;
    jnspetugas temp;

    // Hitung jumlah data yang ada di file
    while (fread(&temp, sizeof(jnspetugas), 1, JGS)) {
        count++;
    }

    // Buat ID Jenis Petugas secara otomatis

    gotoxy(65, 15);
    printf("-----------------------------------");
    gotoprinttext(65,16,"T A M B A H  D A T A  J E N I S  P E T U G A S");
    gotoxy(65, 17);
    printf("-----------------------------------");
    gotoxy(65, 20);
    printf("ID Petugas                    : PGS%03d\n", jgs.id_jenispetugas); // Tampilkan ID petugas
    gotoprinttext(65,22,"Masukkan Jenis Petugas         : ");
    scanf(" %[^\n]", jgs.namaJenisKaryawan);
    gotoxy(65, 24);
    printf("Masukkan Jabatan            : ");
    scanf(" %[^\n]", jgs.jabatan);
    gotoxy(65, 26);

    fwrite(&jgs, sizeof(jnspetugas), 1, JGS);
    fclose(JGS);
    printf("Data jenis petugas berhasil ditambahkan.\n");
}


#endif //CREATE_JENIS_PETUGAS_H
