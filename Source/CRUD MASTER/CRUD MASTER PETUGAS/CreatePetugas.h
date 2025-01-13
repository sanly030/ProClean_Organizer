static int lastpetugas = 0;
void CreatePetugas() {
    fflush(stdin);
    i = 0;

    FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb"); // Buka file untuk membaca dan menulis
    petugas pgs;
    while(fread(&pgs,sizeof(petugas),1,arspgs)) {
       if(pgs.id_petugas >= lastpetugas) {
           lastpetugas = pgs.id_petugas;
       }
   }
    lastpetugas++;
    fclose(arspgs);

    arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "ab"); // Buka file untuk membaca dan menulis
    pgs.id_petugas = lastpetugas;
    // Masukkan data lainnya
    gotoxy(65, 15);
    printf("-----------------------------------");
    gotoprinttext(65,16,"T A M B A H  D A T A  P E T U G A S");
    gotoxy(65, 17);
    printf("-----------------------------------");
    gotoxy(65, 20);
    printf("ID Petugas                    : PGS%03d\n", pgs.id_petugas); // Tampilkan ID petugas
    gotoprinttext(65,22,"Masukkan Nama Petugas         : ");
    scanf(" %[^\n]", pgs.nama);
    gotoxy(65, 24);
    printf("Masukkan Alamat Petugas       : ");
    scanf(" %[^\n]", pgs.alamat);
    gotoxy(65, 26);
    printf("Masukkan No. Telepon Petugas  : ");
    scanf(" %[^\n]", pgs.no_telp);
    gotoxy(65, 28);
    printf("Masukkan Status Petugas       : ");
    scanf(" %[^\n]", pgs.status);
    gotoxy(65, 30);
    printf("Masukkan Username Petugas     : ");
    scanf(" %[^\n]", pgs.username);
    gotoxy(65, 32);
    printf("Masukkan Password Petugas     : ");
    scanf(" %[^\n]", pgs.password);



    fseek(arspgs, 0, SEEK_END);
    fwrite(&pgs, sizeof(petugas), 1, arspgs);
    fclose(arspgs);

    gotoxy(65, 35);
    printf("Data petugas berhasil ditambahkan dengan ID: PGS00%d.\n", pgs.id_petugas);
    getch();
    MenuAdmin();
}
