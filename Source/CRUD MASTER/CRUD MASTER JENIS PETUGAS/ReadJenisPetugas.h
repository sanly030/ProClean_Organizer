//
// Created by hi on 1/12/2025.
//

#ifndef READJENISPETUGAS_H
#define READJENISPETUGAS_H

void ReadJenisPetugas() {
    FILE *JGS = fopen("../Database/Dat/JENIS PETUGAS.dat", "rb");
    if (JGS == NULL) {
        printf("File could not be opened\n");
    }
    gotoxy(65,12);
    printf("-----------------------------------");
    gotoxy(70, 13);
    printf("D A T A  J E N I S  P E T U G A S");
    gotoxy(65, 14);
    printf("-----------------------------------\n");
    for(x=I;x < 150;x++) {
        gotoxy(x,15);printf("%c",205);
        gotoxy(x,17);printf("%c",205);
    }
    gotoxy(55, 16);printf("ID Jenis Petugas");
    gotoxy(70, 16);printf("Jenis Petugas");
    gotoxy(84, 16);printf("Jabatan");

    while(fread(&jgs, sizeof(jnspetugas), 1, JGS)) {
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
        gotoxy(55,A);printf("PGS00%d",jgs.id_jenispetugas);
        gotoxy(70,A);printf("%s",jgs.namajenispetugas);
        gotoxy(84,A);printf("%s",jgs.jabatan);

    }
}
#endif //READJENISPETUGAS_H
