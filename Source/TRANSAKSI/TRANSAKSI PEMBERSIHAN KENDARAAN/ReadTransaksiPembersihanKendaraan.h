void dataTransaksiPemesananK(){
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(43, y);
    generateid("TRSPR",trsTKendaraan.id_TKendaraan);
    gotoxy(55, y);
    printf("PLG%03d", trsTKendaraan.id_plg);
    gotoxy(60, y);
    printf("JLY%03d", trsTKendaraan.id_jnslayanan);
    gotoxy(70, y);
    printf("PRM%03d", trsTKendaraan.id_promo);
    gotoxy(125, y);
    rupiah(trsTKendaraan.totalHarga,inputrp);
    printf("%s",inputrp);
}

void dataDetailTransaksiPemesananKendaraan(){
    gotoxy(38, y);
    printf("%d", a);
    gotoxy(43, y);
    generateid("TRSPR",dTKendaraan.id_TKendaraan);
    gotoxy(69, y);
    printf("%s\n", dTKendaraan.namaTKendaraan);
    gotoxy(100, y);
    printf("%.2f",dTKendaraan.totalHarga);
    gotoxy(128, y);
    rupiah(dTKendaraan.totalHarga,inputrp);
    printf("%s",inputrp);
}

void readAllDataTransaksiPembelianKendaraan(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSPR");
    tampilanTableTransaksiPembersihanKendaraan();
    i = 1;
    y = 16;

        fileTransaksiKendaraan = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANKENDARAAN.dat", "rb+");
        while (fread(&trsTKendaraan, sizeof(trsTKendaraan), 1, fileTransaksiKendaraan) == 1 ) {
            if (i % 2 == 0) {
            SetColorBlock(7,1);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPemesananK();
        } else {
            SetColorBlock(7,9);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPemesananK();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(fileTransaksiKendaraan);
}

void lihatDetailTransaksiPembersihanKendaraan(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSPR");
    gotoprinttext(152, 10, "       ");
    gotoxy(152, 10);
    showCursor();
    getnum(&temptrsTKendaraan.id_TKendaraan, 3);
    hideCursor();
    fileDTKendaraan = fopen("../TRANSAKSI/../Source/../Database/Dat/DETAILTRANSAKSIKENDARAAN.dat", "rb+");
    fread(&dTKendaraan,sizeof(dTKendaraan),1,fileDTKendaraan);
    found = 0;
    while(!feof(fileDTKendaraan) && found==0){
        if (temptrsTKendaraan.id_TKendaraan == dTKendaraan.id_TKendaraan){ /* mengecek apakah id yang dicari ada dalam id transaksi */
            found = 1;
        }else {
            fread(&dTKendaraan, sizeof(dTKendaraan), 1, fileDTKendaraan);
        }
    }
    fclose(fileDTKendaraan);
    if(found == 0) {
        cancel = MessageBoxA(NULL,"ID Transaksi Tidak ada!, Anda ingin mencari lagi?","ATTENTION",MB_OKCANCEL |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        if(cancel == IDOK) {
            BlankDashboard();
            readAllDataTransaksiPembelianKendaraan();
            lihatDetailTransaksiPembersihanKendaraan();
        } else if (cancel == IDCANCEL){
            BlankDashboard();
            Dashboard();
        }
    }

    if(found == 1) {
        a = 1;
        y = 16;
        BlankDashboard();
        tampilanDetailTableTransaksiPembersihanKendaraan();
        /* buka file untuk dibaca */
        fileDTKendaraan = fopen("../TRANSAKSI/../Source/../Database/Dat/DETAILTRANSAKSIKENDARAAN.dat", "rb");
        fread(&dTKendaraan, sizeof(dTKendaraan), 1, fileDTKendaraan);
        while (fread(&dTKendaraan, sizeof(dTKendaraan), 1, fileDTKendaraan) == 1) {
            if (temptrsTKendaraan.id_TKendaraan == dTKendaraan.id_TKendaraan) { /* munculkan data yang id nya sesuai saja */
                if (a % 2 == 0) {
                    SetColorBlock(7, 1);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiPemesananKendaraan();
                } else {
                    SetColorBlock(15, 12);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiPemesananKendaraan();
                }
                batasTable();
                a++;
                y++;
            }
        }
        fclose(fileDTKendaraan);
    }
    SpecialKeyCariorBackDashboard(150, 40,10,9,7,&output);
    switch (output) {
        case 1 :
            SetColorBlock(1,7);
            readAllDataTransaksiPembelianKendaraan();
            lihatDetailTransaksiPembersihanKendaraan();
            break;

        case 2:
            BlankDashboard();
            Dashboard();
            break;
    }
}