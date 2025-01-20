// static int lastpetugas = 0;
// void CreatePetugas() {
//     fflush(stdin);
//     int role_choice; // Variabel untuk menyimpan pilihan role
//     i = 0;
//
//     FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb"); // Buka file untuk membaca
//     petugas pgs;
//
//     // Cari ID terakhir untuk increment ID baru
//     while (fread(&pgs, sizeof(petugas), 1, arspgs)) {
//         if (pgs.id_petugas >= lastpetugas) {
//             lastpetugas = pgs.id_petugas;
//         }
//     }
//     lastpetugas++;
//     fclose(arspgs);
//
//     arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "ab"); // Buka file untuk append
//     pgs.id_petugas = lastpetugas;
//
//     // Masukkan data lainnya
//     gotoxy(65, 15);
//     printf("-----------------------------------");
//     gotoprinttext(65, 16, "T A M B A H  D A T A  P E T U G A S");
//     gotoxy(65, 17);
//     printf("-----------------------------------");
//
//     gotoxy(65, 19);
//     printf("ID Petugas: PGS%03d", pgs.id_petugas);
//
//     // Pilihan Role
//     textBox2(120, 20, 30, 7);
//     gotoxy(122, 21);
//     printf(" Jenis Petugas:");
//     gotoxy(122, 23);
//     printf("1. Owner");
//     gotoxy(122, 24);
//     printf("2. Kasir");
//     gotoxy(122, 25);
//     printf("3. Petugas Kebersihan");
//
//     gotoxy(65, 22);
//     printf("Masukkan Jenis Petugas [1-3]: ");
//     gotoxy(94, 22);
//     scanf("%d", &role_choice);
//
//     // Validasi input role
//
//     gotoxy(65, 22);
//     printf("Masukkan Jenis Petugas [1-3]: ");
//     gotoxy(94, 22);
//     scanf("%d", &role_choice);
//
//     // Bersihkan buffer untuk mencegah konflik input berikutnya
//     while (getchar() != '\n');
//
//     // Validasi input role
//     while (role_choice < 1 || role_choice > 3) {
//         gotoxy(65, 24); // Tempatkan pesan error di lokasi yang jelas
//         printf("Pilihan tidak valid. Silakan pilih lagi [1-3]: ");
//         gotoxy(94, 24);
//         scanf("%d", &role_choice);
//         while (getchar() != '\n'); // Bersihkan buffer
//     }
//
//
//     // Pindah ke bagian input data lainnya
//     gotoxy(65, 26);
//     printf("Masukkan Nama Petugas: ");
//     scanf(" %[^\n]", pgs.nama);
//     gotoxy(65, 28);
//     printf("Masukkan Alamat Petugas: ");
//     scanf(" %[^\n]", pgs.alamat);
//     gotoxy(65, 30);
//     printf("Masukkan No. Telepon Petugas: ");
//     scanf(" %[^\n]", pgs.no_telp);
//     gotoxy(65, 32);
//     printf("Masukkan Status Petugas (Aktif/Nonaktif): ");
//     scanf(" %[^\n]", pgs.status);
//
//     // Hanya untuk Owner dan Kasir, minta Username dan Password
//     if (strcmp(pgs.role, "Owner") == 0 || strcmp(pgs.role, "Kasir") == 0) {
//         gotoxy(65, 34);
//         printf("Masukkan Username Petugas: ");
//         scanf(" %[^\n]", pgs.username);
//         gotoxy(65, 36);
//         printf("Masukkan Password Petugas: ");
//         scanf(" %[^\n]", pgs.password);
//     } else {
//         // Kosongkan username dan password jika role adalah Petugas Kebersihan
//         strcpy(pgs.username, "-");
//         strcpy(pgs.password, "-");
//     }
//
//     // Simpan data ke file
//     fseek(arspgs, 0, SEEK_END);
//     fwrite(&pgs, sizeof(petugas), 1, arspgs);
//     fclose(arspgs);
//
//     // Tampilkan pesan sukses
//     gotoxy(65, 38);
//     printf("Data petugas berhasil ditambahkan dengan ID: PGS%03d.\n", pgs.id_petugas);
//     getch();
//     MenuAdmin();
// }


