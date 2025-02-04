void createTransaksiRumah();
void TambahDetailTransaksiPembersihanRumah();

void TambahTransaksiPembersihanRumah() {
    found = 0;
    i = 0;
    total = 0;
    trsTRumah.totalHarga = 0;

    fileTransaksiRumah = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "ab+");
    fread(&trsTRumah,sizeof(trsTRumah),1,fileTransaksiRumah);
    while(!feof(fileTransaksiRumah)){
        fread(&trsTRumah,sizeof(trsTRumah),1,fileTransaksiRumah);
        id = trsTRumah.id_TRumah;
        i++;
    }
    if(i==0){
        trsTRumah.id_TRumah = 1;
    }else{
        trsTRumah.id_TRumah = id+1;
    }
    SetColorBlock(7,9);
    gotoxy(42, 18);
    printf("I D  T R A N S A K S I              :");
    gotoxy(80, 18);
    generateid("TRSPR",trsTRumah.id_TRumah);
    fclose(fileTransaksiRumah);
    TambahDetailTransaksiPembersihanRumah();
}

void TambahDetailTransaksiPembersihanRumah() {
    FILE *Temp;
    found = 0;
    SetColorBlock(7,9);
    dTRumah.id_TRumah = trsTRumah.id_TRumah;
    gotoxy(42,18);
    printf("I D  T R A N S A K S I              :");
    gotoxy(80,18);
    generateid("TRSPR",dTRumah.id_TRumah);

    gotoxy(42,20);
    printf("N A M A  T R A N S A K S I          :");
    gotoxy(80,20);
    getinput(dTRumah.namaTRumah,25,2);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePelangganinTransaksi();
        gotoxy(42, 22);
        SetColorBlock(7,9);
        printf("I D  P E L A N G G A N              : PLG");
        gotoxy(83, 22);
        getnum(&trsTRumah.id_plg,3);
        found = 0;
        if(trsTRumah.id_plg == 0){
            BlankDashboard();
            Dashboard();
        }
        arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
        while(fread(&plg,sizeof (plg),1,arsplg)==1){
            if(trsTRumah.id_plg == plg.id_plg){
                found = 1;
                trsTRumah.id_plg = plg.id_plg;
                strcpy(trsTRumah.namaPlg,plg.namaPlg);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Pelanggan Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,17,3,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);

    SetColorBlock(7,9);
    gotoxy(42,22);
    printf("N A M A  P E L A N G G A N          :");
    gotoxy(80,22);
    printf("%s", trsTRumah.namaPlg);

    // strcmp(opsiChar, "R") != 0 && strcmp(opsiChar, "K") != 0;
    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateJenisPaketinTransaksi();
        gotoxy(42, 24);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P A K E T           : JPP");
        gotoxy(83, 24);
        getnum(&trsTRumah.id_jnslayanan,3);
        found = 0;
        if(trsTRumah.id_jnslayanan == 0){
            BlankDashboard();
            Dashboard();
        }
        FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
        while(fread(&jly,sizeof (jly),1,arsjly)==1){
            if(trsTRumah.id_jnslayanan == jly.id_jnslayanan){
                found = 1;
                trsTRumah.id_jnslayanan = jly.id_jnslayanan;
                strcpy(trsTRumah.jenispaket,jly.jenispaket);
                trsTRumah.durasi = jly.durasi;
                trsTRumah.totalHarga = jly.harga;
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID JENIS PAKET PEMBERSIHAN Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,21,3,1);
        }
        BlankDesain();
        hideCursor();

    }while(found == 0);
    SetColorBlock(7,9);
    gotoxy(42,24);
    printf("N A M A  J E N I S  P A K E T       : ");
    gotoxy(80,24);
    printf("%s", trsTRumah.jenispaket);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePembayaraninTransaksi();
        gotoxy(42, 26);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P E M B A Y A R A N : JPR");
        gotoxy(83, 26);
        getnum(&trsTRumah.id_pembayaran,3);
        found = 0;
        if(trsTRumah.id_jnslayanan == 0){
            BlankDashboard();
            Dashboard();
        }
        arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
        while(fread(&peb,sizeof (peb),1,arspeb)==1){
            if(trsTRumah.id_pembayaran == peb.id_pembayaran){
                found = 1;
                trsTRumah.id_pembayaran = peb.id_pembayaran;
                strcpy(trsTRumah.namaPembayaran,peb.namaPembayaran);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID JENIS PAKET PEMBERSIHAN Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,21,3,1);
        }
        BlankDesain();
        hideCursor();

    }while(found == 0);
    SetColorBlock(7,9);
    gotoxy(42,26);
    printf("J E N I S  P E M B A Y A R A N      :");
    gotoxy(80,26);
    printf("%s", trsTRumah.namaPembayaran);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePromoinTransaksi();
        gotoxy(42, 28);
        SetColorBlock(7,9);
        printf("I D  P R O M O                      : PRM");
        gotoxy(83, 28);
        getnum(&trsTRumah.id_promo,3);
        found = 0;
        if(trsTRumah.id_promo == 0){
            BlankDashboard();
            Dashboard();
        }
        arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
        while(fread(&prm,sizeof (prm),1,arsprm)==1){
            if(trsTRumah.id_promo == prm.id_promo){
                found = 1;
                trsTRumah.id_promo = prm.id_promo;
                strcpy(trsTRumah.namaPromo,prm.namaPromo);
                dTRumah.potongan = prm.potongan;
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Pelanggan Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,17,3,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);
    SetColorBlock(7,9);
    gotoxy(42,28);
    printf("N A M A  J E N I S  P R O M O       :");
    gotoxy(80,28);
    printf("%s", trsTRumah.namaPromo);

    gotoxy(42, 30);
    printf("T G L  P E M E S A N A N            : ");
    gotoprinttext(80, 30, "  /  /     \n");
    do {
        gotoxy(80, 30);
        getnum(&trsTRumah.pemesanan.hari,2);
        if(trsTRumah.pemesanan.hari > 31 || trsTRumah.pemesanan.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(80,30,2,1);
        }
    }
    while(trsTRumah.pemesanan.hari > 31 || trsTRumah.pemesanan.hari < 1 );
    do {
        gotoxy(83, 30);
        getnum(&trsTRumah.pemesanan.bulan,2);
        if(trsTRumah.pemesanan.bulan > 12 || trsTRumah.pemesanan.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(83,30,2,1);
        }
    }while(trsTRumah.pemesanan.bulan > 12 || trsTRumah.pemesanan.bulan < 1);
    do {
        gotoxy(86, 30);
        getnum(&trsTRumah.pemesanan.tahun, 4);
        hideCursor();
        if (trsTRumah.pemesanan.tahun < 2025 || trsTRumah.pemesanan.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2025 - 2028", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(86, 30, 4, 1);
        }
    }while(trsTRumah.pemesanan.tahun < 2025  || trsTRumah.pemesanan.tahun > 2028);


    SetColorBlock(7,9);
    gotoxy(42,32);
    printf("D U R A S I                         : ");
    gotoxy(80,32);
    printf("%d Menit", trsTRumah.durasi);

    trsTRumah.totalHarga = jly.harga;
    trsTRumah.totalHarga = trsTRumah.totalHarga - (trsTRumah.totalHarga*dTRumah.potongan/100);
    SetColorBlock(7,9);
    gotoxy(42,34);
    printf("T O T A L  H A R G A                :");
    gotoxy(80,34);
    printf("Rp. %.0f", trsTRumah.totalHarga);
    dTRumah.totalHarga = trsTRumah.totalHarga; //Ngambil data harga terakhir setelah promo
    /* buka file untuk menambah data detail*/
    fileDTRumah = fopen("../TRANSAKSI/../Source/../Database/Dat/DETAILTRANSAKSIRUMAH.dat","ab+");
    fwrite(&dTRumah,sizeof(dTRumah),1,fileDTRumah);
    fclose(fileDTRumah);

    strcpy(trsTRumah.Status, Status[0]);
    SetColorBlock(7,9);
    gotoxy(42,36);
    printf("S T A T U S                         :");
    gotoxy(80,36);
    printf("%s", trsTRumah.Status);

    fileTransaksiRumah = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "ab");
    fwrite(&trsTRumah, sizeof(trsTRumah), 1, fileTransaksiRumah);
    fclose(fileTransaksiRumah);
    MessageBox(NULL, "Pemesanan berhasil!", "NOTIFICATION", MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
}

void createTransaksiRumah(){
    frameTransaksi(42, 12);
    SetColorBlock(1,7);
    TambahTransaksiPembersihanRumah();
    fclose(fileTransaksiRumah);
    blankScreen();
    Dashboard();
}
