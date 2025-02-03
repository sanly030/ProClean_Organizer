void ceklaporanMerchandisetahun(){
    if (cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 1){ /* cek apakah dalam bulan yg dicari terdapat transaksi */
        jan = trsTRumah.totalHarga +jan;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 2){
        feb = trsTRumah.totalHarga +feb;
        found = 1;
    }
    else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 3){
        mar = trsTRumah.totalHarga +mar;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 4){
        apr = trsTRumah.totalHarga +apr;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 5){
        mei = trsTRumah.totalHarga +mei;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 6){
        jun = trsTRumah.totalHarga +jun;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 7){
        jul = trsTRumah.totalHarga +jul;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 8){
        aug = trsTRumah.totalHarga +aug;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 9){
        sep = trsTRumah.totalHarga +sep;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 10){
        okt = trsTRumah.totalHarga +okt;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 11){
        nov = trsTRumah.totalHarga +nov;
        found = 1;
    }else if(cektahun == trsTRumah.pemesanan.tahun && trsTRumah.pemesanan.bulan == 12){
        des = trsTRumah.totalHarga +des;
        found = 1;
    } else {
        found = 0;
    }
}

void dataLaporanTransaksiPembersihanRumah(){
    gotoxy(48, y);
    generateid("TRSPR",trsTRumah.id_TRumah);
    gotoxy(118, y);
    uangLaporan(trsTRumah.totalHarga,inputrp);
    aturkanankekiri(inputrp,118,y);
}
void laporanBulananMerchandise(){
    total = 0;
    found = 0;
    /* buka file transaksi untuk dibaca */
    fileDTRumah = fopen("../LAPORAN/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "rb");
    while(fread(&trsTRumah,sizeof(trsTRumah),1,fileDTRumah)){
        if(cektahun == trsTRumah.pemesanan.tahun && cekbulan == trsTRumah.pemesanan.bulan){
            total = total + trsTRumah.totalHarga;
            found = 1;
        }
    }
    fclose(fileDTRumah);

    if(found == 1) {
        i = 1;
        y = 23;
        fileDTRumah = fopen("../LAPORAN/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "rb+");
        while (fread(&trsTRumah, sizeof(trsTRumah), 1, fileDTRumah) == 1 ) {
            if(cektahun == trsTRumah.pemesanan.tahun && cekbulan == trsTRumah.pemesanan.bulan) {
                if (i % 2 == 0) {
                    SetColorBlock(9, 15);
                    dataLaporanTransaksiPembersihanRumah();
                    i++;
                    y++;
                } else {
                    SetColorBlock(9, 15);
                    dataLaporanTransaksiPembersihanRumah();
                    i++;
                    y++;
                }
            }
            batasTable();

        }
        fclose(fileDTRumah);
        convertBulan(cekbulan);
        SetColorBlock(1,15);
        gotoxy(58,18);
        printf("UNTUK PERIODE BULAN %s  TAHUN %d",namabulan,cektahun);
        uangLaporan(total,inputrp);
        aturkanankekiri(inputrp,118,37);
        gotoxy(40,37);
        printf("*Hanya Menampilkan 12 Data Transaksi Awal!");
    }else{
        MessageBox(NULL,"Tidak ada Transaksi Dibulan Tersebut","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
    }
    fclose(fileDTRumah);
}
void laporanTahunanMerchandise(){
    jan = 0; feb = 0; mar = 0; apr =0; mei =0; jun =0; jul=0; aug=0;sep=0;okt=0;nov=0;des=0;
    /* buka file transaksi untuk dibaca */
    fileDTRumah = fopen("../LAPORAN/../Source/../Database/Dat/TRANSAKSIPEMBERSIHANRUMAH.dat", "rb");
    while(fread(&trsTRumah,sizeof(trsTRumah),1,fileDTRumah)){
        ceklaporanMerchandisetahun();
    }
    if(found == 1) {
        SetColorBlock(1,15);
        gotoxy(95,18);
        printf("%d",trsTRumah.pemesanan.tahun);
        SetColorBlock(9,15);
        uangLaporan(jan,inputrp);
        aturkanankekiri(inputrp,118,23);
        uangLaporan(feb,inputrp);
        aturkanankekiri(inputrp,118,24);
        uangLaporan(mar,inputrp);
        aturkanankekiri(inputrp,118,25);
        uangLaporan(apr,inputrp);
        aturkanankekiri(inputrp,118,26);
        uangLaporan(mei,inputrp);
        aturkanankekiri(inputrp,118,27);
        uangLaporan(jun,inputrp);
        aturkanankekiri(inputrp,118,28);
        uangLaporan(jul,inputrp);
        aturkanankekiri(inputrp,118,29);
        uangLaporan(aug,inputrp);
        aturkanankekiri(inputrp,118,30);
        uangLaporan(sep,inputrp);
        aturkanankekiri(inputrp,118,31);
        uangLaporan(okt,inputrp);
        aturkanankekiri(inputrp,118,32);
        uangLaporan(nov,inputrp);
        aturkanankekiri(inputrp,118,33);
        uangLaporan(des,inputrp);
        aturkanankekiri(inputrp,118,34);
        total = jan + feb + mar + apr + mei + jun +jul+ aug+sep+okt+nov+des;
        uangLaporan(total,inputrp);
        aturkanankekiri(inputrp,118,37);
    }else{
        MessageBox(NULL,"Tidak ada Transaksi Ditahun Tersebut","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
    }
    fclose(fileDTRumah);
}

void laporanKeuanganMerchandise() {
    BlankDashboard();
    SetColorBlock(1, 7);
    //DrawFile(39, 9, "../TRANSAKSI BIOSKOP/../Source/../Desaintxt/Dashboard/laporanKeuangan.txt");
    //DrawFile(130, 16, "../TRANSAKSI BIOSKOP/../Source/../Desaintxt/elemen/merchandise.txt");
    SetColorBlock(9, 9);
    frameLayout(60, 18, 120, 34, 32);
    SetColorBlock(7, 1);
    frameLayout(60, 18, 120, 19, 220);
    frameLayout(60, 18, 61, 34, 220);
    frameLayout(60, 34, 120, 35, 223);
    frameLayout(119, 18, 120, 34, 220);
    SetColorBlock(7, 9);
    SpecialkeyLaporanManajer(79, 24, 20, 3, &output);
    switch (output) {
        case 1:
            BlankDashboard();
            do {
                DashboardCRUD();
                lembarLaporanBulanan();
                menuBackLihat(32);
                showCursor();
                SetColorBlock(7,9);
                gotoxy(135,25);
                getnum(&cekbulan,2);
                gotoxy(135,29);
                getnum(&cektahun,4);
                hideCursor();
                SpecialKeyCariDataLaporan(150, 31, 15, 3, &output);
                switch (output) {
                    case 1:
                        laporanBulananMerchandise();
                        break;
                    case 2:
                        laporanKeuanganMerchandise();
                        break;
                }
                gotoxy(139, 35);
                SetColorBlock(7,9);
                printf("Anda Ingin Melihat Lagi?");
                SpecialKeyYesorNoDashboard(154, 37, 10, 7, 9, &output);
                switch (output) {
                    case 1:
                        found = 1;
                        break;
                    case 2:
                        found = 0;
                        break;
                }
            }while(found == 1);
            if(found == 0){
                BlankDashboard();
                laporanKeuanganMerchandise();
            }
            break;
        case 2:
            BlankDashboard();
            do {
                DashboardCRUD();
                lembarLaporanTahunan();
                menuBackLihat(30);
                showCursor();
                SetColorBlock(7,9);
                gotoxy(135,27);getnum(&cektahun,4);
                hideCursor();
                SpecialKeyCariDataLaporan(150, 29, 15, 3, &output);
                switch (output) {
                    case 1:
                        laporanTahunanMerchandise();
                        break;
                    case 2:
                        laporanKeuanganMerchandise();
                        break;
                }
                gotoxy(139, 35);
                SetColorBlock(7,9);
                printf("Anda Ingin Melihat Lagi?");
                SpecialKeyYesorNoDashboard(154, 37, 10, 7, 9, &output);
                switch (output) {
                    case 1:
                        found = 1;
                        break;
                    case 2:
                        found = 0;
                        break;
                }
            }while(found == 1);
            if(found == 0){
                BlankDashboard();
                laporanKeuanganMerchandise();
            }
            break;
        case 3:
            BlankDashboard();
            Dashboard();
            break;
    }
}