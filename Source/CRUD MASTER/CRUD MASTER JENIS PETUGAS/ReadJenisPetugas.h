//
// Created by hi on 1/12/2025.
//

#ifndef READJENISPETUGAS_H
#define READJENISPETUGAS_H


void ReadJenisPetugas() {
    clearArea(30,10,140,31);
    A=19; I=55; N=0;
    FILE *arsjgs = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (arsjgs == NULL) {
        printf("File could not be opened\n");
    }
    gotoxy(70,12);
    printf("-----------------------------------");
    gotoxy(70 ,13);
    printf("D A T A  J E N I S  P E T U G A S");
    gotoxy(70, 14);
    printf("-----------------------------------\n");
    for(x=I;x < 127;x++) {
        gotoxy(x,16);printf("%c",205);
        gotoxy(x,18);printf("%c",205);
    }
    gotoxy(58, 17);printf("ID Jenis Petugas");
    gotoxy(78, 17);printf("Jabatan");
    gotoxy(98, 17);printf("Deskripsi");

    A=18;
    while(fread(&jgs, sizeof(jnspetugas), 1, arsjgs)) {
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
        gotoxy(58,A);printf("JPS00%d",jgs.id_jenispetugas);
        gotoxy(78,A);printf("%s",jgs.jabatan);
        gotoxy(98,A);printf("%s",jgs.deskripsijabatan);
        A+1;
        fflush(stdin);
    }
    fclose(arsjgs);
    getch();
    MenuJenisPetugas();
}
#endif //READJENISPETUGAS_H