static int lastpetugas = 0;

void CreatePetugas() {
    clearArea(30,10,140,31);
    fflush(stdin);
    int role_choice; // Variabel untuk menyimpan pilihan role
    i = 0;

    FILE *arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "rb"); // Buka file untuk membaca
    petugas pgs;

    // Cari ID terakhir untuk increment ID baru
    while (fread(&pgs, sizeof(petugas), 1, arspgs)) {
        if (pgs.id_petugas >= lastpetugas) {
            lastpetugas = pgs.id_petugas;
        }
    }
    lastpetugas++;
    fclose(arspgs);

    arspgs = fopen("../Database/Dat/DATA PETUGAS.dat", "ab"); // Buka file untuk append
    pgs.id_petugas = lastpetugas;

    // Masukkan data lainnya
    gotoxy(65, 15);
    printf("-----------------------------------");
    gotoprinttext(65, 16, "T A M B A H  D A T A  P E T U G A S");
    gotoxy(65, 17);
    printf("-----------------------------------");

    gotoxy(65, 19);
    printf("ID Petugas: PGS%03d", pgs.id_petugas);

    // Pilihaz
    gotoxy(122, 21);
    printf(" Jenis Petugas:");
    gotoxy(122, 23);
    printf("1. Owner");
    gotoxy(122, 24);
    printf("2. Kasir");
    gotoxy(122, 25);
    printf("3. Petugas Kebersihan");


    gotoxy(65, 22);
    printf("Masukkan Jenis Petugas[1-3]: ");
    gotoxy(94, 22);
    scanf("%d", &role_choice);


    // Validasi input role
    while (role_choice < 1 || role_choice > 3) {
        gotoxy(65, 29);
        printf("Pilihan tidak valid. Silakan pilih lagi [1-3]: ");
        scanf("%d", &role_choice);
    }

    // Tentukan role berdasarkan pilihan
    switch (role_choice) {
        case 1:
            strcpy(pgs.role, "Owner");
            break;
        case 2:
            strcpy(pgs.role, "Kasir");
            break;
        case 3:
            strcpy(pgs.role, "Petugas Kebersihan");
            break;
    }

    // Masukkan data lainnya
    gotoxy(65, 24);
    printf("ID Petugas                    : PGS%03d\n", pgs.id_petugas);
    gotoxy(65, 26);
    printf("Masukkan Nama Petugas: ");
    scanf(" %[^\n]", pgs.nama);
    gotoxy(65, 28);
    printf("Masukkan Alamat Petugas: ");
    scanf(" %[^\n]", pgs.alamat);
    gotoxy(65, 30);
    printf("Masukkan No. Telepon Petugas: ");
    scanf(" %[^\n]", pgs.no_telp);
    gotoxy(65, 32);
    printf("Masukkan Status Petugas (Aktif/Nonaktif): ");
    scanf(" %[^\n]", pgs.status);

    // Hanya untuk Owner dan Kasir, minta Username dan Password
    if (strcmp(pgs.role, "Owner") == 0 || strcmp(pgs.role, "Kasir") == 0) {
        gotoxy(65, 34);
        printf("Masukkan Username Petugas: ");
        scanf(" %[^\n]", pgs.username);
        gotoxy(65, 36);
        printf("Masukkan Password Petugas: ");
        scanf(" %[^\n]", pgs.password);
    } else {
        // Kosongkan username dan password jika role adalah Petugas Kebersihan
        strcpy(pgs.username, "-");
        strcpy(pgs.password, "-");
    }

    // Simpan data ke file
    fseek(arspgs, 0, SEEK_END);
    fwrite(&pgs, sizeof(petugas), 1, arspgs);
    fclose(arspgs);

    // Tampilkan pesan sukses
    gotoxy(65, 43);
    printf("Data petugas berhasil ditambahkan dengan ID: PGS%03d.\n", pgs.id_petugas);
    getch();
    DashboardMenuAdmin();
}

