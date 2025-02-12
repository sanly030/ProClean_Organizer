void CreatePelanggan();
void ReadPelanggan();
void UpdatePelanggan();
void DeletePelanggan();
void CreatePembayaran();
void ReadPembayaran();
void UpdatePembayaran();
void DeletePembayaran();
void CreateJenisKendaraan();
void ReadJenisKendaraan();
void UpdateJenisKendaraan();
void DeleteJenisKendaraan();
void createTransaksiObat();



void MenuPelanggan() {
    int pilihan;
    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    PrintFile("..//Asset//MenuData.txt",70, 19);


    do {
        PrintFile("..//Asset//MenuPelanggan.txt",40, 10);
        textBox2(64,24,20,2);
        gotoprinttext(68, 25,"1. Tambah Data");

        textBox2(93,24,21,2);
        gotoprinttext(97, 25,"2. Tampilkan Data");

        textBox2(64,28,20,2);
        gotoprinttext(69,29,"3. Ubah Data");

        textBox2(93,28,21,2);
        gotoprinttext(98,29,"4. Hapus Data");

        textBox2(78,31,21,2);
        gotoprinttext(84,32,"5. Keluar");

        // gotoprinttext(62,28,"5. Keluar Data");
        textBox2(78,35,20,2);
        gotoprinttext(81,36,"PILIH OPSI : [ ]");
        gotoxy(95, 36);
        getnum(&pilihan,1);

        switch (pilihan) {
            case 1:blankScreen();CreatePelanggan();break;
            case 2:blankScreen();ReadPelanggan();break;
            case 3:blankScreen();UpdatePelanggan();break;
            case 4:blankScreen();DeletePelanggan();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}


void MenuPembayaran() {
    int pilihan;
    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    PrintFile("..//Asset//MenuData.txt",70, 19);


    do {
        PrintFile("..//Asset//MenuPembayaran.txt",45, 10);
        textBox2(64,24,20,2);
        gotoprinttext(68, 25,"1. Tambah Data");

        textBox2(93,24,21,2);
        gotoprinttext(97, 25,"2. Tampilkan Data");

        textBox2(64,28,20,2);
        gotoprinttext(69,29,"3. Ubah Data");

        textBox2(93,28,21,2);
        gotoprinttext(98,29,"4. Hapus Data");

        textBox2(78,31,21,2);
        gotoprinttext(84,32,"5. Keluar");

        // gotoprinttext(62,28,"5. Keluar Data");
        textBox2(78,35,20,2);
        gotoprinttext(81,36,"PILIH OPSI : [ ]");
        gotoxy(95, 36);
        getnum(&pilihan,1);

        switch (pilihan) {
            case 1:blankScreen();CreatePembayaran();break;
            case 2:blankScreen();ReadPembayaran();break;
            case 3:blankScreen();UpdatePembayaran();break;
            case 4:blankScreen();DeletePembayaran();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}

void MenuJenisKendaraan() {
    int pilihan;
    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    PrintFile("..//Asset//MenuData.txt",70, 19);


    do {
        PrintFile("..//Asset//MenuKendaraan.txt",45, 10);
        textBox2(64,24,20,2);
        gotoprinttext(68, 25,"1. Tambah Data");

        textBox2(93,24,21,2);
        gotoprinttext(97, 25,"2. Tampilkan Data");

        textBox2(64,28,20,2);
        gotoprinttext(69,29,"3. Ubah Data");

        textBox2(93,28,21,2);
        gotoprinttext(98,29,"4. Hapus Data");

        textBox2(78,31,21,2);
        gotoprinttext(84,32,"5. Keluar");

        // gotoprinttext(62,28,"5. Keluar Data");
        textBox2(78,35,20,2);
        gotoprinttext(81,36,"PILIH OPSI : [ ]");
        gotoxy(95, 36);
        getnum(&pilihan,1);

        switch (pilihan) {
            case 1:blankScreen();CreateJenisKendaraan();break;
            case 2:blankScreen();ReadJenisKendaraan();break;
            case 3:blankScreen();UpdateJenisKendaraan();break;
            case 4:blankScreen();DeleteJenisKendaraan();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}

void MenuTransaksiRumah() {
    int pilihan;

    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    PrintFile("..//Asset//MenuData.txt",70, 19);


    do {
        PrintFile("..//Asset//MenuKendaraan.txt",45, 10);
        textBox2(64,24,20,2);
        gotoprinttext(68, 25,"1. Tambah Data");

        textBox2(93,24,21,2);
        gotoprinttext(97, 25,"2. Tampilkan Data");

        textBox2(64,28,20,2);
        gotoprinttext(69,29,"3. Ubah Data");

        textBox2(93,28,21,2);
        gotoprinttext(98,29,"4. Hapus Data");

        textBox2(78,31,21,2);
        gotoprinttext(84,32,"5. Keluar");

        // gotoprinttext(62,28,"5. Keluar Data");
        textBox2(78,35,20,2);
        gotoprinttext(81,36,"PILIH OPSI : [ ]");
        gotoxy(95, 36);
        getnum(&pilihan,1);

        switch (pilihan) {
            case 1:blankScreen();createTransaksiRumah();break;
            // case 2:blankScreen();ReadJenisKendaraan();break;
            case 3:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);
}