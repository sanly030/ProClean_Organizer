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
    gotoxy(42, 18);
    printf("I D  T R A N S A K S I              :");
    gotoxy(80, 18);
    generateid("TRSPK",trsTKendaraan.id_TKendaraan);
    fclose(fileTransaksiKendaraan);
    TambahDetailTransaksiPembersihanKendaraan();
}

void TambahDetailTransaksiPembersihanKendaraan() {
    FILE *Temp;
    found = 0;
    SetColorBlock(7,9);
    dTKendaraan.id_TKendaraan = trsTKendaraan.id_TKendaraan;
    gotoxy(42,18);
    printf("I D  T R A N S A K S I              :");
    gotoxy(80,18);
    generateid("TRSPK",dTKendaraan.id_TKendaraan);

    gotoxy(42,20);
    printf("N A M A  T R A N S A K S I          :");
    gotoxy(80,20);
    getinput(dTKendaraan.namaTKendaraan,25,2);
    if(strcmpi(dTKendaraan.namaTKendaraan, "exit")==0) {
        blankScreen();
        Dashboard();
    }

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePelangganinTransaksi();
        gotoxy(42, 22);
        SetColorBlock(7,9);
        printf("I D  P E L A N G G A N              : PLG");
        gotoxy(83, 22);
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
            clearArea(83,22,1,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);

    SetColorBlock(7,9);
    clearArea(42,22,38,1);
    gotoxy(42,22);
    printf("N A M A  P E L A N G G A N          :");
    gotoxy(80,22);
    printf("%s", trsTKendaraan.namaPlg);

    do {fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateKendaraaninTransaksi();
        gotoxy(42, 24);
        SetColorBlock(7,9);
        printf("I D  J E N I S  K E N D A R A A N   : JNK");
        gotoxy(83, 24);
        getnum(&trsTKendaraan.id_jeniskendaraan,3);
        found = 0;
        if(trsTKendaraan.id_jeniskendaraan == 0){
            BlankDashboard();
            Dashboard();
        }
        arskdr = fopen("../Database/Dat/JENIS_KENDARAAN.dat", "rb");
        while(fread(&kdr,sizeof (kdr),1,arskdr)==1){
            if(trsTKendaraan.id_jeniskendaraan == kdr.id_jeniskendaraan){
                found = 1;
                trsTKendaraan.id_jeniskendaraan = kdr.id_jeniskendaraan;
                strcpy(trsTKendaraan.jenisKendaraan,kdr.jenisKendaraan);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Jenis Kendaraan Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(73,17,3,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);

    SetColorBlock(7,9);
    gotoxy(42,24);
    printf("J E N I S  K E N D A R A A N        :");
    gotoxy(80,24);
    printf("%s", trsTKendaraan.jenisKendaraan);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateJenisPaketinTransaksiKendaraan();
        gotoxy(42, 26);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P A K E T           : JPP");
        gotoxy(83, 26);
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
    gotoxy(42,26);
    printf("N A M A  J E N I S  P A K E T       :");
    gotoxy(80,26);
    printf("%s", trsTKendaraan.jenispaket);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePembayaraninTransaksi();
        gotoxy(42, 28);
        SetColorBlock(7,9);
        printf("I D  J E N I S  P E M B A Y A R A N : JPR");
        gotoxy(83, 28);
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
    clearArea(42,28,41,1);
    gotoxy(42,28);
    printf("J E N I S  P E M B A Y A R A N      :");
    gotoxy(80,28);
    printf("%s", trsTKendaraan.namaPembayaran);

    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreatePromoinTransaksi();
        gotoxy(42, 30);
        SetColorBlock(7,9);
        printf("I D  P R O M O                      : PRM");
        gotoxy(83, 30);
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
    gotoxy(42,30);
    printf("N A M A  J E N I S  P R O M O       : ");
    gotoxy(80,30);
    printf("%s", trsTKendaraan.namaPromo);

    gotoxy(42, 32);
    printf("T G L  P E M E S A N A N            : ");
    gotoprinttext(80, 32, "  /  /     \n");
    do {
        gotoxy(80, 32);
        getnum(&trsTKendaraan.pemesanan.hari,2);
        if(trsTKendaraan.pemesanan.hari > 31 || trsTKendaraan.pemesanan.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(80,32,2,1);
        }
    }
    while(trsTKendaraan.pemesanan.hari > 31 || trsTKendaraan.pemesanan.hari < 1 );
    do {
        gotoxy(83, 32);
        getnum(&trsTKendaraan.pemesanan.bulan,2);
        if(trsTKendaraan.pemesanan.bulan > 12 || trsTKendaraan.pemesanan.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(86,32,2,1);
        }
    }while(trsTKendaraan.pemesanan.bulan > 12 || trsTKendaraan.pemesanan.bulan < 1);
    do {
        gotoxy(86, 32);
        getnum(&trsTKendaraan.pemesanan.tahun, 4);
        hideCursor();
        if (trsTKendaraan.pemesanan.tahun < 2025 || trsTKendaraan.pemesanan.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2025 - 2028", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(86, 32, 4, 1);
        }
    }while(trsTKendaraan.pemesanan.tahun < 2025  || trsTKendaraan.pemesanan.tahun > 2028);


    SetColorBlock(7,9);
    gotoxy(42,34);
    printf("D U R A S I                         :");
    gotoxy(80,34);
    printf("%d Menit", trsTKendaraan.durasi);

    SetColorBlock(7,9);
    gotoxy(42,36);
    printf("T O T A L  H A R G A                :");
    gotoxy(80,36);
    printf("Rp. %.0f", trsTKendaraan.totalHarga);
    dTKendaraan.totalHarga = trsTKendaraan.totalHarga;

    fileDTKendaraan = fopen("../TRANSAKSI/../Soure/../Database/Dat/DETAILTRANSAKSIKENDARAAN.dat", "ab+");
    fwrite(&dTKendaraan,sizeof(dTKendaraan),1,fileDTKendaraan);
    fclose(fileDTKendaraan);

    strcpy(trsTKendaraan.Status, Status[0]);
    SetColorBlock(7,9);
    gotoxy(42,38);
    printf("S T A T U S              :");
    gotoxy(80,38);
    printf("%s", trsTKendaraan.Status);

    fileTransaksiKendaraan = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANKENDARAAN.dat", "ab");
    fwrite(&trsTKendaraan,sizeof(dTKendaraan),1,fileTransaksiKendaraan);
    fclose(fileTransaksiKendaraan);
    MessageBox(NULL, "Pemesanan berhasil!", "NOTIFICATION", MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);

}

void createTransaksiKendaraan(){
    frameTransaksi(42, 12);
    SetColorBlock(1,7);
    TambahTransaksiPembersihanKendaraan();
    fclose(fileTransaksiKendaraan);
    blankScreen();
    Dashboard();
}