#ifndef CREATEPROMO_H
#define CREATEPROMO_H

promo prm;

void CreatePromo() {
    char Opsi;
    do {
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt", 53, 11);

        int lastPromo = 0, i = 0;

        // Membaca ID terakhir dari file PROMO.dat
        FILE *arsprm = fopen("../Database/Dat/PROMO.dat", "rb");
        if (arsprm) {
            while (fread(&prm, sizeof(promo), 1, arsprm)) {
                if (prm.id_promo >= lastPromo) {
                    lastPromo = prm.id_promo;
                }
            }
            fclose(arsprm);
        }
        lastPromo++;
        prm.id_promo = lastPromo;

        // Membuka file dalam mode append untuk menambahkan data baru
        arsprm = fopen("../Database/Dat/PROMO.dat", "ab+");
        if (!arsprm) {
            MessageBox(NULL, "File PROMO.dat tidak dapat dibuka!", "ERROR!", MB_OK | MB_ICONERROR);
            return;
        }

        // Menampilkan input ID Promo
        textBox2(61, 18, 72, 12);
        BoxBlock(63, 19, 70, 10);
        SetColorBlock(7, 1);
        gotoxy(65, 20);
        printf("I D  P R O M O                       :  PRM%03d\n", prm.id_promo);
        for (i = 105; i <= 130; i++) gotoprintchar(i, 21, 196);

        // Input Nama Promo
        gotoprinttext(65, 22, "N A M A  P R O M O                   : ");
        gotoprinttext(65, 24, "P O T O N G A N  H A R G A           :    %");
        gotoprinttext(65, 26, "T A N G G A L  M U L A I             :  DD/MM/YYYY");
        gotoprinttext(65, 28, "T A N G G A L  S E L E S A I         :  DD/MM/YYYY");

        for (i = 105; i <= 130; i++) gotoprintchar(i, 23, 196);
        for (i = 105; i <= 130; i++) gotoprintchar(i, 25, 196);
        for (i = 105; i <= 130; i++) gotoprintchar(i, 27, 196);
        for (i = 105; i <= 130; i++) gotoprintchar(i, 29, 196);

        gotoxy(105, 22);
        getinput(prm.namaPromo, 25, 2);
        if(strcmpi(prm.namaPromo, "exit") == 0) {
            blankScreen();
            MenuPromo();
        }

        // Input Potongan Harga
        gotoxy(105, 24);
        scanf("%f", &prm.potongan);

        // Input Tanggal Mulai

        gotoxy(105, 26);
        getnum(&prm.mulai.hari, 2);
        gotoxy(108, 26);
        getnum(&prm.mulai.bulan, 2);
        gotoxy(111, 26);
        getnum(&prm.mulai.tahun, 4);

        // Input Tanggal Selesai
        gotoxy(105, 28);
        getnum(&prm.selesai.hari, 2);
        gotoxy(108, 28);
        getnum(&prm.selesai.bulan, 2);
        gotoxy(111, 28);
        getnum(&prm.selesai.tahun, 4);

        // Menyimpan data ke file PROMO.dat
        fwrite(&prm, sizeof(promo), 1, arsprm);
        fclose(arsprm);

        // Konfirmasi penyimpanan
        gotoxy(80, 35);
        SetColorBlock(1, 7);
        printf("Data promo berhasil ditambahkan.\n");
        SetColorBlock(7, 1);

        // Opsi tambah data lagi
        textBox2(69, 37, 56, 2);
        gotoxy(76, 38);
        printf("Apakah ingin menambah promo lagi (y/t) : ");
        gotoxy(117, 38);
        getinput(&Opsi, 1, 2);

        blankScreen();
    } while (Opsi == 'y' || Opsi == 'Y');

    MenuPromo();
}

#endif // CREATEPROMO_H
