void createTransaksiPenjadwalan();

void TambahTransaksiPenjadwalan() {
        found = 0;
        i = 0;
        total = 0;

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
        printf("I D  P E N J A D W A L A N :");
        gotoxy(70, 12);
        generateid("TRSPJ",trsTRumah.id_TRumah);
        fclose(fileTransaksiRumah);
}

void createTransaksiPenjadwalan() {
        frameTransaksi(42, 12);
        SetColorBlock(1,7);

        fclose(fileTransaksiRumah);
}