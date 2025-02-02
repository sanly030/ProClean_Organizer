    void dataTransaksiPembelian(){
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(43, y);
    generateid("TRSPR",trsTRumah.id_TRumah);
    gotoxy(50, y);
    printf("PLG%03d", trsTRumah.id_plg);
    gotoxy(60, y);
    printf("JLY%03d", trsTRumah.id_jnslayanan);
        gotoxy(70, y);
        printf("PRM%03d\n", trsTRumah.id_promo);
    gotoxy(125, y);
    rupiah(trsTRumah.totalHarga,inputrp);
    printf("%s",inputrp);
}

void dataDetailTransaksiPemesanan(){
    gotoxy(38, y);
    printf("%d", a);
    gotoxy(43, y);
    generateid("TRSPR",dTRumah.id_TRumah);
    gotoxy(69, y);
    printf("%s\n", dTRumah.namaTRumah);
    gotoxy(100, y);
    printf("%.2f",dTRumah.totalHarga);
    gotoxy(128, y);
    rupiah(dTRumah.totalHarga,inputrp);
    printf("%s",inputrp);
}

void readAllDataTransaksiPembelian(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSPR");
    tampilanDetailTableTransaksiPembersihanRumah(); //ini harusnya pake yg sahar
    i = 1;
    y = 16;

        fileTransaksiRumah = fopen("../TRANSAKSI/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "rb+");
        while (fread(&trsTRumah, sizeof(trsTRumah), 1, fileTransaksiRumah) == 1 ) {
            if (i % 2 == 0) {
            SetColorBlock(7,1);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPembelian();
        } else {
            SetColorBlock(7,9);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPembelian();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(fileTransaksiRumah);
}

// void lihatDetailTransaksiPembelianOwner(){
//     boxSearch();
//     gotoprinttext(138,10,"CARI   : TRSBO");
//     gotoprinttext(152, 10, "       ");
//     gotoxy(152, 10);
//     showCursor();
//     getnum(&temptrsbo.id_transaksi, 3);
//     hideCursor();
//     arsdetailbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/detailpembelian.dat", "rb+");
//     fread(&dtbo,sizeof(dtbo),1,arsdetailbeliobat);
//     found = 0;
//     while(!feof(arsdetailbeliobat) && found==0){
//         if (temptrsbo.id_transaksi == dtbo.id_transaksi){ /* mengecek apakah id yang dicari ada dalam id transaksi */
//             found = 1;
//         }else {
//             fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat);
//         }
//     }
//     fclose(arsdetailbeliobat);
//     if(found == 0) {
//         cancel = MessageBoxA(NULL,"ID Transaksi Tidak ada!, Anda ingin mencari lagi?","ATTENTION",MB_OKCANCEL |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
//         if(cancel == IDOK) {
//             BlankDashboard();
//             readAllDataTransaksiPembelian();
//             lihatDetailTransaksiPembelianOwner();
//         } else if (cancel == IDCANCEL){
//             BlankDashboard();
//             dataTransaksiPembelianMenu();
//         }
//     }
//
//     if(found == 1) {
//         a = 1;
//         y = 16;
//         BlankDashboard();
//         tampilanDetailTableTransaksiPembelian();
//         /* buka file untuk dibaca */
//         arsdetailbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/detailpembelian.dat", "rb");
//         fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat);
//         while (fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat) == 1) {
//             if (temptrsbo.id_transaksi == dtbo.id_transaksi) { /* munculkan data yang id nya sesuai saja */
//                 if (a % 2 == 0) {
//                     SetColorBlock(15, 4);
//                     for (x = y; x <= y; x++) {
//                         for (j = 37; j < 167; j++) {
//                             gotoprintchar(j, x, 32);
//                         }
//                     }
//                     dataDetailTransaksiPembelian();
//                 } else {
//                     SetColorBlock(15, 12);
//                     for (x = y; x <= y; x++) {
//                         for (j = 37; j < 167; j++) {
//                             gotoprintchar(j, x, 32);
//                         }
//                     }
//                     dataDetailTransaksiPembelian();
//                 }
//                 batasTable();
//                 a++;
//                 y++;
//             }
//         }
//         fclose(arsdetailbeliobat);
//     }
//     SpecialKeyCariorBackDashboard(150, 40,10,12,15,&output);
//     switch (output) {
//         case 1 :
//             SetColorBlock(4,15);
//             readAllDataTransaksiPembelian();
//             lihatDetailTransaksiPembelianOwner();
//             break;
//
//         case 2:
//             BlankDashboard();
//             dataTransaksiPembelianMenu();
//             break;
//     }
//
// }


/*
void lihatDetailTransaksiPembelianAdmin(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSBO");
    gotoprinttext(152, 10, "       ");
    gotoxy(152, 10);
    showCursor();
    getnum(&temptrsmc.id_transaksi, 3);
    hideCursor();
    arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb+");
    fread(&dtmc,sizeof(dtmc),1,arsdetail);
    found = 0;
    while(!feof(arsdetail) && found==0){
        if (temptrsmc.id_transaksi == dtmc.id_transaksi){ /* mengecek apakah id yang dicari ada dalam id transaksi #1#
            found = 1;
        }else {
            fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        }
    }
    fclose(arsdetail);
    if(found == 0) {
        cancel = MessageBoxA(NULL,"ID Transaksi Tidak ada!, Anda ingin mencari lagi?","ATTENTION",MB_OKCANCEL |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        if(cancel == IDOK) {
            BlankDashboard();
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseAdmin();
        } else if (cancel == IDCANCEL){
            BlankDashboard();
            dataTransaksiMenuAdmin();
        }
    }

    if(found == 1) {
        a = 1;
        y = 16;
        BlankDashboard();
        tampilanDetailTableTransaksiMerchandise();
        /* buka file untuk dibaca #1#
        arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb");
        fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        while (fread(&dtmc, sizeof(dtmc), 1, arsdetail) == 1) {
            if (temptrsmc.id_transaksi == dtmc.id_transaksi) { /* munculkan data yang id nya sesuai saja #1#
                if (a % 2 == 0) {
                    SetColorBlock(7, 1);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                } else {
                    SetColorBlock(7, 9);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                }
                batasTable();
                a++;
                y++;
            }
        }
        fclose(arsdetail);
    }
    SpecialKeyCariorBackDashboard(150, 40,10,9,7,&output);
    switch (output) {
        case 1 :
            SetColorBlock(1,7);
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseAdmin();
            break;

        case 2:
            BlankDashboard();
            dataTransaksiMenuAdmin();
            break;
    }

}
*/
