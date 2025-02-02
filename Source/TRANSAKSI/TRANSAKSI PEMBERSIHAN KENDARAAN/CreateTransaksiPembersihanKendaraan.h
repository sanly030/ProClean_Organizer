void createTransaksiKendaraan();
void TambahDetailTransaksiPembersihanKendaraan();

void TambahTransaksiPembersihanKendaraan() {
    found = 0;
    i = 0;
    total = 0;
    trsTKendaraan.totalHarga = 0;


    fileTransaksiKendaraan = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANKENDARAAN.dat", "ab+");
    fread(&trsTKendaraan,sizeof(trsTKendaraan),1,fileTransaksiKendaraan);
    while(!feof(fileTransaksiKendaraan)) {
        fread(&trsTKendaraan,sizeof(trsTKendaraan),1,fileTransaksiKendaraan);
        id = trsTKendaraan.id_TKendaraan;
        i++;
    }
    if(i==0){
        trsTKendaraan.id_TKendaraan = 1;
    }else{
        trsTKendaraan.id_TKendaraan = id+1;
    }
    SetColorBlock(7,9);
    gotoxy(40, 12);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70, 12);
    generateid("TRSPK",trsTKendaraan.id_TKendaraan);
    fclose(fileTransaksiKendaraan);
    TambahDetailTransaksiPembersihanKendaraan();
}

void TambahDetailTransaksiPembersihanKendaraan() {
    FILE *Temp;
    found = 0;
    SetColorBlock(7,9);
    dTKendaraan.id_TKendaraan = trsTKendaraan.id_TKendaraan;
    gotoxy(40,12);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70,12);
    generateid("TRSPK",dTKendaraan.id_TKendaraan);

    gotoxy(40,14);
    printf("N A M A  T R A N S A K S I  :");
    gotoxy(70,14);
    getinput(dTKendaraan.namaTKendaraan,25,2);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePelangganinTransaksi();
        gotoxy(40, 16);
        SetColorBlock(7,9);
        printf("I D  P E L A N G G A N     :  PLG");
        gotoxy(73, 16);
        getnum(&trsTKendaraan.id_plg,3);
        found = 0;
        if(trsTKendaraan.id_plg == 0){
            BlankDashboard();
            Dashboard();
        }
        arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
        while(fread(&plg,sizeof (plg),1,arsplg)==1){
            if(trsTKendaraan.id_plg == plg.id_plg){
                found = 1;
                trsTKendaraan.id_plg = plg.id_plg;
                strcpy(trsTKendaraan.namaPlg,plg.namaPlg);
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
    printf("%s", trsTKendaraan.namaPlg);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateJenisPaketinTransaksiKendaraan();
        gotoxy(40, 20);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P A K E T   :  JPP");
        gotoxy(74, 20);
        getnum(&trsTKendaraan.id_jnslayanan,3);
        found = 0;
        if(trsTKendaraan.id_jnslayanan == 0){
            BlankDashboard();
            Dashboard();
        }
        FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
        while(fread(&jly,sizeof (jly),1,arsjly)==1){
            if(trsTKendaraan.id_jnslayanan == jly.id_jnslayanan){
                found = 1;
                trsTKendaraan.id_jnslayanan = jly.id_jnslayanan;
                strcpy(trsTKendaraan.jenispaket,jly.jenispaket);
                trsTKendaraan.durasi = jly.durasi;
                trsTKendaraan.totalHarga = jly.harga;
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
    printf("%s", trsTKendaraan.jenispaket);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePembayaraninTransaksi();
        gotoxy(40, 24);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P E M B A Y A R A N: JPR");
        gotoxy(81, 24);
        getnum(&trsTKendaraan.id_pembayaran,3);
        found = 0;
        if(trsTKendaraan.id_jnslayanan == 0){
            BlankDashboard();
            Dashboard();
        }
        arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
        while(fread(&peb,sizeof (peb),1,arspeb)==1){
            if(trsTKendaraan.id_pembayaran == peb.id_pembayaran){
                found = 1;
                trsTKendaraan.id_pembayaran = peb.id_pembayaran;
                strcpy(trsTKendaraan.namaPembayaran,peb.namaPembayaran);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID JENIS PEMBAYARAN TIDAK TERSEDIA Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,21,3,1);
        }
        BlankDesain();
        hideCursor();


    }while(found == 0);
    SetColorBlock(7,9);
    gotoxy(40,26);
    printf("N A M A  J E N I S  P E M B A Y A R A N:");
    gotoxy(75,26);
    printf("%s", trsTKendaraan.namaPembayaran);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePromoinTransaksi();
        gotoxy(40, 28);
        SetColorBlock(7,9);
        printf("I D  P R O M O             : PRM");
        gotoxy(73, 28);
        getnum(&trsTKendaraan.id_promo,3);
        found = 0;
        if(trsTKendaraan.id_promo == 0){
            BlankDashboard();
            Dashboard();
        }
        arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
        while(fread(&prm,sizeof (prm),1,arsprm)==1){
            if(trsTKendaraan.id_promo == prm.id_promo){
                found = 1;
                trsTKendaraan.id_promo = prm.id_promo;
                strcpy(trsTKendaraan.namaPromo,prm.namaPromo);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Promo Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,17,3,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);
    SetColorBlock(7,9);
    gotoxy(40,30);
    printf("N A M A  J E N I S  P R O M O :");
    gotoxy(75,30);
    printf("%s", trsTKendaraan.namaPromo);

    gotoxy(40, 32);
    printf("T G L  P E M E S A N A N    : ");
    gotoprinttext(69, 32, "  /  /     \n");
    do {
        gotoxy(69, 32);
        getnum(&trsTKendaraan.pemesanan.hari,2);
        if(trsTKendaraan.pemesanan.hari > 31 || trsTKendaraan.pemesanan.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(69,15,2,1);
        }
    }
    while(trsTKendaraan.pemesanan.hari > 31 || trsTKendaraan.pemesanan.hari < 1 );
    do {
        gotoxy(72, 32);
        getnum(&trsTKendaraan.pemesanan.bulan,2);
        if(trsTKendaraan.pemesanan.bulan > 12 || trsTKendaraan.pemesanan.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(72,15,2,1);
        }
    }while(trsTKendaraan.pemesanan.bulan > 12 || trsTKendaraan.pemesanan.bulan < 1);
    do {
        gotoxy(75, 32);
        getnum(&trsTKendaraan.pemesanan.tahun, 4);
        hideCursor();
        if (trsTKendaraan.pemesanan.tahun < 2025 || trsTKendaraan.pemesanan.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2025 - 2028", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75, 15, 4, 1);
        }
    }while(trsTKendaraan.pemesanan.tahun < 2025  || trsTKendaraan.pemesanan.tahun > 2028);


    SetColorBlock(7,9);
    gotoxy(40,34);
    printf("D U R A S I               :");
    gotoxy(70,34);
    printf("%d Menit", trsTKendaraan.durasi);

    SetColorBlock(7,9);
    gotoxy(40,34);
    printf("T O T A L  H A R G A        :");
    gotoxy(70,34);
    printf("Rp. %.0f", trsTKendaraan.totalHarga);

}

void createTransaksiKendaraan(){
    frameTransaksi(42, 12);
    SetColorBlock(1,7);
    TambahTransaksiPembersihanKendaraan();
    fclose(fileTransaksiKendaraan);
}