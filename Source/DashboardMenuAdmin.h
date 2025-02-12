void CreatePetugas();
void ReadPetugas();
void UpdatePetugas();
void DeletePetugas();
void CreateJenisPetugas();
void ReadJenisPetugas();
void UpdateJenisPetugas();
void DeleteJenisPetugas();
void CreateLayanan();
void ReadLayanan();
void UpdateLayanan();
void DeleteLayanan();
void CreateJnsLayanan();
void ReadJnsLayanan();
void UpdateJnsLayanan();
void DeleteJnsLayanan();
// void CreatePktLayanan();
// void ReadPktLayanan();
// void UpdatePktLayanan();
// void DeletePktLayanan();
void CreateJenisPktLayanan();


void DashboardMenuAdmin() {
    int pilihan;


        do {
            gotoprinttext(50,15,"Menu");
            gotoprinttext(50, 17,"1. Tambah Data");
            gotoprinttext(50, 19,"2. Tampilkan Data");
            gotoprinttext(50,21,"3. Ubah Data");
            gotoprinttext(50,23,"4. Hapus Data");
            gotoprinttext(50,25,"5. Keluar Data");
            gotoprinttext(50,28,"Pilih opsi : ");
            gotoxy(50, 28);
            scanf("%d", &pilihan);

            getchar(); // Bersihkan buffer

            switch (pilihan) {
                case 1:CreatePetugas();break;
                case 2:ReadPetugas();break;
                case 3:UpdatePetugas();break;
                case 4:DeletePetugas();break;
                case 5:printf("Keluar program.\n");
                    // MenuAdmin();
                    exit(0);
                break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        } while (pilihan != 5);
    }


void MenuJenisPetugas() {
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
    PrintFile("..//Asset//MenuJenisPetugas.txt",41, 10);
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
            case 1:blankScreen();CreateJenisPetugas();break;
            case 2:blankScreen();ReadJenisPetugas();break;
            case 3:blankScreen();UpdateJenisPetugas();break;
            case 4:blankScreen();DeleteJenisPetugas();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}

void MenuPetugas() {
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
        PrintFile("..//Asset//MenuPetugas.txt",55, 10);
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
            case 1:blankScreen();CreatePetugas();break;
            case 2:blankScreen();ReadPetugas();break;
            case 3:blankScreen();UpdatePetugas();break;
            case 4:blankScreen();DeletePetugas();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}

void MenuLayanan() {
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
        PrintFile("..//Asset//MenuLayanan.txt",55, 10);
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
            case 1:blankScreen();CreateLayanan();break;
            case 2:blankScreen();ReadLayanan();break;
            case 3:blankScreen();UpdateLayanan();break;
            case 4:blankScreen();DeleteLayanan();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}


void MenuJnsLayanan () {
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
        PrintFile("..//Asset//MenuJenisLayanan.txt",40, 10);
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
            case 1:blankScreen();CreateJnsLayanan();break;
            case 2:blankScreen();ReadJnsLayanan();break;
            case 3:blankScreen();UpdateJnsLayanan();break;
            case 4:blankScreen();DeleteJnsLayanan();break;
            case 5:blankScreen();Dashboard();
            exit(0);
            default:
                gotoprinttext(80,38,"Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}







