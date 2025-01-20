#ifndef READPETUGAS_H
#define READPETUGAS_H



// Fungsi Tampilkan Data
void ReadPetugas() {
    A=17, I=53, N=0;
    FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb");

    if (arspgs == NULL) {
        printf("File could not be opened\n");
        return;
    }

    gotoxy(65,12);
    printf("-----------------------------------");
    gotoxy(70, 13);
    printf("D A T A  P E T U G A S");
    gotoxy(65, 14);
    printf("-----------------------------------\n");
    for(x=I;x < 150;x++) {
        gotoxy(x,15);printf("%c",205);
        gotoxy(x,17);printf("%c",205);
    }
        gotoxy(55, 16);printf("ID Petugas");
        gotoxy(70, 16);printf("Nama");
        gotoxy(84, 16);printf("Alamat");
        gotoxy(96, 16);printf("No.Telepon");
        gotoxy(110, 16);printf("Status");
        gotoxy(123, 16);printf("Username");
        gotoxy(140, 16);printf("Password");

    A = 17;
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
        A+1;

        fflush(stdin);
    }
    fclose(arspgs);
    getch();
    DashboardMenuAdmin();
}
#endif
