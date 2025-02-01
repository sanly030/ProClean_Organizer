void CreatePembayaran() {
    char pilihan;
    do {
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        textBox2(45,17,72,10);
        BoxBlock(47,18,70,8);
        SetColorBlock(7,1);

        // Buka file pembayaran untuk penambahan data
        FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "ab+");
        if (arspeb == NULL) {
            printf("File PEMBAYARAN.dat tidak dapat dibuka.\n");
            return;
        }

        pembayaran peb;

        // Generate ID Pembayaran baru
        int lastPembayaran = 0;
        FILE *arspeb_temp = fopen("../Database/Dat/PEMBAYARAN.dat", "rb");
        while (fread(&peb, sizeof(peb), 1, arspeb_temp)) {
            if (peb.id_pembayaran >= lastPembayaran) {
                lastPembayaran = peb.id_pembayaran;
            }
        }
        fclose(arspeb_temp);
        peb.id_pembayaran = lastPembayaran + 1;

        // Tampilkan dan input data pembayaran
        gotoxy(49, 21);
        printf("I D  P E M B A Y A R A N           : JPR%03d\n", peb.id_pembayaran);
        gotoprinttext(49, 23, "N A M A  P E M B A Y A R A N       : ");


        for (i = 86; i <= 115; i++) gotoprintchar(i, 22, 196);
        for (i = 86; i <= 115; i++) gotoprintchar(i, 24, 196);



        gotoxy(86, 23);
        getinput(peb.namaPembayaran, 24, 2);
        if(strcmpi(peb.namaPembayaran, "Exit") == 0) {
            blankScreen();
            MenuPembayaran();
        }

        // Simpan ke file
        fwrite(&peb, sizeof(peb), 1, arspeb);
        fclose(arspeb);

        gotoxy(80, 34);
        printf("Data pembayaran berhasil ditambahkan.\n");

        // Konfirmasi untuk menambah lagi
        textBox2(69, 37, 56, 2);
        gotoxy(72, 38);
        printf("Apakah ingin menambah data pembayaran lagi? (y/t): ");
        gotoxy(123,38);
        getinput(&pilihan,1,2);

        blankScreen();
    } while (pilihan == 'y' || pilihan == 'Y');

    MenuPembayaran();
}