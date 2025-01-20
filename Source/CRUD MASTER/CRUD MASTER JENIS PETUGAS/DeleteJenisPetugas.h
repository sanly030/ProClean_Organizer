//
// Created by hi on 1/12/2025.
//

#ifndef DELETEJENISPETUGAS_H
#define DELETEJENISPETUGAS_H

void DeleteJenisPetugas() {
    int id_petugas;
    int found = 0;
    fflush(stdin);

    gotoxy(65,15);
    printf("-----------------------------------");
    gotoxy(65,16);
    printf("H A P U S  D A T A  P E T U G A S");
    gotoxy(65,17);
    printf("-----------------------------------\n");
    gotoxy(65,18);
    printf("Masukkan ID Petugas yang ingin dihapus : JPS00 ");
    gotoxy(111,18);
    scanf("%d", &id_petugas);

    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP PETUGAS.dat", "wb");

    if (arsjgs == NULL || temp == NULL) {
        printf("File could not be opened\n");
        return;
    }

    while (fread(&jgs, sizeof(jnspetugas), 1, arsjgs)) {
        if (jgs.id_jenispetugas != id_petugas) {
            fwrite(&jgs, sizeof(jnspetugas), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(arsjgs);
    fclose(temp);

    remove("../Database/Dat/JENIS PETUGAS.dat");
    rename("TEMP PETUGAS.dat", "../Database/Dat/JENIS PETUGAS.dat");

    if (found) {
        gotoprinttext(65,21,"Data petugas berhasil dihapus.\n");
    } else {
        gotoxy(65,21);
        printf("Data dengan ID Petugas JPS00%d tidak ditemukan.\n", id_petugas);
    }
    getch();
    MenuJenisPetugas();
}
#endif //DELETEJENISPETUGAS_H
