
#include "../../../Interface/lib.h"

void TextBoxUpdatePetugasByRole(char id_petugas[]);
// void ReadUpdatePetugasByRole(int role);
void UpdatePetugas() {

    int role; // Variabel untuk menyimpan pilihan role

    blankScreen();
    SetColorBlock(1, 7);
    frameLayout(60,18,120,40,32);
    SetColorBlock(1,7);
    PrintFile("..//Asset//MenuData.txt",70, 19);
    PrintFile("..//Asset//UbahData.txt",60,11);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);

    textBox2(80,24,20,2);
    gotoprinttext(81, 25, "     1-> Admin");
    textBox2(80,27,20,2);
    gotoprinttext(81, 28, "     2-> Kasir");
    textBox2(78,30,24,2);
    gotoprinttext(79, 31, " 3-> Petugas Kebersihan");

    // gotoprinttext(40, 16, "Masukkan pilihan role: ");
    // getnum(&role, 1); // Meminta input angka dari user gotoprinttext(80,38,"Ketik 0 untuk kembali");
    gotoprinttext(80,38,"Ketik 0 untuk kembali");
    gotoxy(80, 36);
    printf("Masukkan pilihan : ");
    getnum(&role, 1);


    // Validasi input
    if (role < 1 || role > 3) {
        blankScreen();        // Bersihkan layar
        MenuPetugas();          // Kembali ke menu utama
        return;
    }

    // Panggil fungsi untuk menampilkan data berdasarkan role
    ReadUpdatePetugasByRole(role);
}


void TextBoxUpdatePetugasByRole(char id_petugas[]) {
    petugas pgs;
    FILE *arspgs = fopen("../Database/Dat/PETUGAS.dat", "rb+"); // Dibuka dengan mode "rb+" untuk read & write
    if (arspgs == NULL) {
        MessageBox(NULL, "File PETUGAS.dat tidak dapat dibuka.", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        return;
    }

    int found = 0;
    while (fread(&pgs, sizeof(pgs), 1, arspgs) == 1) {
        if (strcmp(pgs.id_petugas_str, id_petugas) == 0) {
            found = 1;
            MessageBox(NULL, "ID PETUGAS Ditemukan!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            // Menampilkan data lama
            clearTengah();
            SetColorBlock(1, 7);
            frameDetailData(36, 17);
            seluruhpetugas();
            gotoxy(65, 22);
            printf("%s", pgs.id_petugas_str);
            gotoxy(65, 24);
            printf("%s", pgs.nama);
            gotoxy(65, 28);
            printf("%s", pgs.no_telp);
            gotoxy(65, 30);
            printf("%s", pgs.status);
            gotoxy(65, 32);
            printf("%s", pgs.username);
            gotoxy(65, 34);
            printf("%s", pgs.password);

            // Menampilkan menu update
            clearArea(132, 18, 38, 24);
            SetColorBlock(7, 9);
            gotoprinttext(141, 20, "U P D A T E  D A T A");
            gotoprinttext(134, 24, "[1] Nama");
            gotoprinttext(135, 24, "[2] Tanggal Lahir");
            gotoprinttext(134, 26, "[3] No Telp");
            gotoprinttext(134, 28, "[4] Status");
            gotoprinttext(134, 30, "[5] Username");
            gotoprinttext(134, 32, "[6] Password");
            gotoprinttext(134, 34, "Masukkan Pilihan: ");
            gotoxy(153, 34);


            int pilihan;
            scanf("%d", &pilihan);

            switch (pilihan) {
                case 1:
                    gotoprinttext(134, 36, "Masukkan Nama Baru : ");
                    gotoxy(154, 36);
                    scanf(" %[^\n]s", pgs.nama);
                    break;
                case 2:
                    gotoprinttext(134, 36, "Masukkan No Telp Baru: ");
                    gotoxy(160, 36);
                    scanf(" %[^\n]s", pgs.no_telp);
                    break;
                case 3:
                    gotoprinttext(134, 36, "Masukkan Status Baru: ");
                    gotoxy(160, 36);
                    scanf(" %[^\n]s", pgs.status);
                    break;
                case 4:
                    gotoprinttext(134, 36, "Masukkan Username Baru: ");
                    gotoxy(160, 36);
                    scanf(" %[^\n]s", pgs.username);
                    break;
                case 5:
                    gotoprinttext(134, 36, "Masukkan Password Baru: ");
                    gotoxy(160, 36);
                    scanf(" %[^\n]s", pgs.password);
                    break;
                default:
                    MessageBox(NULL, "Pilihan tidak valid!", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                    fclose(arspgs);
                    return;
            }

            fseek(arspgs, -sizeof(pgs), SEEK_CUR);
            fwrite(&pgs, sizeof(pgs), 1, arspgs);
            fflush(arspgs);

            MessageBox(NULL, "Data berhasil diperbarui.", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            break;
        }
    }

    fclose(arspgs);
    char ulangi;  // Variabel untuk menyimpan input user

    do {
        SetColorBlock(7, 9);
        textBox2(133, 39, 35, 2); // Textbox untuk konfirmasi
        gotoprinttext(135, 40, "Ubah data lagi? (y/t): ");
        gotoxy(157, 40);

        scanf(" %c", &ulangi); // Ambil input karakter (dengan spasi agar menghindari newline issue)

        // **Cek pilihan user**
        if (ulangi == 'y' || ulangi == 'Y') {
            blankScreen();
            ReadUpdatePetugasByRole(id_petugas); // Panggil ulang fungsi untuk update baru
            return;
        } else if (ulangi == 't' || ulangi == 'T') {
            blankScreen();
            MenuPetugas(); // Kembali ke menu utama
            return;
        } else {
            MessageBox(NULL, "Input tidak valid, masukkan y atau t.", "ERROR!", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 't' && ulangi != 'T');


    if (!found) {
        MessageBox(NULL, "ID Petugas tidak ditemukan.", "NOT FOUND", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    }
}

