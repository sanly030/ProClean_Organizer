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
    gotoxy(40, 12);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70, 12);
    generateid("TRSPR",trsTRumah.id_TRumah);
    fclose(fileTransaksiRumah);
    TambahDetailTransaksiPembersihanRumah();
}

void TambahDetailTransaksiPembersihanRumah() {
    FILE *Temp;
    found = 0;
    SetColorBlock(7,9);
    dTRumah.id_TRumah = trsTRumah.id_TRumah;
    gotoxy(40,12);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70,12);
    generateid("TRSPR",dTRumah.id_TRumah);

    gotoxy(40,14);
    printf("N A M A  T R A N S A K S I  :");
    gotoxy(70,14);
    getinput(dTRumah.namaTRumah,25,2);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePelangganinTransaksi();
        gotoxy(40, 16);
        SetColorBlock(7,9);
        printf("I D  P E L A N G G A N     :  PLG");
        gotoxy(73, 16);
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
    gotoxy(40,18);
    printf("N A M A  P E L A N G G A N  :");
    gotoxy(70,18);
    printf("%s", trsTRumah.namaPlg);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateJenisPaketinTransaksi();
        gotoxy(40, 20);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P A K E T   :  JPP");
        gotoxy(74, 20);
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
    gotoxy(40,22);
    printf("N A M A  J E N I S  P A K E T :");
    gotoxy(70,22);
    printf("%s", trsTRumah.jenispaket);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePembayaraninTransaksi();
        gotoxy(40, 24);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P E M B A Y A R A N: JPR");
        gotoxy(81, 24);
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
    gotoxy(40,26);
    printf("N A M A  J E N I S  P E M B A Y A R A N:");
    gotoxy(75,26);
    printf("%s", trsTRumah.namaPembayaran);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePromoinTransaksi();
        gotoxy(40, 28);
        SetColorBlock(7,9);
        printf("I D  P R O M O             : PRM");
        gotoxy(73, 28);
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
    gotoxy(40,30);
    printf("N A M A  J E N I S  P R O M O :");
    gotoxy(75,30);
    printf("%s", trsTRumah.namaPromo);

    gotoxy(40, 32);
    printf("T G L  P E M E S A N A N    : ");
    gotoprinttext(69, 32, "  /  /     \n");
    do {
        gotoxy(69, 32);
        getnum(&trsTRumah.pemesanan.hari,2);
        if(trsTRumah.pemesanan.hari > 31 || trsTRumah.pemesanan.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(69,15,2,1);
        }
    }
    while(trsTRumah.pemesanan.hari > 31 || trsTRumah.pemesanan.hari < 1 );
    do {
        gotoxy(72, 32);
        getnum(&trsTRumah.pemesanan.bulan,2);
        if(trsTRumah.pemesanan.bulan > 12 || trsTRumah.pemesanan.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(72,15,2,1);
        }
    }while(trsTRumah.pemesanan.bulan > 12 || trsTRumah.pemesanan.bulan < 1);
    do {
        gotoxy(75, 32);
        getnum(&trsTRumah.pemesanan.tahun, 4);
        hideCursor();
        if (trsTRumah.pemesanan.tahun < 2025 || trsTRumah.pemesanan.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2025 - 2028", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75, 15, 4, 1);
        }
    }while(trsTRumah.pemesanan.tahun < 2025  || trsTRumah.pemesanan.tahun > 2028);


    SetColorBlock(7,9);
    gotoxy(40,34);
    printf("D U R A S I               :");
    gotoxy(70,34);
    printf("%d Menit", trsTRumah.durasi);

    SetColorBlock(7,9);
    gotoxy(40,34);
    printf("T O T A L  H A R G A        :");
    gotoxy(70,34);
    printf("Rp. %.0f", trsTRumah.totalHarga);


}

void createTransaksiRumah(){
    frameTransaksi(42, 12);
    SetColorBlock(1,7);
    TambahTransaksiPembersihanRumah();
    fclose(fileTransaksiRumah);
}