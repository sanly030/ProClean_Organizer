void CreatePetugas();
void ReadPetugas();
void UpdatePetugas();
void DeletePetugas();
void CreateJenisPetugas();
void ReadJenisPetugas();
void UpdateJenisPetugas();
void DeleteJenisPetugas();

void MenuAdmin() {
        int pilihan;
        system("cls");
        system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(151,2,8);
    garisFullBlokVertical(47,2,42);
    garisFullBlokHorizontal(3,9,171);
    PrintFile("..//Asset//Menu Petugas.txt", 55, 2);

        do {
            gotoprinttext(20,15,"Menu");
            gotoprinttext(15, 17,"1. Tambah Data");
            gotoprinttext(15, 19,"2. Tampilkan Data");
            gotoprinttext(15,21,"3. Ubah Data");
            gotoprinttext(15,23,"4. Hapus Data");
            gotoprinttext(15,25,"5. Keluar Data");
            gotoprinttext(15,28,"Pilih opsi : ");
            gotoxy(28, 28);
            scanf("%d", &pilihan);
            getchar(); // Bersihkan buffer

            switch (pilihan) {
                case 1:
                    CreatePetugas();
                break;
                case 2:
                    ReadPetugas();
                break;
                case 3:
                    UpdatePetugas();
                break;
                case 4:
                    DeletePetugas();
                break;
                case 5:
                    printf("Keluar program.\n");
                    // MenuAdmin();
                    // exit(0)
                Dashboard();
                break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        } while (pilihan != 5);
    }


void MenuJenisPetugas() {
    int pilihan;
    system("cls");
    system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(151,2,8);
    garisFullBlokVertical(47,2,42);
    garisFullBlokHorizontal(3,9,171);
    PrintFile("..//Asset//Menu Petugas.txt", 55, 2);

    do {
        gotoprinttext(20,15,"Menu");
        gotoprinttext(15, 17,"1. Tambah Data");
        gotoprinttext(15, 19,"2. Tampilkan Data");
        gotoprinttext(15,21,"3. Ubah Data");
        gotoprinttext(15,23,"4. Hapus Data");
        gotoprinttext(15,25,"5. Keluar Data");
        gotoprinttext(15,28,"Pilih opsi : ");
        gotoxy(28, 28);
        scanf("%d", &pilihan);
        getchar(); // Bersihkan buffer

        switch (pilihan) {
            case 1:
                CreateJenisPetugas();
            break;
            case 2:
                ReadJenisPetugas();
            break;
            // case 3:
            //     UpdateJenisPetugas();
            // break;
            // case 4:
            //     DeleteJenisPetugas();
            // break;
            case 5:
                printf("Keluar program.\n");
            // MenuAdmin();
            exit(0);
            break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}








