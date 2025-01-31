#ifndef CREATEJNSLAYANAN_H
#define CREATEJNSLAYANAN_H


jnslayanan jly;
tabelDetailJenisPkt tdj;

void CreateJnsLayanan() {
    char Opsi;
    do {
        blankScreen();
        SetColorBlock(1, 7);
        textBox2(31, 10, 139, 33);
        PrintFile("..//Asset//TambahData.txt", 50, 11);

        // Membaca daftar layanan
        FILE *arslyn = fopen("../Database/Dat/LAYANAN.dat", "rb");
        if (arslyn == NULL) {
            printf("File LAYANAN.dat tidak dapat dibuka.\n");
            return;
        }

        layanan lyn[20];
        int jumlahLayanan = 0, i = 0;

        textBox2(130, 17, 39, 18);
        BoxBlock(131, 18, 38, 17);
        SetColorBlock(7, 1);
        gotoprinttext(137, 19, "D A F T A R  L A Y A N A N");

        while (fread(&lyn[i], sizeof(layanan), 1, arslyn)) {
            gotoxy(132, 20 + (i + 1));
            printf("[ %d ] %s", lyn[i].id_layanan, lyn[i].jnslayanan);
            i++;
        }
        fclose(arslyn);
        jumlahLayanan = i;

        // Generate ID Jenis Layanan baru
        int lastJnsLayanan = 0;
        FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
        while (fread(&jly, sizeof(jnslayanan), 1, arsjly)) {
            if (jly.id_jnslayanan >= lastJnsLayanan) {
                lastJnsLayanan = jly.id_jnslayanan;
            }
        }
        lastJnsLayanan++;
        fclose(arsjly);
        jly.id_jnslayanan = lastJnsLayanan;

        // Input jenis layanan
        SetColorBlock(1, 7);
        textBox2(41, 18, 72, 20);
        BoxBlock(43, 19, 70, 18);
        SetColorBlock(7, 1);

        gotoxy(45, 20);
        printf("I D  J E N I S  L A Y A N A N         : JLY%03d\n", jly.id_jnslayanan);
        gotoprinttext(45, 22, "J E N I S  P A K E T                  : ");
        gotoprinttext(45, 24, "H A R G A                             : Rp. ");
        gotoprinttext(45, 26, "D U R A S I                           :     Menit");

        for ( i = 85; i <= 110 ; i++) {
            gotoprintchar(i,23,196);
        }
        for ( i = 85; i <= 110 ; i++) {
            gotoprintchar(i,25,196);
        }
        for ( i = 85; i <= 110 ; i++) {
            gotoprintchar(i,27,196);
        }

        gotoxy(85, 22);
        getinput(jly.jenispaket, 25, 2);

        gotoxy(90, 24);
        getRp(&jly.harga, 4, 6, 88, 24);

        gotoxy(85, 26);
        getnum(&jly.durasi, 3);

        // Simpan ke file JENISLAYANAN.dat
        FILE *fileJns = fopen("../Database/Dat/JENISLAYANAN.dat", "ab");
        if (fileJns == NULL) {
            printf("Gagal membuka file JENISLAYANAN.dat\n");
            return;
        }
        fwrite(&jly, sizeof(jnslayanan), 1, fileJns);
        fclose(fileJns);

        // Pilih layanan yang terkait dengan jenis layanan ini
        int pilihan;
        FILE *fileDetail = fopen("../Database/Dat/DETAILJENISPAKET.dat", "ab");
        if (fileDetail == NULL) {
            printf("Gagal membuka file DETAILJENISPAKET.dat\n");
            return;
        }

        for (int j = 0; j < 3; j++) {
            gotoxy(45, 30 + (j * 2));
            printf("L A Y A N A N K E - %d                 : ", j + 1);
            for ( i = 85; i <= 110 ; i++) {
                gotoprintchar(i,31 + (j * 2),196);
            }
            gotoxy(85, 30 + (j * 2));
            getnum(&pilihan,2);

            // Validasi apakah ID layanan ada dalam daftar
            int valid = 0;
            for (int k = 0; k < jumlahLayanan; k++) {
                if (lyn[k].id_layanan == pilihan) {
                    valid = 1;
                    break;
                }
            }
            if (!valid) {
                printf("ID layanan tidak valid! Coba lagi.\n");
                j--; // Meminta input ulang
                continue;
            }

            // Simpan ke tabel detail
            tdj.id_jnslayanan = jly.id_jnslayanan;
            tdj.id_layanan = pilihan;
            fwrite(&tdj, sizeof(tabelDetailJenisPkt), 1, fileDetail);
        }
        fclose(fileDetail);

        // Konfirmasi sukses
        gotoxy(50, 37);
        printf("Data jenis layanan dan detail berhasil disimpan!\n");

        // Opsi untuk menambahkan lagi
        textBox2(69, 40, 56, 2);
        gotoxy(81, 41);
        printf("Tambah jenis layanan lagi? (y/t) : ");
        gotoxy(116, 41);
        getinput(&Opsi, 1, 2);

        blankScreen();
    } while (Opsi == 'y' || Opsi == 'Y');

    MenuJnsLayanan();
}

#endif //CREATEJNSLAYANAN_H
