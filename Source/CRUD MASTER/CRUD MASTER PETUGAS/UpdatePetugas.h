#ifndef UPDATEPETUGAS_H
#define UPDATEPETUGAS_H

void lihatData();
// Fungsi Ubah Data
void UpdatePetugas() {
    clearArea(30,10,140,31);
    int id_petugas;
    int found = 0;

    lihatData();
    gotoxy(72,21);
    printf("-----------------------------------");
    gotoxy(72,22);
    printf("  U B A H  D A T A  P E T U G A S");
    gotoxy(72,23);
    printf("-----------------------------------\n");
    gotoprinttext(72,24,"Masukkan ID Petugas yang ingin diubah: PGS00 ");
    gotoxy(116,24);
    scanf("%d", &id_petugas);

    FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP PETUGAS.dat", "wb");

    // clearArea(48,10,123,33);
    // frame(72,20);
    while (fread(&pgs, sizeof(petugas), 1, arspgs)) {
        if (pgs.id_petugas == id_petugas) {
            found = 1;
            gotoprinttext(65,23,"Masukkan Nama Petugas Baru      : ");
            scanf("%s", &pgs.nama);
            gotoprinttext(65,24,"Masukkan Alamat Baru             :");
            scanf("%s", &pgs.alamat);
            gotoprinttext(65,25,"Masukkan No. Telepon Baru       : ");
            scanf("%s", &pgs.no_telp);
            gotoprinttext(65,26,"Masukkan Status Baru            : ");
            scanf("%s", &pgs.status);
            gotoprinttext(65,27,"Masukkan Username Baru          : ");
            scanf("%s", &pgs.username);
            gotoprinttext(65,28,"Masukkan Password Baru          : ");
            scanf("%s", &pgs.password);
        }
        fwrite(&pgs, sizeof(petugas), 1, temp);
    }

    fclose(arspgs);
    fclose(temp);

    remove("../Database/Dat/DATA PETUGAS.dat");
    rename("TEMP PETUGAS.dat", "../Database/Dat/DATA PETUGAS.dat");

    if (found) {
        gotoprinttext(65,30,"Data petugas berhasil diubah.\n");
    } else {
        gotoxy(65,30);

        printf("Data dengan ID Petugas PGS00%d tidak ditemukan.\n", id_petugas);
    }
    getch();
    DashboardMenuAdmin();
}


void lihatData() {
    int A=15, I=53, N =0;
    int x,j;
    fflush(stdin);
        FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb");

        if (arspgs == NULL) {
            printf("File could not be opened\n");
            return;
        }
        for(x=I;x < 150;x++) {
            gotoxy(x,12);printf("%c",205);
            gotoxy(x,14);printf("%c",205);
        }
        gotoxy(55, 13);printf("ID Petugas");
        gotoxy(70, 13);printf("Nama");
        gotoxy(84, 13);printf("Alamat");
        gotoxy(96, 13);printf("No.Telepon");
        gotoxy(110, 13);printf("Status");
        gotoxy(123, 13);printf("Username");
        gotoxy(140, 13);printf("Password");

        while(fread(&pgs, sizeof(petugas), 1, arspgs)) {
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
            gotoxy(55,A);printf("PGS00%d",pgs.id_petugas);
            gotoxy(70,A);printf("%s",pgs.nama);
            gotoxy(84,A);printf("%s",pgs.alamat);
            gotoxy(96,A);printf("%s",pgs.no_telp);
            gotoxy(110,A);printf("%s",pgs.status);
            gotoxy(123,A);printf("%s",pgs.username);
            gotoxy(140,A);printf("%s",pgs.password);
            fflush(stdin);
        }
        fclose(arspgs);
    }
#endif //UPDATEPETUGAS_H
