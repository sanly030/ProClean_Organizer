#ifndef CREATEPELANGGAN_H
#define CREATEPELANGGAN_H

void CreatePelanggan() {
    do {
        SetColorBlock(1,7);
        textBox2(31,10,139,33);
        PrintFile("..//Asset//TambahData.txt",50,11);

        int lastPelanggan = 0;
        i = 0;

        lastPelanggan = 0;
        FILE *arsplg = fopen("../Database/Dat/PELANGGAN.dat", "rb"); // Buka file untuk membaca dan menulis

        while(fread(&plg,sizeof(plg),1,arsplg)) {
            if(plg.id_plg >= lastPelanggan) {
                lastPelanggan = plg.id_plg;
            }
        }
        lastPelanggan++;
        fclose(arsplg);

        arsplg = fopen("../Database/Dat/PELANGGAN.dat", "ab+"); // Buka file untuk membaca dan menulis
        plg.id_plg = lastPelanggan;

        // Buat ID Pelanggan secara otomatis
        textBox2(61,18,72,12);
        BoxBlock(63,19,70,10);
        SetColorBlock(7,1);
        gotoxy(65, 20);
        printf("I D  P E L A N G G A N         : PLG%03d\n", plg.id_plg); // Tampilkan ID pelanggan
        gotoprinttext(65,22,"N A M A  P E L A N G G A N     : ");
        gotoprinttext(65,24,"A L A M A T                    : ");
        gotoprinttext(65,26,"N O  T E L E P H O N E         : ");
        gotoprinttext(65,28,"J E N I S  K E L A M I N       : L/P");

        for ( i = 98; i <= 130 ; i++) {
            gotoprintchar(i,21,196);
        }
        for ( i = 98; i <= 130 ; i++) {
            gotoprintchar(i,23,196);
        }
        for ( i = 98; i <= 130 ; i++) {
            gotoprintchar(i,25,196);
        }
        for ( i = 98; i <= 130 ; i++) {
            gotoprintchar(i,27,196);
        }
        for ( i = 98; i <= 130 ; i++) {
            gotoprintchar(i,29,196);
        }

        // Validasi Nama Pelanggan
        gotoxy(98,22);
        getinput(plg.namaPlg,25,2);
        if(strcmpi(plg.namaPlg,"exit")==0) {
            blankScreen();
            MenuPelanggan();
        }

        // Validasi Alamat
        gotoxy(98,24);
        getinput(plg.almt,25,1);

        // Validasi No Telepon
        bool validNoTelp = false;
        do {
            gotoxy(98,26);
            // clearArea(98,26,13,1); // Bersihkan area input
            getinput(plg.no_telp,13,3);

            // Cek apakah nomor telepon dimulai dengan "08" dan memiliki panjang minimal 10 karakter
            if (strlen(plg.no_telp) >= 10 && strncmp(plg.no_telp, "08", 2) == 0) {
                validNoTelp = true;
            } else {
                gotoxy(75, 30);
                clearArea(98,26,12,1);
                SetColorBlock(4,7);
                MessageBox(NULL,"No Telepon harus dimulai dengan '08' dan minimal 10 digit!","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                SetColorBlock(7,1);
                gotoxy(75, 30);// Bersihkan pesan error
            }
        } while (!validNoTelp);

        // Validasi Jenis Kelamin
        bool validKelamin = false;
        do {
            gotoxy(98,28);
            clearArea(98,28,3,1); // Bersihkan area input
            getinput(plg.kelamin,2,2);

            // Cek apakah input adalah 'L' atau 'P' (tidak case-sensitive)
            if (strcmp(plg.kelamin, "L") == 0 || strcmp(plg.kelamin, "P") == 0 ||
                strcmp(plg.kelamin, "l") == 0 || strcmp(plg.kelamin, "p") == 0) {
                validKelamin = true;
            } else {
                gotoxy(75, 32);
                clearArea(98,28,3,1);
                SetColorBlock(4,7);
                MessageBox(NULL,"Jenis Kelamin harus 'L' atau 'P'!","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                SetColorBlock(7,1);
                gotoxy(75, 30);

                // Bersihkan pesan error
            }
        } while (!validKelamin);

        fwrite(&plg, sizeof(plg), 1, arsplg);
        fclose(arsplg);
        gotoxy(75, 35);
        SetColorBlock(1,7);
        printf("Data pelanggan berhasil ditambahkan.\n");
        SetColorBlock(7,1);
        textBox2(69,37,56,2);
        gotoxy(70, 38);
        printf("Apakah ingin menambah data pelanggan lagi (y/t) : ");
        gotoxy(124,38);
        getinput(&Opsi,1,2);

        blankScreen();
    } while(Opsi == 'y' || Opsi == 'Y');

    MenuPelanggan();
}
#endif //CREATEPELANGGAN_H