void CreatePembayaran() {
    char pilihan;
    do {
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        // Menampilkan daftar pelanggan
        FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
        if (arsplg == NULL) {
            printf("File PELANGGAN.dat tidak dapat dibuka.\n");
            return;
        }

        pelanggan plg;
        int i = 1;
        textBox2(130,17,38,7);
        gotoprinttext(140,18, "Daftar Pelanggan:");
        while (fread(&plg, sizeof(plg), 1, arsplg)) {
            gotoxy(122, 19 + i);
            printf("%d %s ", plg.id_plg, plg.namaPlg);
            i++;
        }
        fclose(arsplg);

        // Input dan validasi ID pelanggan
        int id_plg;
        textBox2(45,17,72,7);
        BoxBlock(47,18,70,5);
        SetColorBlock(7,1);
        gotoprinttext(49, 18, "Masukkan ID Pelanggan yang dipilih : ");
        for (i = 86; i <= 107; i++) gotoprintchar(i, 20, 196);
        gotoxy(86, 16 + i + 1);
        getnum(&id_plg,1);

        // Validasi ID Pelanggan
        arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb");
        int valid = 0;
        while (fread(&plg, sizeof(plg), 1, arsplg)) {
            if (plg.id_plg == id_plg) {
                valid = 1;
                break;
            }
        }
        fclose(arsplg);

        if (!valid) {
            MessageBox(NULL, "ID Pelanggan tidak valid.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            continue;
        }

        // Buka file pembayaran untuk penambahan data
        FILE *arspeb = fopen("../Database/Dat/PEMBAYARAN.dat", "ab+");
        if (arspeb == NULL) {
            printf("File PEMBAYARAN.dat tidak dapat dibuka.\n");
            return;
        }

        pembayaran peb;
        peb.id_plg = id_plg;

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
        gotoxy(45, 20);
        printf("I D  P E M B A Y A R A N               : JPR%03d\n", peb.id_pembayaran);
        gotoprinttext(45, 22, "N A M A  P E M B A Y A R A N         : ");
        gotoxy(86, 22);
        getinput(peb.namaPembayaran, 25, 2);
        gotoprinttext(45, 24, "S T A T U S                        : ");
        gotoxy(86, 24);
        getinput(peb.status, 25, 2);

        // Simpan ke file
        fwrite(&peb, sizeof(peb), 1, arspeb);
        fclose(arspeb);

        gotoxy(65, 34);
        printf("Data pembayaran berhasil ditambahkan.\n");

        // Konfirmasi untuk menambah lagi
        textBox2(69, 37, 56, 2);
        gotoxy(70, 38);
        printf("Apakah ingin menambah data pembayaran lagi? (y/t): ");
        gotoxy(118,38);
        getinput(&pilihan,1,2);

        blankScreen();
    } while (pilihan == 'y' || pilihan == 'Y');

    MenuPembayaran();
}