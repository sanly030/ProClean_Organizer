#ifndef DELETEPETUGAS_H
#define DELETEPETUGAS_H

// Fungsi Hapus Data
void DeletePetugas() {
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
    printf("Masukkan ID Petugas yang ingin dihapus : PGS00 ");
    gotoxy(111,18);
    scanf("%d", &id_petugas);

    FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP PETUGAS.dat", "wb");

    if (arspgs == NULL || temp == NULL) {
        printf("File could not be opened\n");
        return;
    }

    while (fread(&pgs, sizeof(petugas), 1, arspgs)) {
        if (pgs.id_petugas != id_petugas) {
            fwrite(&pgs, sizeof(petugas), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(arspgs);
    fclose(temp);

    remove("../Database/Dat/DATA PETUGAS.dat");
    rename("TEMP PETUGAS.dat", "../Database/Dat/DATA PETUGAS.dat");

    if (found) {
        gotoprinttext(65,21,"Data petugas berhasil dihapus.\n");
    } else {
        gotoxy(65,21);
        printf("Data dengan ID Petugas PGS00%d tidak ditemukan.\n", id_petugas);
    }
    getch();
    DashboardMenuAdmin();
}
#endif //DELETEPETUGAS_H
