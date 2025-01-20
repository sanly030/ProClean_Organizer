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

    // PrintFile("..//Asset//Admin.txt", 7, 2);
    // PrintFile("..//Asset//Menu Petugas.txt", 55, 2);


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
    clearArea(30,10,140,31);

    // system("cls");
    // system("color 71");
    //
    // PrintFile("..//Asset//Admin.txt", 7, 2);
    // borderAwal();
    // garisFullBlokVertical(151,2,8);
    // garisFullBlokVertical(47,2,42);
    // garisFullBlokHorizontal(3,9,171);
    // PrintFile("..//Asset//Menu Petugas.txt", 55, 2);

    do {

        gotoprinttext(50,15,"Menu");
        gotoprinttext(50, 17,"1. Tambah Data");
        gotoprinttext(50, 19,"2. Tampilkan Data");
        gotoprinttext(50,21,"3. Ubah Data");
        gotoprinttext(50,23,"4. Hapus Data");
        gotoprinttext(50,25,"5. Keluar Data");
        gotoprinttext(50,28,"Pilih opsi : ");
        gotoxy(63, 28);
        scanf("%d", &pilihan);
        getchar(); // Bersihkan buffer

        switch (pilihan) {
            case 1:CreateJenisPetugas();break;
            case 2:ReadJenisPetugas();break;
            case 3:UpdateJenisPetugas();break;
            case 4:DeleteJenisPetugas();break;
            case 5:printf("Keluar program.\n");
            exit(0);
            break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}








