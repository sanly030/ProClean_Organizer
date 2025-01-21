void CreatePetugas();
void ReadPetugas();
void UpdatePetugas();
void DeletePetugas();
void CreateJenisPetugas();
void ReadJenisPetugas();
void UpdateJenisPetugas();
void DeleteJenisPetugas();

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
    PrintFile("..//Asset//MenuJenisPetugas.txt",41, 10);
    SetColorBlock(1,7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    PrintFile("..//Asset//MenuData.txt",70, 19);


    do {
        textBox2(64,24,20,2);
        gotoprinttext(68, 25,"1. Tambah Data");

        textBox2(93,24,21,2);
        gotoprinttext(97, 25,"2. Tampilkan Data");

        textBox2(64,28,20,2);
        gotoprinttext(69,29,"3. Ubah Data");

        textBox2(93,28,21,2);
        gotoprinttext(98,29
            ,"4. Hapus Data");

        // gotoprinttext(62,28,"5. Keluar Data");
        textBox2(78,33,20,2);
        gotoprinttext(81,34,"PILIH OPSI : [ ]");
        gotoxy(95, 34);
        scanf("%d", &pilihan);
        getchar(); // Bersihkan buffer

        switch (pilihan) {
            case 1:blankScreen();CreateJenisPetugas();break;
            case 2:ReadJenisPetugas();break;
            case 3:UpdateJenisPetugas();break;
            case 4:DeleteJenisPetugas();break;
            case 5:printf("Keluar program.\n");
            exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}








